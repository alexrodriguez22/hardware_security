#ifndef TI_AES
#define TI_AES

void aes_encrypt(unsigned char *input, unsigned int inputLen, unsigned char *output, unsigned char *key);
void aes_decrypt(unsigned char *input, unsigned int inputLen, unsigned char *output, unsigned char *key);

#endif // TI_AES

