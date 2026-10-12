/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** user
*/

#include "../client.h"

int ask_for_user(char *inf)
{
    char message[516];

    snprintf(message, sizeof(message) + 6, "3 %s\r\n", inf);
    write(globalConstClient.socket, message, strlen(message));
    return 1;
}

int user(char **res)
{
    int ret = 0;

    ret = client_print_user(res[1], res[2], atoi(res[3]));
    free(res);
    return ret;
}
