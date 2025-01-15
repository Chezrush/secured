/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include <stdio.h>
#include <stdlib.h>

static void line_copy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
}

char **my_str_to_word_array(char const *str, char const sep)
{
    char **tab = {0};
    int nb_line = 1;
    int cpt = 0;
    int inconnu = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == sep)
            nb_line++;
    tab = malloc(sizeof(char *) * (nb_line + 1));
    for (int i = 0; i < nb_line; i++) {
        cpt = 0;
        for (; str[inconnu] != sep && str[inconnu] != '\0'; inconnu++)
            cpt++;
        tab[i] = malloc(sizeof(char) * (cpt + 1));
        line_copy(tab[i], &str[inconnu - cpt], cpt);
        inconnu++;
    }
    tab[nb_line] = NULL;
    return tab;
}
