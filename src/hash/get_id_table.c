/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** get_id_table
*/

#include <stdio.h>
#include "sha_256.h"

void *my_memcpy(void *dest, void *src, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        ((uint8_t *)dest)[i] = ((uint8_t *)src)[i];
    }
    return dest;
}

uint64_t convert_chunk(uint8_t *hash)
{
    uint64_t res = 0;
    uint64_t somme = 0;

    for (size_t i = 0; i < 4; ++i) {
        my_memcpy(&res, &hash[i * sizeof(uint64_t)], sizeof(uint64_t));
        somme += res;
    }
    printf("%lu\n", somme);
    return somme;
}
