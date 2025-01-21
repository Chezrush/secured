/*
** EPITECH PROJECT, 2024
** organized
** File description:
** linked lists
*/

#include "secured.h"
#include "my.h"
#include <stdlib.h>

static void free_node(hashtable_value_t *list)
{
    free(list->value);
    free(list);
}

int free_list(hashtable_value_t *list)
{
    if (list->next == NULL) {
        free_node(list);
    } else {
        free_list(list->next);
        free_node(list);
    }
    return SUCCESS;
}

int display_list(hashtable_value_t *begin)
{
    if (!begin) {
        return SUCCESS;
    }
    if (begin->next == NULL) {
        my_putstr("\n> ");
        my_put_nbr(begin->hash_key);
        my_putstr(" - ");
        my_putstr(begin->value);
    } else {
        display_list(begin->next);
        my_putstr("\n> ");
        my_put_nbr(begin->hash_key);
        my_putstr(" - ");
        my_putstr(begin->value);
    }
    return SUCCESS;
}

static void remove_last_node(hashtable_value_t **list)
{
    free((*list)->value);
    (*list)->value = NULL;
}

static int remove_node(hashtable_value_t **list)
{
    hashtable_value_t *temp;

    if ((*list)->next == NULL) {
        remove_last_node(list);
    } else {
        temp = malloc(sizeof(hashtable_value_t));
        if (!temp) {
            return FAIL;
        }
        (*list)->id = (*list)->next->id;
        (*list)->value = my_strdup((*list)->next->value);
        (*list)->hash_key = (*list)->next->hash_key;
        temp->next = (*list)->next;
        (*list)->next = (*list)->next->next;
        free_node(temp->next);
        free(temp);
    }
    return SUCCESS;
}

static int delete_next(hashtable_value_t **begin, int hash_key)
{
    if ((*begin)->next->hash_key == hash_key && (*begin)->next->next != NULL) {
        if (remove_node(&(*begin)->next) == FAIL) {
            return FAIL;
        }
    }
    if (!(*begin)->next->next && (*begin)->next->hash_key == hash_key) {
        if (remove_node(&(*begin)->next) == FAIL) {
            return FAIL;
        }
        (*begin)->next = NULL;
    }
    if ((*begin)->next != NULL) {
        delete_in_list(&(*begin)->next, hash_key);
    }
    return SUCCESS;
}

int delete_in_list(hashtable_value_t **begin, int hash_key)
{
    if ((*begin)->hash_key == hash_key) {
        if (remove_node(begin) == FAIL) {
            return FAIL;
        }
    }
    if ((*begin)->next != NULL) {
        if (delete_next(begin, hash_key) == FAIL) {
            return FAIL;
        }
    }
    return SUCCESS;
}

int create_list(hashtable_value_t **list, char *value, int id, int hash)
{
    (*list)->value = my_strdup(value);
    (*list)->hash_key = hash;
    (*list)->id = id;
    return SUCCESS;
}

int push_to_list(hashtable_value_t **begin, char *value, int id, int hash)
{
    hashtable_value_t *next = malloc(sizeof(hashtable_value_t));

    if (!next) {
        return FAIL;
    }
    next->id = (*begin)->id;
    next->value = my_strdup((*begin)->value);
    next->hash_key = (*begin)->hash_key;
    free((*begin)->value);
    next->next = (*begin)->next;
    (*begin)->next = next;
    (*begin)->id = id;
    (*begin)->value = my_strdup(value);
    (*begin)->hash_key = hash;
    return SUCCESS;
}
