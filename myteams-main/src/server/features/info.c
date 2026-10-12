/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** info
*/

#include "../server.h"

void disply_info_user(client_t *cli)
{
    user_teams_t *usr = cli->teams_user;

    dprintf(cli->_sd_client, "4 \"%s\" \"%s\" \"%s\"\r\n",
        usr->str_uuid, usr->_name, "N/C");
}

void display_info(client_t *client_tcp, teams_data_t *data, char **command)
{
    int size = 0;
    entity_t *fat = client_tcp->useFeature.entity;
    int fd = client_tcp->_sd_client;

    if (client_tcp->useFeature.usecontext == ContextNothing) {
        disply_info_user(client_tcp);
        return;
    }
    if (client_tcp->useFeature.usecontext == ContextTeam)
        dprintf(fd, "13 0 \"%s\" \"%s\" \"%s\"\r\n", fat->str_uuid,
            fat->_name, fat->desc);
    if (client_tcp->useFeature.usecontext == ContextChannel)
        dprintf(fd, "13 1 \"%s\" \"%s\" \"%s\"\r\n", fat->str_uuid,
            fat->_name, fat->desc);
    if (client_tcp->useFeature.usecontext == ContextThread)
        dprintf(fd, "13 2 \"%s\" \"%s\" \"%s\" \"%s\" \"%s\"\r\n",
            fat->str_uuid,
            fat->creator->str_uuid, fat->date, fat->_name, fat->desc);
}

void info(data_t *data_serv, char **command, client_t *client_tcp)
{
    int size = 0;

    if (client_tcp->teams_user == NULL) {
        dprintf(client_tcp->_sd_client, "16 4\r\n");
        return;
    }
    for (; command[size] != NULL; size++);
    display_info(client_tcp, data_serv->data_teams, command);
}
