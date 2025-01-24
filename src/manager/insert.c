/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** insert
*/

#include <stdlib.h>
#include "my.h"
#include "hashtable.h"
#include "secured.h"

static int replace_value(hashtable_entry_t *entry, char *value)
{
    free(entry->list->value);
    entry->list->value = my_strdup(value);
    return SUCCESS;
}

static hashtable_entry_t *search_value(hashtable_t *ht, char *key)
{
    int const hash_key = ht->hash(key, ht->len);
    int const index = ((hash_key % ht->len) + ht->len) % ht->len;
    int i = 0;
    hashtable_entry_t *entry = NULL;
    hashtable_value_t *ht_value = NULL;

    entry = ht->list[index];
    ht_value = entry->list;
    for (; i < entry->num_item; ++i) {
        if (ht_value->hash_key == hash_key) {
            return entry;
        }
        ht_value = ht_value->next;
    }
    return NULL;
}

static int insert_value(hashtable_entry_t **entry, hashtable_entry_t *entry_s,
    char *value, int hash_key)
{
    if (entry_s) {
        return replace_value(entry_s, value);
    }
    if ((*entry)->num_item == 0) {
        return create_list(&(*entry)->list, value, (*entry)->num_item,
            hash_key);
    } else {
        return push_to_list(&(*entry)->list, value, (*entry)->num_item,
            hash_key);
    }
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int hash_key;
    int index;
    hashtable_entry_t **entry = NULL;
    hashtable_entry_t *entry_s = NULL;
    int return_value;

    if (!ht || key[0] == '\0' || value[0] == '\0') {
        return FAIL;
    }
    hash_key = ht->hash(key, ht->len);
    if (hash_key < 0) {
        return FAIL;
    }
    index = ((hash_key % ht->len) + ht->len) % ht->len;
    entry = &(ht->list[index]);
    entry_s = search_value(ht, key);
    return_value = insert_value(entry, entry_s, value, hash_key);
    (*entry)->num_item += 1;
    return return_value;
}
