/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** user
*/

#include "../server.h"

char *status_usr(data_t *data_serv, user_teams_t *user)
{
    for (int i = 0; i < data_serv->_max_client; i++) {
        if (data_serv->_client_list[i]._sd_client > 0 &&
            data_serv->_client_list[i].teams_user == user)
            return "1";
    }
    return "0";
}

void users(data_t *d, char **command, client_t *client_tcp)
{
    user_teams_t *user_list = d->data_teams->user_list;
    int size = 0;

    if (client_tcp->teams_user == NULL) {
        dprintf(client_tcp->_sd_client, "16 4\r\n");
        return;
    }
    for (; command[size] != NULL; size++);
    if (size != 1)
        return;
    for (; user_list != NULL; user_list = user_list->next)
        dprintf(client_tcp->_sd_client, "3 \"%s\" \"%s\" \"%s\"\r\n",
            user_list->_name, user_list->str_uuid, status_usr(d, user_list));
}

void user(data_t *data_serv, char **command, client_t *client_tcp)
{
    int size = 0;
    user_teams_t *user_list = data_serv->data_teams->user_list;
    int fd = client_tcp->_sd_client;

    if (client_tcp->teams_user == NULL) {
        dprintf(fd, "16 4\r\n");
        return;
    }
    for (; command[size] != NULL; size++);
    if (size != 2)
        return;
    for (; user_list != NULL; user_list = user_list->next) {
        if (strcmp(command[1], user_list->str_uuid) == 0) {
            dprintf(fd, "4 \"%s\" \"%s\" \"%s\"\r\n", user_list->str_uuid,
            user_list->_name, status_usr(data_serv, user_list));
            return;
        }
    }
}
