/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** secured
*/

#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "secured.h"
#include "my.h"

static char *get_bin_char(char c)
{
    char *bin = malloc(sizeof(char) * (SIZE_BINARY_LETTER + 1));
    int value = (int) c;

    if (!bin) {
        return NULL;
    }
    for (int i = SIZE_BINARY_LETTER - 1; i >= 0; --i) {
        bin[i] = value % 2 + '0';
        value = value / 2;
    }
    return bin;
}

char *get_bin_str(char *str)
{
    char *bin = malloc(sizeof(char) * (my_strlen(str) * 8 + my_strlen(str)));
    char *bin_char;

    if (!bin) {
        return NULL;
    }
    for (int i = 0; str[i]; ++i) {
        bin_char = get_bin_char(str[i]);
        if (!bin) {
            return NULL;
        }
        my_strcat(bin, bin_char);
        my_strcat(bin, " ");
        free(bin_char);
    }
    return bin;
}

int secured(void)
{
    int size = 5;

    printf("Vision: %d\n", hash("Vision", size));
    printf("Perception: %d\n", hash("Perception", size));
    printf("Fight: %d\n", hash("Fight", size));
    printf("Pathfinding: %d\n", hash("Pathfinding", size));
    return 0;
}
