/*
** EPITECH PROJECT, 2024
** my_is_prime.c
** File description:
** my_is_prime.c
*/

int my_is_prime(int n)
{
    int i = 5;
    int is_prime = 1;

    if (n == 2 || n == 3)
        return 1;
    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return 0;
    while (i * i <= n) {
        is_prime = (n % i == 0 || n % (i + 2) == 0) ? 0 : is_prime;
        i += 6;
    }
    return is_prime;
}
