/*
** EPITECH PROJECT, 2025
** secured
** File description:
** create hashtable
*/

#include <stdlib.h>
#include "my.h"
#include "hashtable.h"

static int create_entry(hashtable_t *ht, int id)
{
    hashtable_entry_t *entry = malloc(sizeof(hashtable_entry_t));

    if (!entry) {
        return FAIL;
    }
    entry->id = id;
    entry->num_item = 0;
    entry->list = malloc(sizeof(hashtable_value_t));
    if (!entry->list) {
        return FAIL;
    }
    ht->list[id] = entry;
    return SUCCESS;
}

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    if (!hash || !ht || len <= 0) {
        return NULL;
    }
    ht->hash = hash;
    ht->len = len;
    ht->list = malloc(sizeof(hashtable_value_t) * (len + 1));
    if (!ht->list) {
        return NULL;
    }
    for (int i = 0; i < len; ++i) {
        if (create_entry(ht, i) == FAIL) {
            return NULL;
        }
    }
    ht->list[len] = NULL;
    return ht;
}
