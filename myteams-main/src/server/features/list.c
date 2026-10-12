/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** list
*/

#include "../server.h"

void display_list_of(client_t *cli, entity_t *father, entity_t *ent)
{
    int fd = cli->_sd_client;

    if (cli->useFeature.usecontext == ContextNothing)
        dprintf(fd, "12 0 \"%s\" \"%s\" \"%s\"\r\n", ent->str_uuid,
            ent->_name, ent->desc);
    if (cli->useFeature.usecontext == ContextTeam)
        dprintf(fd, "12 1 \"%s\" \"%s\" \"%s\"\r\n", ent->str_uuid,
            ent->_name, ent->desc);
    if (cli->useFeature.usecontext == ContextChannel)
        dprintf(fd, "12 2 \"%s\" \"%s\" \"%s\" \"%s\" \"%s\"\r\n",
            ent->str_uuid,
            ent->creator->str_uuid, ent->date, ent->_name, ent->desc);
    if (cli->useFeature.usecontext == ContextThread)
        dprintf(fd, "12 2 \"%s\" \"%s\" \"%s\" \"%s\"", "N/C\r\n",
            ent->creator->str_uuid, ent->date, ent->desc);
}

void display_list(client_t *client_tcp, teams_data_t *data, char **command)
{
    int size = 0;
    entity_t *father = client_tcp->useFeature.entity;
    storage_t *storage = father->list_entity;
    entity_t *entity = NULL;

    if (father->list_entity == NULL)
        return;
    for (; storage != NULL; storage = storage->next) {
        entity = storage->entity;
        display_list_of(client_tcp, father, entity);
    }
}

void list(data_t *data_serv, char **command, client_t *client_tcp)
{
    int size = 0;

    if (client_tcp->teams_user == NULL) {
        dprintf(client_tcp->_sd_client, "16 4\r\n");
        return;
    }
    for (; command[size] != NULL; size++);
    display_list(client_tcp, data_serv->data_teams, command);
}
