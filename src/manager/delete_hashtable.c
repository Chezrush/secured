/*
** EPITECH PROJECT, 2025
** secured
** File description:
** delete hashtable
*/

#include <stdlib.h>
#include "hashtable.h"
#include "secured.h"

static void delete_entry(hashtable_entry_t *entry)
{
    free_list(entry->list);
    free(entry);
}

void delete_hashtable(hashtable_t *ht)
{
    for (int i = 0; i < ht->len; ++i) {
        delete_entry(ht->list[i]);
    }
    free(ht->list);
    free(ht);
}
