/*
** EPITECH PROJECT, 2025
** secured
** File description:
** search
*/

#include "stddef.h"
#include "hashtable.h"

char *ht_search(hashtable_t *ht, char *key)
{
    int hash_key = ht->hash(key, ht->len);
    hashtable_entry_t *entry = ht->list[hash_key % ht->len];
    hashtable_value_t *value = entry->list;

    for (int i = 0; i < entry->num_item; ++i) {
        if (value->hash_key == hash_key) {
            return value->value;
        }
        value = value->next;
    }
    return NULL;
}
