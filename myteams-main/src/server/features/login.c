/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** login
*/

#include "../server.h"

void login(data_t *data_serv, char **command, client_t *cli)
{
    int size = 0;
    user_teams_t *user_connection;

    for (; command[size] != NULL; size++);
    if (size < 2)
        return;
    user_connection = user_exist(command[1], data_serv->data_teams);
    if (cli->teams_user != NULL && cli->teams_user == user_connection)
        return;
    if (user_connection == NULL)
        user_connection = create_user(command[1], data_serv->data_teams);
    cli->teams_user = user_connection;
    server_event_user_logged_in(user_connection->str_uuid);
    dprintf(cli->_sd_client, "1 \"%s\" \"%s\"\r\n", user_connection->str_uuid,
        user_connection->_name);
}
