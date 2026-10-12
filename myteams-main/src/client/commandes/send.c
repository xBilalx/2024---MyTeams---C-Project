/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** send
*/

#include "../client.h"

int send_msg(char **inf)
{
    return 1;
}

int ask_for_send_msg(char *inf)
{
    char message[MAX_BODY_LENGTH + MAX_NAME_LENGTH];

    if (strlen(inf) < MAX_BODY_LENGTH) {
        snprintf(message, sizeof(message) + 6, "4 %s\r\n", inf);
        write(globalConstClient.socket, message, strlen(message));
        return 1;
    }
    return -1;
}
