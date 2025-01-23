/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** insert
*/

#include <stdio.h>

#include "hashtable.h"
#include "secured.h"

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int hash_key = ht->hash(key, ht->len);
    int index = ((hash_key % ht->len) + ht->len) % ht->len;
    hashtable_entry_t **entry = NULL;

    if (key[0] == '\0' || value[0] == '\0' || hash_key < 0) {
        return FAIL;
    }
    entry = &(ht->list[index]);
    if ((*entry)->num_item == 0) {
        create_list(&(*entry)->list, value, (*entry)->num_item, hash_key);
    } else {
        push_to_list(&(*entry)->list, value, (*entry)->num_item, hash_key);
    }
    (*entry)->num_item += 1;
    return SUCCESS;
}
