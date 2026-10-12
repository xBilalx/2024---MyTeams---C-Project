/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** help
*/

#include "../client.h"

int help(char **)
{
    printf("/help /login /logout /users "
        "/user /send /messages /subscribe "
        "/subscribed /unsubscribe /use /create "
        "/list /info\n");
    return 0;
}

int ask_for_help(char *)
{
    printf("/help /login /logout /users "
        "/user /send /messages /subscribe "
        "/subscribed /unsubscribe /use /create "
        "/list /info\n");
    return 0;
}