/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** subscibed
*/

#include "../server.h"

void subscibed(data_t *data_serv, char **command, client_t *client_tcp)
{
    printf("Fonction -> subscibed\n");
    if (client_tcp->teams_user == NULL) {
        dprintf(client_tcp->_sd_client, "16 4\r\n");
        return;
    }
}
