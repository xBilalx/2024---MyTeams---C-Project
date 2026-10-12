/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** info
*/

#include "../client.h"

int ask_for_info(char *username)
{
    write(globalConstClient.socket, "12\r\n", strlen("12\r\n"));
    return 1;
}

int info(char **rep)
{
    if (strcmp(rep[1], "0") == 0)
        return client_print_teams(rep[2], rep[3], rep[4]);
    if (strcmp(rep[1], "1") == 0)
        return client_print_channel(rep[2], rep[3], rep[4]);
    if (strcmp(rep[1], "2") == 0)
        return client_print_thread(rep[2], rep[3],
            str_to_time_t(rep[3]), rep[4], rep[5]);
}
