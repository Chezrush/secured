/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** hash_key
*/

#include "sha_256.h"

void sha256_transform(SHA256_CTX_t *ctx, const uint8_t data[])
{
    uint32_t W[64];
    uint32_t list[SHA_TRANS_SIZE] = {0};

    sha256_transform_2(W, data, list, ctx);
    sha256_transform_3(list, W);
    for (int i = 0; i <= SHA_TRANS_H; ++i)
        ctx->H[i] += list[i];
}

void sha256_transform_2(uint32_t W[64], const uint8_t *data,
    uint32_t list[10], SHA256_CTX_t *ctx)
{
    for (int i = 0; i < 16; ++i)
        W[i] = (data[i * 4] << 24) | (data[i * 4 + 1] << 16) |
        (data[i * 4 + 2] << 8) | (data[i * 4 + 3]);
    for (int i = 16; i < 64; ++i)
        W[i] = SIGMA11(W[i - 2]) + W[i - 7] + SIGMA00(W[i - 15]) + W[i - 16];
    for (int i = 0; i <= SHA_TRANS_H; ++i)
        list[i] = ctx->H[i];
}

void sha256_transform_3(uint32_t list[10], uint32_t W[64])
{
    for (int i = 0; i < 64; ++i) {
        list[SHA_TRANS_T1] = list[SHA_TRANS_H] + SIGMA1(list[SHA_TRANS_E])
        + CH(list[SHA_TRANS_E], list[SHA_TRANS_F], list[SHA_TRANS_G])
        + SHA_K[i] + W[i];
        list[SHA_TRANS_T2] = SIGMA0(list[SHA_TRANS_A])
        + MAJ(list[SHA_TRANS_A], list[SHA_TRANS_B], list[SHA_TRANS_C]);
        list[SHA_TRANS_H] = list[SHA_TRANS_G];
        list[SHA_TRANS_G] = list[SHA_TRANS_F];
        list[SHA_TRANS_F] = list[SHA_TRANS_E];
        list[SHA_TRANS_E] = list[SHA_TRANS_D] + list[SHA_TRANS_T1];
        list[SHA_TRANS_D] = list[SHA_TRANS_C];
        list[SHA_TRANS_C] = list[SHA_TRANS_B];
        list[SHA_TRANS_B] = list[SHA_TRANS_A];
        list[SHA_TRANS_A] = list[SHA_TRANS_T1] + list[SHA_TRANS_T2];
    }
}
