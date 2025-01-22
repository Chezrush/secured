/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** hash
*/

#include <stdint.h>
#include "my.h"
#include "secured.h"
#include "sha_256.h"

int hash(char *key, int len)
{
    const char *message = key;
    uint8_t hash[32];
    SHA256_CTX_t ctx = {};

    (void)len;
    sha256_init(&ctx);
    sha256_update(&ctx, (uint8_t *)message, my_strlen(message));
    sha256_final(&ctx, hash);
    return convert_chunk(hash);
}
