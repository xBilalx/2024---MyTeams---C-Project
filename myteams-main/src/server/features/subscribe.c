/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** subscribe
*/

#include "../server.h"

void subscribe(data_t *data_serv, char **command, client_t *client_tcp)
{
    if (client_tcp->teams_user == NULL) {
        dprintf(client_tcp->_sd_client, "16 4\r\n");
        return;
    }
}
