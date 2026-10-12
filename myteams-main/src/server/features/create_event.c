/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** create_event
*/

#include "../server.h"

void display_event_create1(client_t *cli, entity_t *e, entity_t *father,
    client_t *cli_tcp)
{
    int fd = 0;

    fd = cli->_sd_client;
    if (cli_tcp->useFeature.usecontext == ContextNothing)
        dprintf(fd, "15 0 \"%s\" \"%s\" \"%s\"\r\n", e->str_uuid,
            e->_name, e->desc);
    if (cli_tcp->useFeature.usecontext == ContextTeam)
        dprintf(fd, "15 1 \"%s\" \"%s\" \"%s\"\r\n", e->str_uuid,
            e->_name, e->desc);
    if (cli_tcp->useFeature.usecontext == ContextChannel)
        dprintf(fd, "15 2 \"%s\" \"%s\" \"%s\" \"%s\" \"%s\"\r\n", e->str_uuid,
            e->creator->str_uuid, e->date, e->_name, e->desc);
    if (cli_tcp->useFeature.usecontext == ContextThread)
        dprintf(fd, "15 3 \"%s\" \"%s\" \"%s\" \"%s\"\r\n", "N/C",
            e->str_uuid, e->creator->str_uuid, e->desc);
}

void display_event_create(data_t *d, entity_t *ent, client_t *cli_tcp,
    entity_t *father)
{
    client_t *cli_list = d->_client_list;
    int fd = 0;

    for (int i = 0; i < d->_max_client; i++) {
        if (cli_list[i]._sd_client > 0)
            display_event_create1(&cli_list[i], ent, father, cli_tcp);
    }
}
