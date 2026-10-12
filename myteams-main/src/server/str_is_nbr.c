/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** str_is_nbr
*/

#include <stdbool.h>

bool str_is_nbr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' && str[i] > '9')
            return true;
    }
    return false;
}
