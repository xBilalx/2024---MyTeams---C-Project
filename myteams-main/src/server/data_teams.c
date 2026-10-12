/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** data_teams
*/

#include "server.h"

teams_data_t *init_data_teams(void)
{
    teams_data_t *data_teams = malloc(sizeof(teams_data_t));

    data_teams->racine = malloc(sizeof(entity_t));
    data_teams->racine->type_entity = TRacine;
    data_teams->racine->list_entity = NULL;
    data_teams->racine->creator = NULL;
    data_teams->racine->recipient = NULL;
    data_teams->racine->desc = NULL;
    data_teams->user_list = NULL;
    data_teams->team_list = NULL;
    return data_teams;
}
