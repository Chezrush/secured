/*
** EPITECH PROJECT, 2025
** secured
** File description:
** dump
*/

#include "../../include/hashtable.h"
#include "../../include/secured.h"
#include "../../include/my.h"

static void display_entry(hashtable_entry_t *entry)
{
    if (entry->num_item != 0) {
        display_list(entry->list);
    }
}

void ht_dump(hashtable_t *ht)
{
    for (int i = 0; i < ht->len; ++i) {
        my_putchar('[');
        my_put_nbr(i);
        my_putstr("]:");
        display_entry(ht->list[i]);
        my_putchar('\n');
    }
}
