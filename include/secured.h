/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** secured
*/

#ifndef SECURED_H
    #define SECURED_H

    #define SIZE_BINARY_LETTER 8

    #include "hashtable.h"

int secured(void);
int display_list(hashtable_value_t *begin);
int free_list(hashtable_value_t *list);
int delete_in_list(hashtable_value_t **begin, int hash_key);
int push_to_list(hashtable_value_t **begin, char *value, int id, int hash);
int create_list(hashtable_value_t **list, char *value, int id, int hash);

#endif /* SECURED_H */
