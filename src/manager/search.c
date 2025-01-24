/*
** EPITECH PROJECT, 2025
** secured
** File description:
** search
*/

#include "stddef.h"
#include "hashtable.h"

#include <stdio.h>

static char *search_value(hashtable_entry_t *entry,
    hashtable_value_t *ht_value, int hash_key)
{
    for (int i = 0; i < entry->num_item; ++i) {
        if (ht_value->hash_key == hash_key) {
            return ht_value->value;
        }
        ht_value = ht_value->next;
    }
    return NULL;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int hash_key = 0;
    int index = 0;
    hashtable_entry_t *entry = NULL;
    hashtable_value_t *ht_value = NULL;

    if (!ht || key == NULL || key[0] == '\0') {
        return NULL;
    }
    hash_key = ht->hash(key, ht->len);
    if (hash_key < 0) {
        return NULL;
    }
    index = ((hash_key % ht->len) + ht->len) % ht->len;
    entry = ht->list[index];
    ht_value = entry->list;
    return search_value(entry, ht_value, hash_key);
}
