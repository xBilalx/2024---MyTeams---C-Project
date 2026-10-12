/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** create
*/

#include "../client.h"

int ask_for_create(char *inf)
{
    char buffer[MAX_BODY_LENGTH];

    snprintf(buffer, sizeof(buffer), "10 %s\r\n", inf);
    write(globalConstClient.socket, buffer, strlen(buffer));
}

int create(char **rep)
{
    if (strcmp(rep[1], "3") == 0)
        return client_event_thread_reply_received(rep[2], rep[3],
            rep[3], rep[4]);
    if (strcmp(rep[1], "0") == 0)
        return client_print_team_created(rep[2], rep[3], rep[4]);
    if (strcmp(rep[1], "1") == 0)
        return client_print_channel_created(rep[2], rep[3], rep[4]);
    if (strcmp(rep[1], "2") == 0)
        return client_print_thread_created(rep[2], rep[3],
            str_to_time_t(rep[4]), rep[5], rep[6]);
    if (strcmp(rep[1], "3") == 0)
        return client_print_reply_created(rep[2], rep[3],
            str_to_time_t(rep[4]), rep[5]);
}
