/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** send
*/

#include "../server.h"

// void add_message_user(mess_teams *mess, teams_data *data_teams)
// {
//     mess_teams *list_mess = data_teams->messages;

//     if (list_mess == NULL) {
//         data_teams->messages = mess;
//         printf("ICI\n");
//         return;
//     }
//     for (; list_mess != NULL; list_mess = list_mess->next) {
//         if (list_mess->next != NULL)
//             continue;
//         list_mess->next = mess;
//         return;
//     }
// }

// mess_teams *create_mess(char *message, user_teams *sender,user_teams *recip)
// {
//     mess_teams *new_message = malloc(sizeof(mess_teams));

//     new_message->_content = message;
//     new_message->sender = sender;
//     new_message->recipient = recip;
//     new_message->next = NULL;
// }

entity_t *create_mess(char *message, user_teams_t *sender, user_teams_t *recip)
{
    entity_t *new_message = malloc(sizeof(entity_t));
    time_t now;
    struct tm *tm_info;

    time(&now);
    tm_info = localtime(&now);
    new_message->_name = NULL;
    new_message->desc = message;
    new_message->creator = sender;
    new_message->recipient = recip;
    new_message->type_entity = Tmessage;
    new_message->list_entity = NULL;
    strftime(new_message->date, 40, "%d/%m/%Y %H:%M:%S", tm_info);
    uuid_generate(new_message->uuid);
    uuid_unparse(new_message->uuid, new_message->str_uuid);
    return new_message;
}

void send_message_to_recip(entity_t *message, data_t *d, client_t *client_tcp)
{
    client_t *cli_list = d->_client_list;
    int fd = 0;

    for (int i = 0; i < d->_max_client; i++) {
        if (cli_list[i]._sd_client > 0 && cli_list[i].teams_user != NULL
        && cli_list[i].teams_user == message->recipient) {
            fd = cli_list[i]._sd_client;
            dprintf(fd, "14 \"%s\" \"%s\"\r\n", message->creator->str_uuid,
            message->desc);
        }
    }
}

void link_message(char *mess, user_teams_t *recip, data_t *d, client_t *cli)
{
    entity_t *message = NULL;
    user_teams_t *send = cli->teams_user;

    if (send == recip)
        return;
    message = create_mess(mess, send, recip);
    add_entity(message, &send->listMessage);
    add_entity(message, &recip->listMessage);
    server_event_private_message_sended(send->str_uuid, recip->str_uuid,
    message->desc);
    send_message_to_recip(message, d, cli);
}

void send_mess(data_t *data_serv, char **command, client_t *client_tcp)
{
    int size = 0;
    user_teams_t *user_list = data_serv->data_teams->user_list;

    if (client_tcp->teams_user == NULL) {
        dprintf(client_tcp->_sd_client, "16 4\r\n");
        return;
    }
    for (; command[size] != NULL; size++);
    if (size != 3)
        return;
    for (; user_list != NULL; user_list = user_list->next) {
        if (strcmp(command[1], user_list->str_uuid) == 0) {
            link_message(command[2], user_list, data_serv, client_tcp);
            return;
        }
    }
}
