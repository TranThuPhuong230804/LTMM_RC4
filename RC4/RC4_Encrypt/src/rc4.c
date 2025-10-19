#include "rc4.h"

static inline void rc4_swap(uint8_t *a, uint8_t *b){
    uint8_t t = *a; *a = *b; *b = t;
}

void rc4_init(RC4State *state, const uint8_t *key, size_t keylen){
    uint8_t *S = state->S;
    for (int i = 0; i < RC4_STATE_SIZE; ++i) S[i] = (uint8_t)i;

    uint8_t T[RC4_STATE_SIZE];
    for (int i = 0; i < RC4_STATE_SIZE; ++i) T[i] = key[i % keylen];

    uint8_t j = 0;
    for (int i = 0; i < RC4_STATE_SIZE; ++i){
        j = (uint8_t)((j + S[i] + T[i]) % RC4_STATE_SIZE);
        rc4_swap(&S[i], &S[j]);
    }
    state->i = 0;
    state->j = 0;
}

void rc4_crypt(RC4State *state, const uint8_t *in, uint8_t *out, size_t len){
    uint8_t *S = state->S;
    for (size_t n = 0; n < len; ++n){
        state->i = (uint8_t)((state->i + 1) % RC4_STATE_SIZE);
        state->j = (uint8_t)((state->j + S[state->i]) % RC4_STATE_SIZE);
        rc4_swap(&S[state->i], &S[state->j]);
        uint8_t t = (uint8_t)((S[state->i] + S[state->j]) % RC4_STATE_SIZE);
        uint8_t k = S[t];
        out[n] = in[n] ^ k;
    }
}
