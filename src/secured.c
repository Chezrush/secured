/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** secured
*/

#include <stdio.h>
#include "hashtable.h"

int secured(void)
{
    int size = 3;
    hashtable_t *ht = new_hashtable(hash, size);

    if (!ht) {
        return FAIL;
    }
    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Holidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_insert(ht, "</3", "+33 7 51 49 01 38 11");
    ht_dump(ht);
    printf("RUNNNNNNNNNNNN\n");
    ht_delete(ht, "Vision");
    printf("HELLOOOOOOOOOOOOOOOOOOOOOO\n");
    ht_delete(ht, "<3");
    printf("COUCOUUUUUUUUUUUUUUUUUUUUUU\n");
    ht_delete(ht, "Kratos");
    printf("tuzrjyhdgvsbds\n");
    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    printf("b\n");
    ht_delete(ht, "Vision");
    printf("uqg\n");
    ht_dump(ht);
    return SUCCESS;
}
