/*
** EPITECH PROJECT, 2025
** secured
** File description:
** dump
*/

#include "hashtable.h"
#include "secured.h"
#include "my.h"

static void display_entry(hashtable_t *ht, int i)
{
    if (ht->list[i]->num_item != 0) {
        if (ht->list[i]->num_item != 0) {
            display_list(ht->list[i]->list);
        }
    }
}

void ht_dump(hashtable_t *ht)
{
    if (ht) {
        for (int i = 0; i < ht->len; ++i) {
            my_putchar('[');
            my_put_nbr(i);
            my_putstr("]:");
            display_entry(ht, i);
            my_putchar('\n');
        }
    }
}
