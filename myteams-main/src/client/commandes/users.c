/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** users
*/

#include "../client.h"

int ask_for_users(char *)
{
    char message[516];

    snprintf(message, sizeof(message) + 6, "2 %s\r\n", "");
    write(globalConstClient.socket, message, strlen(message));
    return 1;
}

int users(char **res)
{
    client_print_users(res[1], res[2], atoi(res[3]));
    free(res);
    return 1;
}
