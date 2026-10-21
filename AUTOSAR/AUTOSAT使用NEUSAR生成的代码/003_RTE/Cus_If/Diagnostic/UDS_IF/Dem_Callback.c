#include "Dem_Callback.h"

#ifdef VCU_Test_Code_LLH

uint8 DemDataElement_DID_0x0400[8] = {0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01};
uint8 DemDataElement_DID_0x0402[8] = {0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02};
uint8 DemDataElement_DID_0x0403[8] = {0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03};
uint8 DemDataElement_DID_0x0404[8] = {0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04};
uint8 DemDataElement_DID_0x0405[8] = {0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05};
uint8 DemDataElement_DID_0x0406[8] = {0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06};
uint8 DemDataElement_DID_0x0407[8] = {0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07};
uint8 DemDataElement_DID_0x0408[8] = {0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08};
uint8 DemDataElement_DID_0x0409[8] = {0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09};
uint8 DemDataElement_DID_0x040B[8] = {0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A};
uint8 DemDataElement_DID_0x040C[8] = {0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B};
uint8 DemDataElement_DID_0x040D[8] = {0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C};
uint8 DemDataElement_DID_0x04CF[8] = {0x0D,0x0D,0x0D,0x0D,0x0D,0x0D,0x0D,0x0D};
uint8 DemDataElement_DID_0x0505[8] = {0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E};
uint8 DemDataElement_DID_0x0525[8] = {0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F};
uint8 DemDataElement_DID_0x0526[8] = {0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10};
uint8 DemDataElement_DID_0x0527[8] = {0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11};
uint8 DemDataElement_DID_0x0528[8] = {0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12};
uint8 DemDataElement_DID_0x0529[8] = {0x13,0x13,0x13,0x13,0x13,0x13,0x13,0x13};
uint8 DemDataElement_DID_0x052B[8] = {0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14};
uint8 DemDataElement_DID_0x052D[8] = {0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15};
uint8 DemDataElement_DID_0x0530[8] = {0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16};
uint8 DemDataElement_DID_0x0531[8] = {0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17};
uint8 DemDataElement_DID_0x0532[8] = {0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18};
uint8 DemDataElement_DID_0x0533[8] = {0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19};
uint8 DemDataElement_DID_0x0534[8] = {0x1A,0x1A,0x1A,0x1A,0x1A,0x1A,0x1A,0x1A};
uint8 DemDataElement_DID_0x0535[8] = {0x1B,0x1B,0x1B,0x1B,0x1B,0x1B,0x1B,0x1B};
uint8 DemDataElement_DID_0x0536[8] = {0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C};
uint8 DemDataElement_DID_0x0538[8] = {0x1D,0x1D,0x1D,0x1D,0x1D,0x1D,0x1D,0x1D};
uint8 DemDataElement_DID_0x0539[8] = {0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E};
uint8 DemDataElement_DID_0x053B[8] = {0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F};
uint8 DemDataElement_DID_0x053C[8] = {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
uint8 DemDataElement_DID_0x0542[8] = {0x21,0x21,0x21,0x21,0x21,0x21,0x21,0x21};
uint8 DemDataElement_DID_0x0543[8] = {0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x22};
uint8 DemDataElement_DID_0x0544[8] = {0x23,0x23,0x23,0x23,0x23,0x23,0x23,0x23};
uint8 DemDataElement_DID_0x0545[8] = {0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24};
uint8 DemDataElement_DID_0x0547[8] = {0x25,0x25,0x25,0x25,0x25,0x25,0x25,0x25};
uint8 DemDataElement_DID_0x055A[8] = {0x26,0x26,0x26,0x26,0x26,0x26,0x26,0x26};
uint8 DemDataElement_DID_0x055C[8] = {0x27,0x27,0x27,0x27,0x27,0x27,0x27,0x27};
uint8 DemDataElement_DID_0x0585[8] = {0x28,0x28,0x28,0x28,0x28,0x28,0x28,0x28};
uint8 DemDataElement_DID_0x0586[8] = {0x29,0x29,0x29,0x29,0x29,0x29,0x29,0x29};
uint8 DemDataElement_DID_0x0587[8] = {0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A};
uint8 DemDataElement_DID_0x0588[8] = {0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B};
uint8 DemDataElement_DID_0x0589[8] = {0x2C,0x2C,0x2C,0x2C,0x2C,0x2C,0x2C,0x2C};
uint8 DemDataElement_DID_0x058A[8] = {0x2D,0x2D,0x2D,0x2D,0x2D,0x2D,0x2D,0x2D};
uint8 DemDataElement_DID_0x058C[8] = {0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E};
uint8 DemDataElement_DID_0x058D[8] = {0x2F,0x2F,0x2F,0x2F,0x2F,0x2F,0x2F,0x2F};
uint8 DemDataElement_DID_0x058E[8] = {0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30};
uint8 DemDataElement_DID_0x058F[8] = {0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31};
uint8 DemDataElement_DID_0x0590[8] = {0x32,0x32,0x32,0x32,0x32,0x32,0x32,0x32};
uint8 DemDataElement_DID_0x0592[8] = {0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33};
uint8 DemDataElement_DID_0x0594[8] = {0x34,0x34,0x34,0x34,0x34,0x34,0x34,0x34};
uint8 DemDataElement_DID_0x0596[8] = {0x35,0x35,0x35,0x35,0x35,0x35,0x35,0x35};
uint8 DemDataElement_DID_0x0597[8] = {0x36,0x36,0x36,0x36,0x36,0x36,0x36,0x36};
uint8 DemDataElement_DID_0x0598[8] = {0x37,0x37,0x37,0x37,0x37,0x37,0x37,0x37};
uint8 DemDataElement_DID_0x0599[8] = {0x38,0x38,0x38,0x38,0x38,0x38,0x38,0x38};
uint8 DemDataElement_DID_0x059A[8] = {0x39,0x39,0x39,0x39,0x39,0x39,0x39,0x39};
uint8 DemDataElement_DID_0x059B[8] = {0x3A,0x3A,0x3A,0x3A,0x3A,0x3A,0x3A,0x3A};
uint8 DemDataElement_DID_0x059C[8] = {0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B};
uint8 DemDataElement_DID_0x059D[8] = {0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C};
uint8 DemDataElement_DID_0x059E[8] = {0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D};
uint8 DemDataElement_DID_0x059F[8] = {0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E};
uint8 DemDataElement_DID_0x05A1[8] = {0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F};
uint8 DemDataElement_DID_0x05AA[8] = {0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40};
uint8 DemDataElement_DID_0x05AB[8] = {0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41};
uint8 DemDataElement_DID_0x05B3[8] = {0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42};
uint8 DemDataElement_DID_0x05B4[8] = {0x43,0x43,0x43,0x43,0x43,0x43,0x43,0x43};
uint8 DemDataElement_DID_0x05B5[8] = {0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44};
uint8 DemDataElement_DID_0x05B6[8] = {0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45};
uint8 DemDataElement_DID_0x05B9[8] = {0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46};
uint8 DemDataElement_DID_0x05BA[8] = {0x47,0x47,0x47,0x47,0x47,0x47,0x47,0x47};
uint8 DemDataElement_DID_0x05BB[8] = {0x48,0x48,0x48,0x48,0x48,0x48,0x48,0x48};
uint8 DemDataElement_DID_0x05BC[8] = {0x49,0x49,0x49,0x49,0x49,0x49,0x49,0x49};
uint8 DemDataElement_DID_0x05BD[8] = {0x4A,0x4A,0x4A,0x4A,0x4A,0x4A,0x4A,0x4A};
uint8 DemDataElement_DID_0x05BE[8] = {0x4B,0x4B,0x4B,0x4B,0x4B,0x4B,0x4B,0x4B};
uint8 DemDataElement_DID_0x05C0[8] = {0x4C,0x4C,0x4C,0x4C,0x4C,0x4C,0x4C,0x4C};
uint8 DemDataElement_DID_0x05C1[8] = {0x4D,0x4D,0x4D,0x4D,0x4D,0x4D,0x4D,0x4D};
uint8 DemDataElement_DID_0x05C2[8] = {0x4E,0x4E,0x4E,0x4E,0x4E,0x4E,0x4E,0x4E};
uint8 DemDataElement_DID_0x05C3[8] = {0x4F,0x4F,0x4F,0x4F,0x4F,0x4F,0x4F,0x4F};
uint8 DemDataElement_DID_0x05C4[8] = {0x50,0x50,0x50,0x50,0x50,0x50,0x50,0x50};
uint8 DemDataElement_DID_0x05C5[8] = {0x51,0x51,0x51,0x51,0x51,0x51,0x51,0x51};
uint8 DemDataElement_DID_0x05C6[8] = {0x52,0x52,0x52,0x52,0x52,0x52,0x52,0x52};
uint8 DemDataElement_DID_0x05C7[8] = {0x53,0x53,0x53,0x53,0x53,0x53,0x53,0x53};
uint8 DemDataElement_DID_0x05C8[8] = {0x54,0x54,0x54,0x54,0x54,0x54,0x54,0x54};
uint8 DemDataElement_DID_0x05C9[8] = {0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55};
uint8 DemDataElement_DID_0x05CA[8] = {0x56,0x56,0x56,0x56,0x56,0x56,0x56,0x56};
uint8 DemDataElement_DID_0x05CB[8] = {0x57,0x57,0x57,0x57,0x57,0x57,0x57,0x57};
uint8 DemDataElement_DID_0x05CC[8] = {0x58,0x58,0x58,0x58,0x58,0x58,0x58,0x58};
uint8 DemDataElement_DID_0x05CD[8] = {0x59,0x59,0x59,0x59,0x59,0x59,0x59,0x59};
uint8 DemDataElement_DID_0x05CE[8] = {0x5A,0x5A,0x5A,0x5A,0x5A,0x5A,0x5A,0x5A};
uint8 DemDataElement_DID_0x05CF[8] = {0x5B,0x5B,0x5B,0x5B,0x5B,0x5B,0x5B,0x5B};
uint8 DemDataElement_DID_0x05D0[8] = {0x5C,0x5C,0x5C,0x5C,0x5C,0x5C,0x5C,0x5C};
uint8 DemDataElement_DID_0x05D1[8] = {0x5D,0x5D,0x5D,0x5D,0x5D,0x5D,0x5D,0x5D};
uint8 DemDataElement_DID_0x05D2[8] = {0x5E,0x5E,0x5E,0x5E,0x5E,0x5E,0x5E,0x5E};
uint8 DemDataElement_DID_0x05D3[8] = {0x5F,0x5F,0x5F,0x5F,0x5F,0x5F,0x5F,0x5F};
uint8 DemDataElement_DID_0x05D4[8] = {0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60};
uint8 DemDataElement_DID_0xCF00[8] = {0x61,0x61,0x61,0x61,0x61,0x61,0x61,0x61};
uint8 DemDataElement_DID_0xCF05[8] = {0x62,0x62,0x62,0x62,0x62,0x62,0x62,0x62};
uint8 DemDataElement_DID_0xCF06[8] = {0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63};
uint8 DemDataElement_DID_0xCF07[8] = {0x64,0x64,0x64,0x64,0x64,0x64,0x64,0x64};
uint8 DemDataElement_DID_0xDD00[8] = {0x65,0x65,0x65,0x65,0x65,0x65,0x65,0x65};
uint8 DemDataElement_DID_0xDF00[8] = {0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66};
uint8 DemDataElement_DID_0xDF01[8] = {0x67,0x67,0x67,0x67,0x67,0x67,0x67,0x67};
uint8 DemDataElement_DID_0xDF02[8] = {0x68,0x68,0x68,0x68,0x68,0x68,0x68,0x68};
uint8 DemDataElement_DID_0xDF03[8] = {0x69,0x69,0x69,0x69,0x69,0x69,0x69,0x69};
uint8 DemDataElement_DID_0xDF04[8] = {0x6A,0x6A,0x6A,0x6A,0x6A,0x6A,0x6A,0x6A};
uint8 DemDataElement_DID_0xDF06[8] = {0x6B,0x6B,0x6B,0x6B,0x6B,0x6B,0x6B,0x6B};
uint8 DemDataElement_DID_0xDF09[8] = {0x6C,0x6C,0x6C,0x6C,0x6C,0x6C,0x6C,0x6C};
uint8 DemDataElement_DID_0xDF0A[8] = {0x6D,0x6D,0x6D,0x6D,0x6D,0x6D,0x6D,0x6D};
uint8 DemDataElement_DID_0xDF0B[8] = {0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E};
uint8 DemDataElement_DID_0xDF0C[8] = {0x6F,0x6F,0x6F,0x6F,0x6F,0x6F,0x6F,0x6F};
uint8 DemDataElement_DID_0xDF0D[8] = {0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x70};
uint8 DemDataElement_DID_0xDF0E[8] = {0x71,0x71,0x71,0x71,0x71,0x71,0x71,0x71};

#endif//#ifdef VCU_Test_Code_LLH

uint8 Dem_DataServices_ElementClass_DID_0x0400(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0400[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0402(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0402[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0403(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0403[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0404(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0404[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0405(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0405[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0406(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0406[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0407(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0407[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0408(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0408[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0409(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0409[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x040B(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x040B[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x040C(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x040C[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x040D(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x040D[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x04CF(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x04CF[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0505(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0505[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0525(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0525[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0526(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0526[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0527(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0527[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0528(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0528[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0529(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0529[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x052B(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x052B[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x052D(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x052D[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0530(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0530[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0531(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0531[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0532(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0532[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0533(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0533[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0534(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0534[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0535(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0535[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0536(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0536[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0538(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0538[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0539(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0539[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x053B(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x053B[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x053C(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x053C[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0542(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0542[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0543(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0543[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0544(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0544[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0545(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0545[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0547(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0547[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x055A(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x055A[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x055C(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x055C[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0585(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0585[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0586(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0586[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0587(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0587[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0588(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0588[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0589(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0589[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x058A(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x058A[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x058C(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x058C[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x058D(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x058D[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x058E(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x058E[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x058F(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x058F[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0590(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0590[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0592(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0592[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0594(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0594[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0596(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0596[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0597(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0597[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0598(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0598[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x0599(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x0599[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x059A(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x059A[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x059B(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x059B[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x059C(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x059C[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x059D(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x059D[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x059E(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x059E[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x059F(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x059F[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05A1(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05A1[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05AA(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05AA[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05AB(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05AB[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05B3(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05B3[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05B4(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05B4[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05B5(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05B5[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05B6(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05B6[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05B9(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05B9[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05BA(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05BA[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05BB(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05BB[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05BC(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05BC[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05BD(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05BD[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05BE(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05BE[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05C0(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05C0[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05C1(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05C1[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05C2(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05C2[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05C3(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05C3[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05C4(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05C4[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05C5(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05C5[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05C6(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05C6[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05C7(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05C7[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05C8(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05C8[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05C9(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05C9[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05CA(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05CA[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05CB(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05CB[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05CC(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05CC[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05CD(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05CD[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05CE(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05CE[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05CF(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05CF[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05D0(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05D0[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05D1(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05D1[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05D2(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05D2[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05D3(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05D3[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0x05D4(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0x05D4[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0xCF00(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0xCF00[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0xCF05(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0xCF05[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0xCF06(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0xCF06[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0xCF07(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0xCF07[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0xDD00(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0xDD00[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0xDF00(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0xDF00[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0xDF01(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0xDF01[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0xDF02(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0xDF02[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0xDF03(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0xDF03[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0xDF04(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0xDF04[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0xDF06(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0xDF06[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0xDF09(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0xDF09[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0xDF0A(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0xDF0A[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0xDF0B(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0xDF0B[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0xDF0C(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0xDF0C[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0xDF0D(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0xDF0D[0];
#endif
    return 0U;
}

uint8 Dem_DataServices_ElementClass_DID_0xDF0E(uint8 *DataBufPtr)
{
#ifdef VCU_Test_Code_LLH
    DataBufPtr[0] = DemDataElement_DID_0xDF0E[0];
#endif
    return 0U;
}
