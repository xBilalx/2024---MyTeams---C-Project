/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** team
*/

#include "../server.h"

entity_t *create_entity(char *name, char *desc, typeEntity_t type,
    user_teams_t *creator)
{
    entity_t *new_entity = malloc(sizeof(entity_t));
    time_t now;
    struct tm *tm_info;

    time(&now);
    tm_info = localtime(&now);
    new_entity->_name = name;
    new_entity->type_entity = type;
    new_entity->desc = desc;
    uuid_generate(new_entity->uuid);
    uuid_unparse(new_entity->uuid, new_entity->str_uuid);
    strftime(new_entity->date, 40, "%d/%m/%Y %H:%M:%S", tm_info);
    new_entity->list_entity = NULL;
    new_entity->recipient = NULL;
    new_entity->creator = creator;
    return new_entity;
}
