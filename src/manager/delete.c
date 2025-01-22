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

int ht_delete(hashtable_t *ht, char *key)
{
    int hash_key = ht->hash(key, ht->len);
    int index = ((hash_key % ht->len) + ht->len) % ht->len;
    hashtable_entry_t **entry = &(ht->list[index]);

    if (hash_key < 0)
        hash_key *= -1;
    delete_in_list(&(*entry)->list, hash_key);
    --(*entry)->num_item;
    if ((*entry)->num_item == 0) {
        (*entry)->list = malloc(sizeof(hashtable_value_t));
    }
    if (!(*entry)->list) {
        return FAIL;
    }
    return SUCCESS;
}
