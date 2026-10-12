/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** messages
*/

#include "../server.h"

void display_message1(user_teams_t *recipient, client_t *client_tcp,
    teams_data_t *data_teams)
{
    storage_t *listMessage;
    entity_t *mess;
    user_teams_t *sender = client_tcp->teams_user;
    int fd = client_tcp->_sd_client;

    listMessage = sender->listMessage;
    if (listMessage == NULL) {
    }
    for (; listMessage != NULL; listMessage = listMessage->next) {
        mess = listMessage->entity;
        dprintf(fd, "6 \"%s\" \"%s\" \"%s\"\r\n", mess->creator->str_uuid,
        mess->date, mess->desc);
    }
}

void messages(data_t *data_serv, char **command, client_t *client_tcp)
{
    int size = 0;
    user_teams_t *user_list = data_serv->data_teams->user_list;

    if (client_tcp->teams_user == NULL) {
        dprintf(client_tcp->_sd_client, "16 4\r\n");
        return;
    }
    for (; command[size] != NULL; size++);
    if (size != 2)
        return;
    for (; user_list != NULL; user_list = user_list->next) {
        if (strcmp(command[1], user_list->str_uuid) == 0) {
            display_message1(user_list, client_tcp, data_serv->data_teams);
        }
    }
}
