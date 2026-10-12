/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** list
*/

#include "../client.h"

int ask_for_list(char *inf)
{
    char buffer[MAX_BODY_LENGTH];

    snprintf(buffer, sizeof(buffer), "11 %s\r\n", inf);
    write(globalConstClient.socket, buffer, strlen(buffer));
}

int list(char **rep)
{
    if (strcmp(rep[1], "0") == 0)
        return client_print_teams(rep[2], rep[3], rep[4]);
    if (strcmp(rep[1], "1") == 0)
        return client_team_print_channels(rep[2], rep[3], rep[4]);
    if (strcmp(rep[1], "2") == 0)
        return client_channel_print_threads(rep[2], rep[3],
            str_to_time_t(rep[4]), rep[5], rep[6]);
    if (strcmp(rep[1], "3") == 0)
        return client_thread_print_replies(rep[2], rep[3],
            str_to_time_t(rep[4]), rep[5]);
}
