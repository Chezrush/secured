/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** test.c
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n; i++){
        if (n < i) {
            dest[i] = '\0';
            return dest;
        }
        dest[i] = src[i];
    }
    return dest;
}
