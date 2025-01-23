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
    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Holidays_Pics/.secret_folder/kratos.ai");
    ht_dump(ht);
    printf("\n\n\n");
    ht_insert(ht, "Kratos", "pipi");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_insert(ht, "</3", "+33 7 51 49 01 38 11");
    ht_dump(ht);
    ht_delete(ht, "Vision");
    ht_delete(ht, "<3");
    //ht_delete(ht, "Kratos");
    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_delete(ht, "Vision");
    ht_dump(ht);
    printf("%s\n", ht_search(ht, "</3"));
    printf("%s\n", ht_search(ht, "Kratos"));
    delete_hashtable(ht);
    return SUCCESS;
}
