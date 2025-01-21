/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** update_sha_hash
*/

#include "sha_256.h"

void sha256_update(SHA256_CTX_t *ctx, const uint8_t data[], size_t len)
{
    for (size_t i = 0; i < len; ++i) {
        ++ctx->datalen;
        ctx->data[ctx->datalen] = data[i];
        if (ctx->datalen == 64) {
            sha256_transform(ctx, ctx->data);
            ctx->bitlen += 512;
            ctx->datalen = 0;
        }
    }
}
