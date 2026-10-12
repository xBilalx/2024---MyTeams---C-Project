/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** logout
*/

#include "../server.h"

void logout(data_t *data_serv, char **command, client_t *client_tcp)
{
    if (client_tcp->teams_user == NULL) {
        dprintf(client_tcp->_sd_client, "16 4\r\n");
        return;
    }
    dprintf(client_tcp->_sd_client, "2 \"%s\" \"%s\"\r\n",
        client_tcp->teams_user->str_uuid, client_tcp->teams_user->_name);
    server_event_user_logged_out(client_tcp->teams_user->str_uuid);
    client_tcp->teams_user = NULL;
    client_tcp->useFeature.entity = data_serv->data_teams->racine;
    client_tcp->useFeature.usecontext = ContextNothing;
}
