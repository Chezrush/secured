/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** insert
*/

#include "hashtable.h"
#include "secured.h"

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int ind_ht = ht->hash(key, ht->len);
    hashtable_entry_t **entry = &(ht->list[ind_ht % ht->len]);

    if ((*entry)->num_item == 0) {
        create_list(&(*entry)->list, value, (*entry)->num_item, ind_ht);
    } else {
        push_to_list(&(*entry)->list, value, (*entry)->num_item, ind_ht);
    }
    (*entry)->num_item += 1;
    return SUCCESS;
}
