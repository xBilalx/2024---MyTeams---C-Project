/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** create
*/

#include "../server.h"

entity_t *entity_list_use2(client_t *client_tcp, char **command,
    int size, user_teams_t *creator)
{
    int fd = client_tcp->_sd_client;
    entity_t *e = NULL;
    entity_t *father = client_tcp->useFeature.entity;

    if (client_tcp->useFeature.usecontext == ContextChannel && size == 3) {
        e = create_entity(command[1], command[2], Tthread, creator);
        server_event_thread_created(father->str_uuid, e->str_uuid,
        creator->str_uuid, e->_name, e->desc);
        dprintf(fd, "11 2 \"%s\" \"%s\" \"%s\" \"%s\" \"%s\"\r\n", e->str_uuid,
            creator->str_uuid, e->date, e->_name, e->desc);
        return e;
    }
    return NULL;
}

entity_t *entity_list_use1(client_t *client_tcp, char **command,
    int size, user_teams_t *creator)
{
    entity_t *e = NULL;
    entity_t *father = client_tcp->useFeature.entity;
    int fd = client_tcp->_sd_client;

    if (client_tcp->useFeature.usecontext == ContextNothing && size == 3) {
        e = create_entity(command[1], command[2], Tteam, creator);
        server_event_team_created(e->str_uuid, e->_name, creator->str_uuid);
        dprintf(fd, "11 0 \"%s\" \"%s\" \"%s\"\r\n",
            e->str_uuid, e->_name, e->desc);
        return e;
    }
    if (client_tcp->useFeature.usecontext == ContextTeam && size == 3) {
        e = create_entity(command[1], command[2], Tchannel, creator);
        server_event_channel_created(father->str_uuid, e->str_uuid, e->_name);
        dprintf(fd, "11 1 \"%s\" \"%s\" \"%s\"\r\n",
            e->str_uuid, e->_name, e->desc);
        return e;
    }
    return entity_list_use2(client_tcp, command, size, creator);
}

bool search_doublon(entity_t *father, char **command, client_t *client_tcp)
{
    entity_t *ent = NULL;

    if (client_tcp->useFeature.usecontext == ContextThread)
        return false;
    for (storage_t *sto = father->list_entity; sto != NULL; sto = sto->next) {
        ent = sto->entity;
        if (strcmp(ent->_name, command[1]) == 0) {
            dprintf(client_tcp->_sd_client, "16 5\r\n");
            return true;
        }
    }
    return false;
}

void entity_list_use(client_t *client_tcp, data_t *data_serv,
    char **command, user_teams_t *creator)
{
    int size = 0;
    entity_t *ent = NULL;
    entity_t *father = client_tcp->useFeature.entity;

    if (search_doublon(father, command, client_tcp))
        return;
    for (; command[size] != NULL; size++);
    ent = entity_list_use1(client_tcp, command, size, creator);
    if (client_tcp->useFeature.usecontext == ContextThread && size == 2) {
        ent = create_entity(NULL, command[1], Tcomment, creator);
        server_event_reply_created(father->str_uuid,
        creator->str_uuid, ent->desc);
        dprintf(client_tcp->_sd_client, "11 3 \"%s\" \"%s\"\"%s\" \"%s\"\r\n",
            ent->str_uuid, creator->str_uuid, ent->date, ent->desc);
    }
    if (ent == NULL) {
        return;
    }
    display_event_create(data_serv, ent, client_tcp, father);
    add_entity(ent, &father->list_entity);
}

void create(data_t *data_serv, char **command, client_t *client_tcp)
{
    int size = 0;

    if (client_tcp->teams_user == NULL) {
        dprintf(client_tcp->_sd_client, "16 4\r\n");
        return;
    }
    for (; command[size] != NULL; size++);
    entity_list_use(client_tcp, data_serv,
    command, client_tcp->teams_user);
}
