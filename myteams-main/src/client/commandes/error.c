/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** error
*/

#include "../client.h"

int ask_for_error(char *)
{
    return 0;
}

int error(char **rep)
{
    if (strcmp(rep[1], "0") == 0)
        return client_error_unknown_team(rep[2]);
    if (strcmp(rep[1], "1") == 0)
        return client_error_unknown_channel(rep[2]);
    if (strcmp(rep[1], "2") == 0)
        return client_error_unknown_thread(rep[2]);
    if (strcmp(rep[1], "3") == 0)
        return client_error_unknown_user(rep[2]);
    if (strcmp(rep[1], "4") == 0)
        return client_error_unauthorized();
    if (strcmp(rep[1], "5") == 0)
        return client_error_already_exist();
}
