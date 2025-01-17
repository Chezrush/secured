/*
** EPITECH PROJECT, 2024
** organized
** File description:
** linked lists
*/

#include "secured.h"
#include <stdlib.h>

static void free_node(hashtable_value_t *list)
{
    free(list->key);
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
    if (!begin->next) {
        return SUCCESS;
    }
    if (begin->next == NULL) {
    } else {
        display_list(begin->next);
    }
    return SUCCESS;
}

static void remove_last_node(hashtable_value_t **list)
{
    free((*list)->key);
    free((*list)->value);
    (*list)->key = NULL;
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
        (*list)->key = my_strdup((*list)->next->key);
        (*list)->value = my_strdup((*list)->next->value);
        temp->next = (*list)->next;
        (*list)->next = (*list)->next->next;
        free_node(temp->next);
        free(temp);
    }
    return SUCCESS;
}

static int delete_next(hashtable_value_t **begin, char *key)
{
    if ((*begin)->next->key == key && (*begin)->next->next != NULL) {
        if (remove_node(&(*begin)->next) == FAIL) {
            return FAIL;
        }
    }
    if (!(*begin)->next->next && (*begin)->next->key == key) {
        if (remove_node(&(*begin)->next) == FAIL) {
            return FAIL;
        }
        (*begin)->next = NULL;
    }
    if ((*begin)->next != NULL) {
        delete_in_list(&(*begin)->next, key);
    }
    return SUCCESS;
}

int delete_in_list(hashtable_value_t **begin, char *key)
{
    if ((*begin)->key == key) {
        if (remove_node(begin) == FAIL) {
            return FAIL;
        }
    }
    if ((*begin)->next != NULL) {
        if (delete_next(begin, key) == FAIL) {
            return FAIL;
        }
    }
    return SUCCESS;
}

int push_to_list(hashtable_value_t **begin, char *key, char *value, int id)
{
    hashtable_value_t *next = malloc(sizeof(hashtable_value_t));

    if (!next) {
        return FAIL;
    }
    next->id = (*begin)->id;
    next->key = my_strdup((*begin)->key);
    next->value = my_strdup((*begin)->value);
    free((*begin)->key);
    free((*begin)->value);
    next->next = (*begin)->next;
    (*begin)->next = next;
    (*begin)->id = id;
    (*begin)->key = my_strdup(key);
    (*begin)->value = my_strdup(value);
    return SUCCESS;
}
