#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TI_aes.h"

int main(int argc, char *argv[]) {
    const unsigned char ikey[] = {0xa1, 0xa2, 0xa3, 0xb4, 0xa5, 0xa6, 0xa7, 0xa8, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8};
    unsigned char msg[] = "gainesvillelkjhlkjhkjlhlkjhlkjhl;lkaj;lkasdjf;lkasjd;lkfjkl;s;kjhlkhlklkhjklhljkhlkjh";
    unsigned int msgLen = strlen((char *)msg);
    unsigned char encryptedData[256]; // Make sure this is large enough
    unsigned char decryptedData[256]; // Make sure this is large enough
    unsigned int j;

    printf("Plain Text Before Encryption TXT  : '%s'\n", msg);

    aes_encrypt(msg, msgLen, encryptedData, ikey);

    printf("\nCipher Text After Encryption HEX  : ");
    for (j = 0; j < msgLen; j++) {
        printf("0x%x ", encryptedData[j]);
    }

    unsigned int encryptedDataLen = msgLen + (16 - (msgLen % 16)); // Adjust for padding
    aes_decrypt(encryptedData, encryptedDataLen, decryptedData, ikey);

    printf("\n\nPlain Text After Decryption       : '%s'\n", decryptedData);
    printf("Plain Text After Decryption HEX   : ");
    for (j = 0; j < encryptedDataLen; j++) {
        printf("0x%x ", decryptedData[j]);
    }

    printf("\n");

    return 0;
}

