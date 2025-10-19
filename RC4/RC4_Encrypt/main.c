#include <stdio.h>
#include <string.h>
#include "rc4.h"

int main(void){
    const char *key = "HUST2025";
    const char *plaintext = "Hanoi University of Science and Technology";

    unsigned char ciphertext[512];
    RC4State st;
    rc4_init(&st, (const unsigned char*)key, strlen(key));
    rc4_crypt(&st, (const unsigned char*)plaintext, ciphertext, strlen(plaintext));

    printf("Key: %s\n", key);
    printf("Plaintext: %s\n", plaintext);
    printf("Cipher (hex): ");
    for (size_t i = 0; i < strlen(plaintext); ++i) printf("%02X ", ciphertext[i]);
    printf("\n");
    return 0;
}
