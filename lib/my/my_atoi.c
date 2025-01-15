/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** my_atoi
*/

int my_atoi(char const *str)
{
    int i = 0;
    int res = 0;
    int minus = 1;

    for (; str[i] == '-'; ++i)
        minus = minus * -1;
    for (; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
    return (res * minus);
}
