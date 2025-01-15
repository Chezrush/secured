/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** test.c
*/

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

bool check_ismax(long int nb)
{
    if (nb > INT_MAX || nb < INT_MIN)
        return true;
    if (nb > LONG_MAX || nb < LONG_MAX)
        return false;
    return false;
}

int check_i(char const *str, int i)
{
    while (str[i] == '+' || str[i] == '-')
        i = i + 1;
    return i;
}

int check_isneg(char const *str, int i)
{
    int isneg = 1;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            isneg = isneg * - 1;
        i = i + 1;
    }
    return isneg;
}

int my_getnbr(char const *str)
{
    long int nb = 0;
    int i = 0;
    int isneg = check_isneg(str, i);
    int l_numb = 0;

    i = check_i(str, i);
    for (; str[i] != '\0'; i++) {
        if (l_numb > 9)
            return (0);
        if (str[i] >= '0' && str[i] <= '9') {
            nb = (nb * 10) + str[i] - '0';
            l_numb++;
        } else
            return check_ismax(nb * isneg) ? (0) : (nb * isneg);
    }
    return check_ismax(nb * isneg) ? (0) : (nb * isneg);
}
