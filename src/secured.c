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
    printf("V : %d\nK : %d\nV : %d\n", hash("Vision", ht->len), hash("Kratos", ht->len), hash("Vision", ht->len));
    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    /*ht_insert(ht, "Kratos", "./Trash/Holidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_insert(ht, "</3", "+33 7 51 49 01 38 11");
    ht_dump(ht);
    //printf("\ndelete Vision\n");
    ht_delete(ht, "Vision");
    ht_dump(ht);
    //printf("\ndelete <3\n");
    ht_delete(ht, "<3");
    ht_dump(ht);
    printf("\ndelete Kratosn\n");
    ht_delete(ht, "Kratos");
    ht_dump(ht);
    printf("\ninsert Vision\n");
    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_delete(ht, "Vision");
    ht_dump(ht);*/
    printf("V : %d\nK : %d\nV : %d\n", hash("Vision", ht->len), hash("Kratos", ht->len), hash("Vision", ht->len));
    delete_hashtable(ht);
    return SUCCESS;
}
