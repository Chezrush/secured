/*
** EPITECH PROJECT, 2024
** my_print_comb2.c
** File description:
** my_print_comb2.c
*/

#include "my.h"

void print_res(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648){
        print_res();
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb / 10)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
    return 0;
}
