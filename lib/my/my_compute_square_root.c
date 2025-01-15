/*
** EPITECH PROJECT, 2024
** my_compute_square_root.c
** File description:
** my_compute_square_root.c
*/

int my_compute_power_it(int nb, int p)
{
    int result = 0;
    int i = 1;

    result = (p == 0) ? 1 : nb;
    if (p < 0)
        return 0;
    while (i < p) {
        result *= nb;
        i++;
        result = (result > 2147483647) ? 0 : result;
    }
    return result;
}

int my_compute_square_root(int nb)
{
    int result = 0;
    int i = 1;
    int add = 0;

    while (result < nb) {
        add = 2 * i - 1;
        result += add;
        i++;
    }
    i--;
    i = (my_compute_power_it(i, 2) != nb) ? 0 : i;
    return i;
}
