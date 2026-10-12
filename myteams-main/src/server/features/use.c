/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** use
*/

#include "../server.h"

int upgrade_context(entity_t *entity, useFeature_t *useFeature, char *str_uuid)
{
    if (strcmp(entity->str_uuid, str_uuid) == 0) {
        if (useFeature->usecontext == ContextThread)
            return 1;
        useFeature->usecontext++;
        useFeature->entity = entity;
    }
    return 0;
}

void search_uuid_storage(useFeature_t *useFeature, char *str_uuid)
{
    entity_t *entity = NULL;
    storage_t *storage = useFeature->entity->list_entity;

    for (; storage != NULL; storage = storage->next) {
        entity = storage->entity;
        upgrade_context(entity, useFeature, str_uuid);
    }
}

void use(data_t *data_serv, char **command, client_t *client_tcp)
{
    int size = 0;

    if (client_tcp->teams_user == NULL) {
        dprintf(client_tcp->_sd_client, "16 4\r\n");
        return;
    }
    for (; command[size] != NULL; size++);
    if (size == 1) {
        client_tcp->useFeature.entity = data_serv->data_teams->racine;
        client_tcp->useFeature.usecontext = ContextNothing;
    }
    if (size != 2)
        return;
    search_uuid_storage(&client_tcp->useFeature, command[1]);
}
