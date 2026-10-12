/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** unsubscribe
*/

#include "../client.h"

int ask_for_unsubscribes(char *inf)
{
    char buff[MAX_BODY_LENGTH];

    snprintf(buff, sizeof(buff) + 6, "8 %s\r\n", inf);
    write(globalConstClient.socket, buff, strlen(buff));
    return 1;
}

int unsubscribes(char **res)
{
    return client_print_subscribed(res[1], res[2]);
}
