/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** subscibe
*/

#include "../client.h"

int ask_for_subscribe(char *inf)
{
    char message[MAX_NAME_LENGTH];

    if (strlen(inf) < MAX_NAME_LENGTH) {
        snprintf(message, sizeof(message) + 6, "6 %s\r\n", inf);
        write(globalConstClient.socket, message, strlen(message));
        return 1;
    }
    return -1;
}

int subscribe(char **res)
{
    return client_print_subscribed(res[1], res[2]);
}

int ask_for_subscribed(char *inf)
{
    char buff[MAX_BODY_LENGTH];

    snprintf(buff, 8, "7 %s\r\n", inf);
    write(globalConstClient.socket, buff, strlen(buff));
    return 1;
}

int subscribed(char **res)
{
    int n = 0;

    while (res[n] != NULL || res[n + 1] != NULL || res[n + 2] != NULL) {
        client_print_teams(res[n], res[n + 1], res[n + 2]);
    }
    free(res);
    return 1;
}
