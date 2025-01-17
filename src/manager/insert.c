/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** insert
*/

#include "hashtable.h"
#include "secured.h"

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    push_to_list(&ht, key, value, hash(key, ht->len));
    return SUCCESS;
}
