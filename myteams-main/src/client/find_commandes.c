/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** find_commandes
*/

#include "client.h"

char **split_command(const char *command)
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
    array = realloc(array, sizeof(char *) * (command_count + 2));
    array[command_count] = strdup(" ");
    command_count++;
    array[command_count] = NULL;
    return array;
}

static int (*match_cmd(char *cmd))(char *)
{
    int i = 0;

    if (cmd == NULL)
        return 0;
    while (i < 14) {
        if (strcmp(cmd, str_cmd[i]) == 0)
            return func_ask_ptr[i];
        i++;
    }
    return 0;
}

char *concatstr(char **strings)
{
    int num_strings = tablen(strings);
    int total_length = 1;
    int i = 0;
    char *result;

    if (num_strings == 1)
        return strings[0];
    for (i = 0; i < num_strings; i++) {
        total_length += strlen(strings[i]) + 1;
    }
    result = (char *)malloc(total_length * sizeof(char));
    result[0] = '\0';
    for (i = 0; i < num_strings; i++) {
        strcat(result, strings[i]);
        if (i < num_strings - 1)
            strcat(result, " ");
    }
    return result;
}

char *concatstr_without_first(char **strings)
{
    int num_strings = tablen(strings);
    int total_length = 1;
    int i = 0;
    char *result;

    if (num_strings <= 1)
        return NULL;
    for (i = 1; i < num_strings; i++) {
        total_length += strlen(strings[i]) + 1;
    }
    result = (char *)malloc(total_length * sizeof(char));
    result[0] = '\0';
    for (i = 1; i < num_strings; i++) {
        strcat(result, strings[i]);
        if (i < num_strings - 1)
            strcat(result, " ");
    }
    return result;
}

int find_commande(char *cmd)
{
    char **cmd_splited = split_command(cmd);
    int(*res)(char *) = match_cmd(cmd_splited[0]);
    char *cmd_without_first = concatstr_without_first(cmd_splited);
    int result = 0;

    if (res != NULL && cmd_without_first != NULL &&
        strlen(cmd_without_first) <= MAX_BODY_LENGTH) {
        result = res(cmd_without_first);
        return result;
    }
    return 1;
}
