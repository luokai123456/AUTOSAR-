#ifndef AES_ENCYPT_H_
#define AES_ENCYPT_H_

/*----------------------------------------------*
 * Algorithm from customer                 *
 *----------------------------------------------*/
extern void AES_InitKey( unsigned char* pucKey  );
extern unsigned char  AES_Encrypt(unsigned char* input);
// extern unsigned char AES_Cal();
unsigned char* AES_Decrypt(unsigned char* input);
void AES_ExpandKey( unsigned char* key, unsigned char w[][4][4] );
unsigned char AES_FFmul(unsigned char a, unsigned char b);
void AES_SubBytes(unsigned char state[][4]);
void AES_ShiftRows(unsigned char state[][4]);
void AES_MixColumns(unsigned char state[][4]);
void AES_AddRoundKey(unsigned char state[][4], unsigned char k[][4]);
void AES_InvSubBytes(unsigned char state[][4]);
void AES_InvShiftRows(unsigned char state[][4]);
void AES_InvMixColumns(unsigned char state[][4]);
#endif

