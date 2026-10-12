/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** user
*/

#include "server.h"

user_teams_t *user_exist(char *name, teams_data_t *data_teams)
{
    user_teams_t *head = data_teams->user_list;

    for (; head != NULL; head = head->next) {
        if (strcmp(name, head->_name) == 0)
            return head;
    }
    return NULL;
}

user_teams_t *return_user(teams_data_t *data_teams, user_teams_t *head,
    user_teams_t *new_user)
{
    if (data_teams->user_list == NULL) {
        data_teams->user_list = new_user;
        return new_user;
    }
    for (; head != NULL; head = head->next) {
        if (head->next != NULL)
            continue;
        head->next = new_user;
        return new_user;
    }
}

user_teams_t *create_user(char *name, teams_data_t *data_teams)
{
    user_teams_t *new_user = malloc(sizeof(user_teams_t));
    user_teams_t *head;
    time_t now;
    struct tm *tm_info;

    time(&now);
    tm_info = localtime(&now);
    head = data_teams->user_list;
    strftime(new_user->date, 40, "%d/%m/%Y %H:%M:%S", tm_info);
    new_user->_name = name;
    new_user->listMessage = NULL;
    new_user->next = NULL;
    uuid_generate(new_user->uuid);
    uuid_unparse(new_user->uuid, new_user->str_uuid);
    server_event_user_created(new_user->str_uuid, new_user->_name);
    return return_user(data_teams, head, new_user);
}
