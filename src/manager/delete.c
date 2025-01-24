/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** delete
*/

#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "secured.h"

static int delete_value(hashtable_entry_t **entry, int hash_key)
{
    int delete_return = delete_in_list(&(*entry)->list, hash_key);

    if (delete_return == FAIL) {
        return FAIL;
    }
    --(*entry)->num_item;
    if ((*entry)->num_item == 0) {
        (*entry)->list = malloc(sizeof(hashtable_value_t));
    }
    if (!(*entry)->list) {
        return FAIL;
    }
    return SUCCESS;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int hash_key = 0;
    int index = 0;
    hashtable_entry_t **entry = NULL;

    if (!ht || key == NULL || key[0] == '\0' || !ht_search(ht, key)) {
        return FAIL;
    }
    hash_key = ht->hash(key, ht->len);
    if (hash_key < 0) {
        return FAIL;
    }
    index = ((hash_key % ht->len) + ht->len) % ht->len;
    entry = &(ht->list[index]);
    return delete_value(entry, hash_key);
}
