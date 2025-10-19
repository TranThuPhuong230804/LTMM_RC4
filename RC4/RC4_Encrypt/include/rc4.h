#ifndef RC4_H
#define RC4_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RC4_STATE_SIZE 256

typedef struct {
    uint8_t S[RC4_STATE_SIZE];
    uint8_t i, j;
} RC4State;

void rc4_init(RC4State *state, const uint8_t *key, size_t keylen);
void rc4_crypt(RC4State *state, const uint8_t *in, uint8_t *out, size_t len);

#ifdef __cplusplus
}
#endif

#endif
