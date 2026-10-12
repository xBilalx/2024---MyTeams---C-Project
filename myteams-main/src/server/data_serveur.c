/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** data_serveur
*/

#include "server.h"

void init_data_serv_2(data_t *d)
{
    for (int i = 0; i < d->_max_client; i++) {
        d->_client_list[i]._sd_client = 0;
        d->_client_list[i]._id = i + 1;
        d->_client_list[i].command1 = NULL;
        d->_client_list[i].len_command = 0;
        d->_client_list[i]._user_check = 0;
        d->_client_list[i].connected = 0;
        d->_client_list[i]._sd_data = 0;
        d->_client_list[i].teams_user = NULL;
        d->_client_list[i].useFeature.entity = d->data_teams->racine;
        d->_client_list[i].useFeature.usecontext = ContextNothing;
    }
}

void init_data_serv(int port, data_t *d, char *path)
{
    struct sockaddr_in address;

    d->_max_sd = 0;
    d->_path = path;
    d->port_serveur = port;
    d->_address.sin_family = AF_INET;
    d->_address.sin_port = htons(port);
    d->_address.sin_addr.s_addr = INADDR_ANY;
    d->addrlen = sizeof(d->_address);
    d->_max_client = 32;
    d->_client_list = malloc(sizeof(client_t) * d->_max_client);
    d->data_teams = init_data_teams();
    init_data_serv_2(d);
}
