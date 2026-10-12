/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** use
*/

#include "../client.h"

int ask_for_use(char *inf)
{
    char buffer[MAX_BODY_LENGTH];

    snprintf(buffer, sizeof(buffer), "9 %s\r\n", inf);
    write(globalConstClient.socket, buffer, strlen(buffer));
}

int use(char **)
{
    return 1;
}
