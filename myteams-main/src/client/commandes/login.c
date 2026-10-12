/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** login
*/

#include "../client.h"

int login(char **rep)
{
    client_event_logged_in(rep[1], rep[2]);
    return 1;
}

int ask_for_login(char *username)
{
    char buffer[MAX_NAME_LENGTH + 4];

    if (strlen(username) < MAX_NAME_LENGTH) {
        snprintf(buffer, sizeof(buffer) + 6, "0 %s\r\n", username);
        write(globalConstClient.socket, buffer, strlen(buffer));
        return 1;
    }
    return -1;
}

int logout(char **rep)
{
    client_event_logged_out(rep[1], rep[2]);
    exit(0);
}

int ask_for_logout(char *)
{
    char buffer[MAX_NAME_LENGTH + 4];

    snprintf(buffer, sizeof(buffer) + 6, "1 %s\r\n", "");
    write(globalConstClient.socket, buffer, strlen(buffer));
    return 1;
}
