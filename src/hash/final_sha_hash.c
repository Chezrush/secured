/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** final_sha_hash
*/

#include "sha_256.h"

void sha256_final(SHA256_CTX_t *ctx, uint8_t hash[])
{
    ctx->bitlen += ctx->datalen * 8;
    ++ctx->datalen;
    ctx->data[ctx->datalen] = 0x80;
    if (ctx->datalen > 56) {
        while (ctx->datalen < 64) {
            ++ctx->datalen;
            ctx->data[ctx->datalen] = 0x00;
        }
        sha256_transform(ctx, ctx->data);
        ctx->datalen = 0;
    }
    sha256_final2(ctx);
    sha256_transform(ctx, ctx->data);
    for (int i = 0; i < 8; ++i) {
        hash[i * 4] = (ctx->H[i] >> 24) & 0xFF;
        hash[i * 4 + 1] = (ctx->H[i] >> 16) & 0xFF;
        hash[i * 4 + 2] = (ctx->H[i] >> 8) & 0xFF;
        hash[i * 4 + 3] = ctx->H[i] & 0xFF;
    }
}

void sha256_final2(SHA256_CTX_t *ctx)
{
    while (ctx->datalen < 56) {
        ++ctx->datalen;
        ctx->data[ctx->datalen] = 0x00;
    }
    for (int i = 7; i >= 0; --i)
        ctx->data[63 - i] = (ctx->bitlen >> (i * 8)) & 0xFF;
}
