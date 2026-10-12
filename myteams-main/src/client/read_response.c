/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** read_response
*/

#include "client.h"

char **split_command1(const char *command)
{
    char **array = malloc(sizeof(char *));
    int command_count = 0;
    char *str = strtok((char *)command, " ");

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

static int (*match_rep(char *cmd))(char **)
{
    int i = 0;

    while (i < 17) {
        if (atoi(cmd) == i)
            return func_ptr[i];
        i++;
    }
    return 0;
}

static int fcm(char *cmd)
{
    char **cmd_splited = split_command_quote(cmd);
    int(*res)(char **) = match_rep(cmd_splited[0]);
    char *str = NULL;

    if (res != 0) {
        return res(cmd_splited);
    }
    return 1;
}

void read_rep(char *rep)
{
    fcm(rep);
}
