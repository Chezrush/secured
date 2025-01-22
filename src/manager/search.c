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
    hashtable_entry_t *entry = ht->list[index];
    hashtable_value_t *value = entry->list;

    if (hash_key < 0)
        hash_key *= -1;
    for (int i = 0; i < entry->num_item; ++i) {
        if (value->hash_key == hash_key) {
            return value->value;
        }
        value = value->next;
    }
    return NULL;
}
