/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** check_return_value
*/

#include "hashtable.h"
#include <stdio.h>

int main(void)
{
    int size = 100;
    hashtable_t *ht_bad_null_struct = new_hashtable(NULL, size);
    hashtable_t *ht_bad_null_all = new_hashtable(NULL, NULL);
    hashtable_t *ht_bad_null_size = new_hashtable(hash, NULL);
    hashtable_t *ht = new_hashtable(hash, size);

    if (ht_bad_null_struct == NULL)
        printf("ht_bad_null_struct = return NULL\n");
    if (ht_bad_null_all == NULL)
        printf("ht_bad_null_all = return NULL\n");
    if (ht_bad_null_size == NULL)
        printf("ht_bad_null_size = return NULL\n");
    if (ht != NULL)
        printf("ht = ! NULL\n\n");

    printf("Voici les cas d'erreurs: \n");

    printf("Test normal return 0: res = %d\n", ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision"));
    
    printf("-------------------------------\n");
    printf("Test sans value return 84: res = %d\n", ht_insert(ht, "Vision", ""));
    printf("-------------------------------\n");
    printf("Test sans value null return 84: res = %d\n", ht_insert(ht, "Vision", NULL));
    printf("-------------------------------\n");
    printf("Test sans value return 84: res = %d\n", ht_insert(ht, "", "./Documents/Tournament/Modules/Vision"));
    printf("-------------------------------\n");
    printf("Test sans value null return 84: res = %d\n", ht_insert(ht, NULL, "./Documents/Tournament/Modules/Vision"));
    printf("-------------------------------\n");
    printf("Test avec NULL sur la ht return 84: res = %d\n", ht_insert(NULL, "Vision", "./Documents/Tournament/Modules/Vision"));
    printf("-------------------------------\n");
    printf("Test avec NULL sur la ht et key vide return 84: res = %d\n", ht_insert(NULL, "", "./Documents/Tournament/Modules/Vision"));
    printf("-------------------------------\n");
    printf("Test avec NULL sur la ht et key null return 84: res = %d\n", ht_insert(NULL, NULL, "./Documents/Tournament/Modules/Vision"));
    printf("-------------------------------\n");
    printf("Test avec NULL sur la ht, key null et value vide return 84: res = %d\n", ht_insert(NULL, NULL, ""));
    printf("-------------------------------\n");
    printf("Test avec NULL sur la ht, key null et value null return 84: res = %d\n", ht_insert(NULL, NULL, NULL));
    printf("-------------------------------\n");
    printf("Test avec la ht good, key null et value null return 84: res = %d\n", ht_insert(NULL, NULL, NULL));
}
