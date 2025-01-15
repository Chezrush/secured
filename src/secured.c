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
    int size = 5;
    printf("Vision: %d\n", hash("Vision", size));
    printf("Perception: %d\n", hash ("Perception", size));
    printf("Fight: %d\n", hash( "Fight", size));
    printf("Pathfinding: %d\n", hash("Pathfinding", size));
    return 0;
}
