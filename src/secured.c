/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** secured
*/

#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "secured.h"
#include "my.h"

static char *get_bin_char(char c)
{
    char *bin = malloc(sizeof(char) * (SIZE_BINARY_LETTER + 1));
    int value = (int) c;

    if (!bin) {
        return NULL;
    }
    for (int i = SIZE_BINARY_LETTER - 1; i >= 0; --i) {
        bin[i] = value % 2 + '0';
        value = value / 2;
    }
    return bin;
}

char *get_bin_str(char *str)
{
    char *bin = malloc(sizeof(char) * (my_strlen(str) * 8 + my_strlen(str)));
    char *bin_char;

    if (!bin) {
        return NULL;
    }
    for (int i = 0; str[i]; ++i) {
        bin_char = get_bin_char(str[i]);
        if (!bin) {
            return NULL;
        }
        my_strcat(bin, bin_char);
        my_strcat(bin, " ");
        free(bin_char);
    }
    return bin;
}

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

    if (!ht) {
        return NULL;
    }
    ht->hash = hash;
    ht->len = len;
    ht->list = malloc(sizeof(hashtable_entry_t *) * len + 1);
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

int secured(void)
{
    int size = 100;
    hashtable_t *ht = new_hashtable(hash, size);

    if (!ht) {
        return FAIL;
    }
    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Hollidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_insert(ht, "</3", "+33 7 51 49 01 38 11");
    ht_dump(ht);
    return SUCCESS;
}
