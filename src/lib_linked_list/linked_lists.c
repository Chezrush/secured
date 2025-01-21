/*
** EPITECH PROJECT, 2024
** organized
** File description:
** linked lists
*/

#include <stdlib.h>
#include "secured.h"
#include "my.h"

#include <stdio.h>

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
        my_putstr("\n> ");
        my_put_nbr(begin->hash_key);
        my_putstr(" - ");
        my_putstr(begin->value);
        display_list(begin->next);
    }
    return SUCCESS;
}

static void remove_first_node(hashtable_value_t **begin)
{
    hashtable_value_t *tmp;

    tmp = *begin;
    (*begin) = (*begin)->next;
    free_node(tmp);
}

static void remove_last_node(hashtable_value_t *node)
{
    free_node(node->next);
    node->next = NULL;
}

static void remove_node(hashtable_value_t *node)
{
    hashtable_value_t *tmp;

    tmp = node->next;
    node->next = node->next->next;
    free_node(tmp);
}

int delete_in_list(hashtable_value_t **begin, int hash_key)
{
    if ((*begin)->hash_key == hash_key) {
        remove_first_node(begin);
    }
    if ((*begin) != NULL) {
        printf("%p\n", (*begin));
        if ((*begin)->next != NULL && (*begin)->next->hash_key == hash_key
        && (*begin)->next->next != NULL) {
            remove_node((*begin));
        }
        if ((*begin)->next != NULL && (*begin)->next->hash_key == hash_key
        && (*begin)->next->next == NULL) {
            remove_node(*begin);
        }
        if ((*begin)->next != NULL) {
            delete_in_list(&(*begin)->next, hash_key);
        }
    }
    return SUCCESS;
}

int create_list(hashtable_value_t **list, char *value, int id, int hash)
{
    (*list)->value = my_strdup(value);
    (*list)->hash_key = hash;
    (*list)->id = id;
    (*list)->next = NULL;
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
