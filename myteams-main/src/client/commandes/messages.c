/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** messages
*/

#include "../client.h"

char **split_msg(char *command)
{
    char **array = malloc(sizeof(char *));
    int command_count = 0;
    char *str = strtok(command, " ");

    while (str != NULL) {
        array = realloc(array, sizeof(char *) * (command_count + 1));
        array[command_count] = malloc(sizeof(char) * (strlen(str) + 1));
        strcpy(array[command_count], str);
        command_count++;
        str = strtok(NULL, " ");
    }
    array = realloc(array, sizeof(char *) * (command_count + 1));
    array[command_count] = NULL;
    return array;
}

int messages(char **res)
{
    int n = 0;
    char *concat = malloc(sizeof(char) * strlen(res[1]) + strlen(res[2]) + 2);

    client_private_message_print_messages(res[1],
        str_to_time_t(res[2]), res[3]);
    return 1;
}

int ask_for_messages(char *inf)
{
    char buffer[MAX_BODY_LENGTH + 4];

    snprintf(buffer, sizeof(buffer) + 6, "5 %s\r\n", inf);
    write(globalConstClient.socket, buffer, strlen(buffer));
    return 1;
}

int ask_for_message_recieve(char *msg)
{
    return 0;
}

int message_recieve(char **res)
{
    client_event_private_message_received(res[1], res[2]);
    free(res);
    return 1;
}
