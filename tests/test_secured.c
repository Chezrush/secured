/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-secured-valentin.mine-perso
** File description:
** test_secured
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "secured.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

int secured(void);

Test(Hello_World, check_return_output, .init = redirect_all_std)
{
    printf("Hello World");
    cr_assert_stdout_eq_str("Hello World");
}
