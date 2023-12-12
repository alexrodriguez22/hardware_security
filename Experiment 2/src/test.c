#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TI_aes.h"

int main(int argc, char *argv[]) {
	const unsigned char ikey[] = {0xa1, 0xa2, 0xa3, 0xb4, 0xa5, 0xa6, 0xa7, 0xa8, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8};
	unsigned char msg[] = "gainesvillekjhkjhlkjlkjnkjnkjnlklkmlkmn";
	char ci[32];
	char de[32];
	unsigned int j;

	printf("Plain Text Before Encryption TXT  : '%s'\n", msg);
	printf("Plain Text Before Encryption HEX  : ");
	for(j = 0;j< 16; j++) 
		printf("0x%x ",msg[j]);

	aes_encrypt(msg, ikey);

	memcpy(ci, msg, 16);
	ci[17] = '\0';

	printf("\nCipher Text After Encryption      : '%s'\n", ci);
	printf("Cipher Text After Encryption HEX  : ");
	for(j = 0;j< 16; j++) 
		printf("0x%x ",msg[j]);

	
	aes_decrypt(ci, ikey);
	ci[17] = '\0';
	printf("\nPlain Text After Decryption       : '%s'\n", ci);
	printf("Plain Text After Decryption HEX   : ");
	for(j = 0;j< 16; j++) 
		printf("0x%x ",ci[j]);

	printf("\n");

}
