/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H

    #define FAIL 84
    #define SUCCESS 0
    #include <stdint.h>

typedef struct hashtable_value_s {
    int id;
    int hash_key;
    char *value;
    struct hashtable_value_s *next;
} hashtable_value_t;

typedef struct hashtable_entry_s {
    int id;
    int num_item;
    hashtable_value_t *list;
} hashtable_entry_t;

typedef struct hashtable_s {
    int len;
    int (*hash)(char *, int);
    hashtable_entry_t **list;
} hashtable_t;

// Hash function
int hash(char *key, int len);

// Create & destro table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

#endif /* HASHTABLE_H */
