/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** main
*/

#include "hashtable.h"
#include <stdio.h>

int main(void)
{
    int size = 3;
    hashtable_t *ht = new_hashtable(hash, size);

    if (!ht) {
        return FAIL;
    }
    printf("vision\n");
    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    printf("kratos 1\n");
    ht_insert(ht, "Kratos", "./Trash/Holidays_Pics/.secret_folder/kratos.ai");
    printf("kratos 2\n");
    ht_insert(ht, "Kratos", "pipi");
    printf("<3\n");
    ht_dump(ht);
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    printf("</3\n");
    ht_insert(ht, "</3", "+33 7 51 49 01 38 11");
    printf("dump\n");
    ht_dump(ht);
    ht_delete(ht, "Vision");
    ht_delete(ht, "<3");
    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_delete(ht, "Vision");
    ht_dump(ht);
    ht_delete(ht, "zuefdsnj");
    printf("\n");
    ht_dump(ht);
    printf("\n");
    ht_delete(ht, "</3");
    printf("%s\n", ht_search(ht, "</3"));
    printf("%s\n", ht_search(ht, "Kratos"));
    delete_hashtable(ht);
    return SUCCESS;
}
