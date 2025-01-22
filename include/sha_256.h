/*
** EPITECH PROJECT, 2025
** test_sha_256
** File description:
** sha_256
*/


#ifndef SHA_256_H
    #define SHA_256_H
    #define ROTR(x, n) ((x >> n) | (x << (32 - n)))
    #define SHR(x, n) (x >> n)
    #define CH(x, y, z) ((x & y) ^ (~x & z))
    #define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
    #define SIGMA0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
    #define SIGMA1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
    #define SIGMA00(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ SHR(x, 3))
    #define SIGMA11(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ SHR(x, 10))
    #include <stdint.h>
    #include <stddef.h>

typedef enum SHA_TRANS_s {
    SHA_TRANS_A = 0,
    SHA_TRANS_B,
    SHA_TRANS_C,
    SHA_TRANS_D,
    SHA_TRANS_E,
    SHA_TRANS_F,
    SHA_TRANS_G,
    SHA_TRANS_H,
    SHA_TRANS_T1,
    SHA_TRANS_T2,
    SHA_TRANS_SIZE
}SHA_TRANS_t;

static const uint32_t SHA_K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

typedef struct SHA256_CTX_s {
    uint32_t H[8];
    uint8_t data[64];
    uint64_t bitlen;
    uint32_t datalen;
} SHA256_CTX_t;

void sha256_final(SHA256_CTX_t *ctx, uint8_t hash[]);
unsigned int convert_chunk(uint8_t *hash);
void sha256_init(SHA256_CTX_t *ctx);
void sha256_transform(SHA256_CTX_t *ctx, const uint8_t data[]);
void sha256_transform_2(uint32_t W[64], const uint8_t *data,
    uint32_t list[10], SHA256_CTX_t *ctx);
void sha256_transform_3(uint32_t list[10], uint32_t W[64]);
void sha256_update(SHA256_CTX_t *ctx, const uint8_t data[], size_t len);
void sha256_final2(SHA256_CTX_t *ctx);

#endif /* SHA_256_H */
