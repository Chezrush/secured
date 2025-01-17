/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** hash
*/

#include <stdio.h>

#include "my.h"
#include "../../include/secured.h"

int hash(char *key, int len)
{
    int final_hash = 0;

    for (int i = 0; key[i]; ++i) {
        final_hash += final_hash ^ (key[i] * (i + 1));
        final_hash += len * my_strlen(key);
        final_hash <<= key[i] % my_strlen(key);
        if (final_hash < 0)
            final_hash *= (-1);
        /*final_hash >>= my_strlen(pass_key) % my_strlen(key)*/;
    }
    return final_hash;
}
