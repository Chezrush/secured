/*
** EPITECH PROJECT, 2025
** secured
** File description:
** search
*/

#include "stddef.h"
#include "hashtable.h"
#include <stdio.h>

char *ht_search(hashtable_t *ht, char *key)
{
    int hash_key = ht->hash(key, ht->len);
    int index = ((hash_key % ht->len) + ht->len) % ht->len;
    hashtable_entry_t *entry = NULL;
    hashtable_value_t *ht_value = NULL;

    if (key[0] == '\0' || hash_key < 0) {
        return NULL;
    }
    entry = ht->list[index];
    ht_value = entry->list;
    for (int i = 0; i < entry->num_item; ++i) {
        if (ht_value->hash_key == hash_key) {
            return ht_value->value;
        }
        ht_value = ht_value->next;
    }
    return NULL;
}
