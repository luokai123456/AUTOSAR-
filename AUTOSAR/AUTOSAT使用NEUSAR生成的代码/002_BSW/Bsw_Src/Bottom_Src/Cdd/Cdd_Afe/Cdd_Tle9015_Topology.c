#include "Cdd_Tle9015_Topology.h"
#include "CCFC3012PT.h"
#include "SchM_Fls.h"



#define TLE9018_TOPO_EN_WAKEUP_PULSE_UART0_ONE  0
#define TLE9018_TOPO_EN_SET_CHIP_ID_UART0_ONE   1
#define TLE9018_TOPO_EN_READ_CHIP_ID_UART0_ONE  2
#define TLE9018_TOPO_EN_WAKEUP_PULSE_UART1_ONE  3
#define TLE9018_TOPO_EN_SET_CHIP_ID_UART1_ONE   4
#define TLE9018_TOPO_EN_READ_CHIP_ID_UART1_ONE  5
#define TLE9018_TOPO_EN_REST_CHIP               6
#define TLE9018_TOPO_EN_WAKEUP_PULSE_TWO        7
#define TLE9018_TOPO_EN_SET_CHIP_ID_TWO         8
#define TLE9018_TOPO_EN_READ_CHIP_ID_TWO        9



/**
 * @brief AFE的延迟函数
 * @param counter 计数值
 */
__attribute__((ghs_optimize(Onone))) void Tle9015_DelayFunction(uint32 counter)
{
    volatile uint32 i = counter;

    while(i > 0) {
        i--;
    }
}

void Tle9015_SendWakeUpPulse(uint8 index)
{
    uint16 mux;
    uint8 port;
    volatile uint8 i;

    mux = (0 == index) ? 0x059C : 0x0B9C;
    port = (0 == index) ? 112 : 127;

SchM_Enter_Fls_EXCLUSIVE_AREA_64();
    SIUL.PCR[port].R = 0x9C;
    for(i = 0;i < 14;i++) {
        SIUL.GPDO[port].R = 1;
        Tle9015_DelayFunction(1500);
        SIUL.GPDO[port].R = 0;
        Tle9015_DelayFunction(1500);
    }
    SIUL.GPDO[port].R = 1;
    SIUL.PCR[port].R = mux;
    SIUL.GPDO[port].R = 0 ;
SchM_Exit_Fls_EXCLUSIVE_AREA_64();
    Tle9015_DelayFunction(5000);
}

static uint8 Tle9015_CheckRingComplete(Tle9015_SegmentType* segments)
{
    uint8 i;

    if(segments[0].dev_count != segments[1].dev_count) {
        return 0;
    }

    if(segments[0].dev_count != TLE9018_CHIP_NUMBER) {
        return 0;
    }

    for(i = 0;i < TLE9018_CHIP_NUMBER;i++) {
        if(segments[0].dev_list[i] != segments[1].dev_list[i]) {
            return 0;
        }
    }

    return 1;
}

static uint8 Tle9015_GenerateSegInfo(uint8* up_list,
    uint8 up_cnt,
    uint8* down_list,
    uint8 down_cnt,
    Tle9015_SegmentType* segments
)
{
    uint8 ret = 0;
    uint8 i;

    if(!up_list || !down_list || !segments) return 1;

    if((up_cnt == TLE9018_CHIP_NUMBER) &&\
        (down_cnt == 0)) {
        segments[0].dev_count = up_cnt;
        for(i = 0;i < TLE9018_CHIP_NUMBER;i++)
        {
            segments[1].dev_list[i] = 0;
            segments[0].dev_list[i] = up_list[i];
        }
            
    }else if((up_cnt == 0) &&\
        (down_cnt == TLE9018_CHIP_NUMBER)) {
        segments[0].dev_count = 0;
        segments[1].dev_count = down_cnt;
        for(i = 0;i < TLE9018_CHIP_NUMBER;i++)
        {
            segments[0].dev_list[i] = 0;
            segments[1].dev_list[i] = down_list[i];
        }
    }else if(TLE9018_CHIP_NUMBER == (up_cnt + down_cnt)) {
        segments[0].dev_count = up_cnt;
        segments[1].dev_count = down_cnt;
        for(i = 0;i < TLE9018_CHIP_NUMBER;i++) {
            segments[0].dev_list[i] = up_list[i];
            segments[1].dev_list[i] = down_list[i];
        }
    }else {
        ret = 1;
    }

    return ret;
}

static uint8 Tle9015_EnumDevices(Tle9018_DevType* dev, uint8 index, uint8 seg_dev_cnt)
{
    uint8 ret = 0;
    uint8 i;
    uint8 is_last;
    Tle9015_SendWakeUpPulse(index);
    Tle9015_DelayFunction(150000);
    Tle9015_SendWakeUpPulse(index);
    Tle9015_DelayFunction(150000);

    for(i = 0;i < seg_dev_cnt;i++) {
        Tle9015_SendWakeUpPulse(index);
        is_last = ((i + 1) == seg_dev_cnt);
        if(Tle9018_SetDeviceId(dev, index, (i + 1), is_last)) {
            ret = 1;
            break;
        }
        Tle9015_DelayFunction(5000);
    }

    return ret;
}

__attribute__((ghs_optimize(Onone))) static void Tle9015_ScanPort(Tle9018_DevType* dev, Tle9015_SegmentType* segments)
{
    uint8 really_dev_id[2];
    uint8 dev_id;
    uint8 ret;
    uint8 i;

    for(dev_id = 0;dev_id < TLE9018_CHIP_NUMBER;dev_id++) {
        ret = Tle9018_ReadDualDevId(dev, 0, (dev_id + 1), really_dev_id);
        if(ret ||\
            really_dev_id[0] != (dev_id + 1) ||\
            really_dev_id[1] != (dev_id + 1)) {
            break;
        }

        for(i = 0;i < 2;i++) {
            if(really_dev_id[i])
                segments[i].dev_count++;

            segments[i].dev_list[dev_id] = really_dev_id[i];
        }
    }
}

static void Tle9015_ScanSinglePort(Tle9018_DevType* dev, uint8 port, Tle9015_SegmentType* segments)
{
    uint8 really_dev_id;
    uint8 dev_id;
    uint8 ret;

    for(dev_id = 0;dev_id < TLE9018_CHIP_NUMBER;dev_id++) {
        really_dev_id = (dev_id + 1);
        ret = Tle9018_ReadDevId(dev, port, &really_dev_id);
        if(ret || (really_dev_id != (dev_id + 1))) {
            break;
        }
        
        segments[port].dev_count++;
        segments[port].dev_list[dev_id] = really_dev_id;
    }
}

static void Tle9015_AssignLogicalAddr(
    Tle9015_SegmentType* segments,
    uint8 seg_cnt,
    Tle9015_LinkStateType* link_state
)
{
    uint8 seg0_cnt = segments[0].dev_count;
    uint8 seg1_cnt = segments[1].dev_count;
    uint8 total_dev = seg0_cnt + seg1_cnt;
    uint8 logic_addr;
    uint8 dev_idx;
    uint8 phy_id;

    memset(link_state->logical_to_physical, 0xFF, sizeof(link_state->logical_to_physical));
    memset(link_state->logic_to_port, 0xFF, sizeof(link_state->logic_to_port));

    link_state->segment_count = seg_cnt;
    link_state->total_devices = total_dev;

    if (seg0_cnt > 0)
    {
        logic_addr = 1;
        for (dev_idx = 0; dev_idx < seg0_cnt; dev_idx++)
        {
            phy_id = segments[0].dev_list[dev_idx];
            
            link_state->logical_to_physical[logic_addr] = phy_id;
            link_state->logic_to_port[logic_addr] = 0;

            logic_addr++;
        }
    }

    if (seg1_cnt > 0)
    {
        logic_addr = total_dev;
        for (dev_idx = 0; dev_idx < seg1_cnt; dev_idx++)
        {
            phy_id = segments[1].dev_list[dev_idx];
            
            link_state->logical_to_physical[logic_addr] = phy_id;
            link_state->logic_to_port[logic_addr] = 1;

            logic_addr--;
        }
    }
}

uint8 Tle9015_Topology_AutoInit(Tle9018_DevType* dev)
{
    Tle9015_SegmentType segments[2] = {0};
    uint8 seg_cnt = 0;
    uint8 ret = 0;
    uint8 i;
    uint8 seg0_cnt;
    uint8 seg1_cnt;

    ret = Tle9015_EnumDevices(dev, 0, TLE9018_CHIP_NUMBER);
    if(!ret) {
        memset(segments, 0, sizeof(segments));
        Tle9015_ScanPort(dev, segments);
    }
    ret = Tle9015_CheckRingComplete(segments);
    if(ret) {
        for(i = TLE9018_CHIP_NUMBER;i >= 1;i--)
            Tle9018_ResetFromSleep(dev, 0, i);
        Tle9015_DelayFunction(15000);

        Tle9015_EnumDevices(dev, 0, TLE9018_CHIP_NUMBER);
        memset(segments, 0, sizeof(segments));
        Tle9015_DelayFunction(75000);
        Tle9015_ScanPort(dev, segments);

        dev->link_state.segments[0] = segments[0];
        memset((void*)&segments[1], 0, sizeof(segments[1]));

        Tle9015_AssignLogicalAddr(segments, 1, &dev->link_state);
    }else {
        memset(segments, 0, sizeof(segments));
        Tle9015_ScanSinglePort(dev, 0, segments);

        if(segments[0].dev_count < TLE9018_CHIP_NUMBER) {
            Tle9015_EnumDevices(dev, 1, TLE9018_CHIP_NUMBER);
            Tle9015_ScanSinglePort(dev, 1, segments);

            if(TLE9018_CHIP_NUMBER == segments[1].dev_count) {
                for(i = TLE9018_CHIP_NUMBER;i >= 1;i--)
                    Tle9018_ResetFromSleep(dev, 1, i);
                Tle9015_DelayFunction(15000);

                Tle9015_EnumDevices(dev, 1, TLE9018_CHIP_NUMBER);
                memset(segments, 0, sizeof(segments));
                Tle9015_DelayFunction(75000);
                Tle9015_ScanSinglePort(dev, 1, segments);
            }else {
                seg0_cnt = segments[0].dev_count;
                seg1_cnt = segments[1].dev_count;
                for(i = seg0_cnt;i >= 1;i--)
                    Tle9018_ResetFromSleep(dev, 0, i);
                for(i = seg1_cnt;i >= 1;i--)
                    Tle9018_ResetFromSleep(dev, 1, i);
  
                Tle9015_DelayFunction(15000);

                memset(segments, 0, sizeof(segments));
                
                Tle9015_EnumDevices(dev, 0, seg0_cnt);
                Tle9015_ScanSinglePort(dev, 0, segments);
                Tle9015_EnumDevices(dev, 1, seg1_cnt);
                Tle9015_DelayFunction(75000);
                Tle9015_ScanSinglePort(dev, 1, segments);
            }
        }else {
            for(i = TLE9018_CHIP_NUMBER;i >= 1;i--)
            Tle9015_DelayFunction(15000);
            Tle9018_ResetFromSleep(dev, 0, i);

            Tle9015_EnumDevices(dev, 0, TLE9018_CHIP_NUMBER);
            memset(segments, 0, sizeof(segments));
            Tle9015_DelayFunction(75000);
            Tle9015_ScanSinglePort(dev, 0, segments);
        }

        ret = Tle9015_GenerateSegInfo(segments[0].dev_list,
            segments[0].dev_count,
            segments[1].dev_list,
            segments[1].dev_count,
            dev->link_state.segments
        );
        if(ret) {
            return ret;
        }

        if(segments[0].dev_count > 0) seg_cnt++;
        if(segments[1].dev_count > 0) seg_cnt++;
        Tle9015_AssignLogicalAddr(segments, seg_cnt, &dev->link_state);
    }

    return 0;
}

uint8 Tle9015_GetPhyId(Tle9018_DevType* dev, uint8 logic_addr)
{
    if (logic_addr < 1 || logic_addr > dev->link_state.total_devices)
        return 0xFF;
    return dev->link_state.logical_to_physical[logic_addr];
}

uint8 Tle9015_GetPort(Tle9018_DevType* dev, uint8 logic_addr)
{
    if (logic_addr < 1 || logic_addr > dev->link_state.total_devices)
        return 0xFF;
    return dev->link_state.logic_to_port[logic_addr];
}

uint8 Tle9015_GetTotalDevNum(Tle9018_DevType* dev)
{
    return dev->link_state.total_devices;
}

void Tle9015_RestErrAndnSleep(void)
{
        SIUL.GPDO[136].R = 1;

        SIUL.GPDO[135].R = 1;
        Tle9015_DelayFunction(2000);
        SIUL.GPDO[135].R = 0;
        Tle9015_DelayFunction(220000);
        SIUL.GPDO[135].R = 1;
        Tle9015_DelayFunction(2000);
        // SIUL.GPDO[135].R = 0;
}

uint8 valFlag_EnTopoligyInitStatus_Mp = TLE9018_TOPO_EN_WAKEUP_PULSE_UART0_ONE;

uint8 valFlag_EnTopoligyInitEnd_Mp = 0;
 extern uint8 Afe_valDev_nSleepFg_Mp;
 extern uint8 AFE_valDualInitState_Mp;
 extern uint32 sleep_Count;
 extern uint8  valFlag_LoseChip_Mp;
uint8 Tle9015_LineOffTopologyInit(Tle9018_DevType* dev)
{
    static Tle9015_SegmentType segments[2] = {0};
    uint8 seg_cnt = 0;
    uint8 ret = 0;
    uint8 i;
    uint8 seg0_cnt;
    uint8 seg1_cnt;
    uint8 is_last;

    switch(valFlag_EnTopoligyInitStatus_Mp){
        case TLE9018_TOPO_EN_WAKEUP_PULSE_UART0_ONE:
            Tle9015_SendWakeUpPulse(0);
            // Tle9015_DelayFunction(150000);
            // if(valFlag_LoseChip_Mp == 1)
            // {
            //     for(uint8 i = 1;i <= segments[0].dev_count;i++)
            //     {
            //         (void)Tle9018_WriteRegister(0, i, TLE9018_REG_OP_MODE, 0x0100);
            //     }
            // }
            Tle9015_DelayFunction(150000);
            Tle9015_SendWakeUpPulse(0);
            valFlag_EnTopoligyInitStatus_Mp = TLE9018_TOPO_EN_SET_CHIP_ID_UART0_ONE;
            break;

        case TLE9018_TOPO_EN_SET_CHIP_ID_UART0_ONE:
            for(i = 0;i < TLE9018_CHIP_NUMBER;i++) {
                Tle9015_SendWakeUpPulse(0);
                is_last = ((i + 1) == TLE9018_CHIP_NUMBER);
                Tle9018_SetDeviceId(dev, 0, (i + 1), is_last);
                Tle9015_DelayFunction(5000);
            }
            valFlag_EnTopoligyInitStatus_Mp = TLE9018_TOPO_EN_READ_CHIP_ID_UART0_ONE;
            break;

        case TLE9018_TOPO_EN_READ_CHIP_ID_UART0_ONE:
            memset(segments, 0, sizeof(segments));
            Tle9015_ScanSinglePort(dev, 0, segments);
            if(segments[0].dev_count < TLE9018_CHIP_NUMBER) 
            {
                valFlag_EnTopoligyInitStatus_Mp = TLE9018_TOPO_EN_WAKEUP_PULSE_UART1_ONE;
            }
            else
            {
                valFlag_EnTopoligyInitStatus_Mp = TLE9018_TOPO_EN_REST_CHIP;
            }
            break;

        case TLE9018_TOPO_EN_WAKEUP_PULSE_UART1_ONE:            
            Tle9015_SendWakeUpPulse(1);
            // Tle9015_DelayFunction(150000);
            // if(valFlag_LoseChip_Mp == 1)
            // {
            //     for(uint8 i = 1;i <= segments[0].dev_count;i++)
            //     {
            //         (void)Tle9018_WriteRegister(0, i, TLE9018_REG_OP_MODE, 0x0100);
            //     }
            // }
            Tle9015_DelayFunction(150000);
            Tle9015_SendWakeUpPulse(1);
            valFlag_EnTopoligyInitStatus_Mp = TLE9018_TOPO_EN_SET_CHIP_ID_UART1_ONE;
            break;

        case TLE9018_TOPO_EN_SET_CHIP_ID_UART1_ONE:
            for(i = 0;i < TLE9018_CHIP_NUMBER;i++) {
                Tle9015_SendWakeUpPulse(1);
                is_last = ((i + 1) == TLE9018_CHIP_NUMBER);
                if(Tle9018_SetDeviceId(dev, 1, (i + 1), is_last)) {
                    break;
                }
                Tle9015_DelayFunction(5000);
            }
            valFlag_EnTopoligyInitStatus_Mp = TLE9018_TOPO_EN_READ_CHIP_ID_UART1_ONE;
            break;
        
        case TLE9018_TOPO_EN_READ_CHIP_ID_UART1_ONE:
            Tle9015_ScanSinglePort(dev, 1, segments);

            valFlag_EnTopoligyInitStatus_Mp = TLE9018_TOPO_EN_REST_CHIP;
            break;
            
        case TLE9018_TOPO_EN_REST_CHIP:
            if(segments[0].dev_count + segments[1].dev_count < TLE9018_CHIP_NUMBER)
            {
                valFlag_EnTopoligyInitStatus_Mp = TLE9018_TOPO_EN_WAKEUP_PULSE_UART0_ONE;
                for(uint8 i = 1;i <= segments[0].dev_count;i++)
                {
                    (void)Tle9018_WriteRegister(0, i, TLE9018_REG_OP_MODE, 0x0001);
                }
                for(uint8 j = 1;j <= segments[1].dev_count;j++)
                {
                    (void)Tle9018_WriteRegister(1, j, TLE9018_REG_OP_MODE, 0x0001);
                }
                Afe_valDev_nSleepFg_Mp = 0;
                AFE_valDualInitState_Mp = 0;
                valFlag_LoseChip_Mp = 1;                
                sleep_Count = 0;
                break;
            }
            if(segments[0].dev_count < TLE9018_CHIP_NUMBER) 
            {
                if(segments[1].dev_count == TLE9018_CHIP_NUMBER)
                {
                    for(i = 8;i >= 1;i--)
                        Tle9018_ResetFromSleep(dev, 1, i);
                }
                else
                {
                    seg0_cnt = segments[0].dev_count;
                    seg1_cnt = segments[1].dev_count;
                    for(i = seg0_cnt;i >= 1;i--)
                        Tle9018_ResetFromSleep(dev, 0, i);
                    for(i = seg1_cnt;i >= 1;i--)
                        Tle9018_ResetFromSleep(dev, 1, i);
                }
            }
            else
            {
                for(i = 8;i >= 1;i--)
                    Tle9018_ResetFromSleep(dev, 0, i);
            }
            valFlag_EnTopoligyInitStatus_Mp = TLE9018_TOPO_EN_WAKEUP_PULSE_TWO;
            break;

        case TLE9018_TOPO_EN_WAKEUP_PULSE_TWO:
            if(segments[0].dev_count < TLE9018_CHIP_NUMBER) 
            {
                if(segments[1].dev_count == TLE9018_CHIP_NUMBER)
                {
                    Tle9015_SendWakeUpPulse(1);
                    Tle9015_DelayFunction(150000);
                    Tle9015_SendWakeUpPulse(1);
                }
                else
                {
                    Tle9015_SendWakeUpPulse(0);
                    Tle9015_SendWakeUpPulse(1);
                    Tle9015_DelayFunction(150000);
                    Tle9015_SendWakeUpPulse(0);
                    Tle9015_SendWakeUpPulse(1);
                }
            }
            else
            {
                Tle9015_SendWakeUpPulse(0);
                Tle9015_DelayFunction(150000);
                Tle9015_SendWakeUpPulse(0);
            }
            valFlag_EnTopoligyInitStatus_Mp = TLE9018_TOPO_EN_SET_CHIP_ID_TWO;
            break;

        case TLE9018_TOPO_EN_SET_CHIP_ID_TWO:
            if(segments[0].dev_count < TLE9018_CHIP_NUMBER) 
            {
                if(segments[1].dev_count == TLE9018_CHIP_NUMBER)
                {
                    for(i = 0;i < TLE9018_CHIP_NUMBER;i++) {
                        Tle9015_SendWakeUpPulse(1);
                        is_last = ((i + 1) == TLE9018_CHIP_NUMBER);
                        if(Tle9018_SetDeviceId(dev, 1, (i + 1), is_last)) {
                            break;
                        }
                        Tle9015_DelayFunction(5000);
                    }
                }
                else
                {
                    seg0_cnt = segments[0].dev_count;
                    seg1_cnt = segments[1].dev_count;
                    for(i = 0;i < seg0_cnt;i++) {
                        Tle9015_SendWakeUpPulse(0);
                        is_last = ((i + 1) == seg0_cnt);
                        if(Tle9018_SetDeviceId(dev, 0, (i + 1), is_last)) {
                            break;
                        }
                        Tle9015_DelayFunction(5000);
                    }
                    for(i = 0;i < seg1_cnt;i++) {
                        Tle9015_SendWakeUpPulse(1);
                        is_last = ((i + 1) == seg1_cnt);
                        if(Tle9018_SetDeviceId(dev, 1, (i + 1), is_last)) {
                            break;
                        }
                        Tle9015_DelayFunction(5000);
                    }
                }
            }
            else
            {
                for(i = 0;i < TLE9018_CHIP_NUMBER;i++) {
                    Tle9015_SendWakeUpPulse(0);
                    is_last = ((i + 1) == TLE9018_CHIP_NUMBER);
                    if(Tle9018_SetDeviceId(dev, 0, (i + 1), is_last)) {
                        break;
                    }
                    Tle9015_DelayFunction(5000);
                }
            }
            valFlag_EnTopoligyInitStatus_Mp = TLE9018_TOPO_EN_READ_CHIP_ID_TWO;
            break;

        case TLE9018_TOPO_EN_READ_CHIP_ID_TWO:
            if(segments[0].dev_count < TLE9018_CHIP_NUMBER) 
            {
                if(segments[1].dev_count == TLE9018_CHIP_NUMBER)
                {
                    memset(segments, 0, sizeof(segments));
                    Tle9015_ScanSinglePort(dev, 1, segments);
                }
                else
                { 
                    memset(segments, 0, sizeof(segments));
                    Tle9015_ScanSinglePort(dev, 0, segments);
                    Tle9015_ScanSinglePort(dev, 1, segments);
                }
            }
            else
            {
                memset(segments, 0, sizeof(segments));
                Tle9015_ScanSinglePort(dev, 0, segments);
            }
            ret = Tle9015_GenerateSegInfo(segments[0].dev_list,
            segments[0].dev_count,
            segments[1].dev_list,
            segments[1].dev_count,
            dev->link_state.segments
            );
            if(ret) {
                return ret;
            }

            if(segments[0].dev_count > 0) seg_cnt++;
            if(segments[1].dev_count > 0) seg_cnt++;
            Tle9015_AssignLogicalAddr(segments, seg_cnt, &dev->link_state);
            valFlag_EnTopoligyInitEnd_Mp = 1;
            break;

        default:
            break;
    }
}

uint8 Cdd_Afe_Tle9015_AbistChack(Tle9018_DevType* dev)
{
    uint8 ret = 0;
    volatile uint8 i = 0;
    Tle9015_SegmentType segments[2] = {0};

    ret = Tle9015_EnumDevices(dev, 1, TLE9018_CHIP_NUMBER);
    if(!ret) {
        memset(segments, 0, sizeof(segments));
        Tle9015_ScanSinglePort(dev, 1, segments);
    }
    if(segments[1].dev_count != TLE9018_CHIP_NUMBER) {
        ret = 1;
    }

        // (void)Tle9018_WriteRegister(1, i, TLE9018_REG_OP_MODE, 0x0100);
    (void)Tle9018_WriteRegister(1, 0x3F, TLE9018_REG_OP_MODE, 0x0001);


    SIUL.GPDO[136].R = 0;
    
    Tle9015_DelayFunction(200000);
    Tle9015_RestErrAndnSleep();
    Tle9015_SendWakeUpPulse(0);
    Tle9015_DelayFunction(50000);
    Tle9015_SendWakeUpPulse(0);
    return ret;
}
