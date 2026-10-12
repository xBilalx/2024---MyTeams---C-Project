/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** quit
*/

#include "../server.h"

void close_client(client_t *client, data_t *d)
{
    close(client->_sd_client);
    client->_sd_client = 0;
    if (client->command1 != NULL)
        free(client->command1);
    client->command1 = NULL;
    client->len_command = 0;
    client->connected = 0;
    client->_user_check = 0;
    client->_sd_data = 0;
    if (client->teams_user != NULL) {
    server_event_user_logged_out(client->teams_user->str_uuid);
        client->teams_user = NULL;
        client->useFeature.entity = d->data_teams->racine;
        client->useFeature.usecontext = ContextNothing;
    }
}
