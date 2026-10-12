/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** entity
*/

#include "../server.h"

void add_entity(entity_t *entity, storage_t **head)
{
    storage_t *new_storage = malloc(sizeof(storage_t));
    storage_t *list;

    new_storage->entity = entity;
    new_storage->next = NULL;
    if (*head == NULL) {
        *head = new_storage;
        return;
    }
    list = *head;
    for (; list != NULL; list = list->next) {
        if (list->next != NULL)
            continue;
        list->next = new_storage;
        return;
    }
}
