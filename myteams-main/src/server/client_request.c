/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** parth_command
*/

#include "server.h"
#include <ctype.h>

int dynamyc_buf(int fd, client_t *client)
{
    int read_max = 10;
    char *buf[read_max + 1];
    int a = 0;

    memset(buf, 0, read_max + 1);
    a = read(fd, buf, read_max);
    if (a == 0)
        return 1;
    if (a < 0) {
        perror("Read error");
        return 1;
    }
    client->command1 = realloc(client->command1, client->len_command + a + 1);
    if (client->command1 == NULL)
        return 1;
    memcpy(client->command1 + client->len_command, buf, a);
    client->len_command += a;
    client->command1[client->len_command] = '\0';
    return 0;
}

char **split_command(const char *command)
{
    char **array = malloc(sizeof(char *));
    int command_count = 0;
    char *str = strtok((char *)command, " ");

    while (str != NULL) {
        if (str[0] == '"')
            str++;
        if ((str[strlen(str) - 1]) == '"')
            str[strlen(str) - 1] = '\0';
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

int run_command(client_t *client, data_t *d)
{
    char **command = NULL;
    int size = 0;
    int index_command;

    command = split_command_quote(client->command1);
    if (strcasecmp(command[0], "quit") == 0) {
        close_client(client, d);
        return 1;
    }
    for (size = 0; command[size] != NULL; size++);
    if (size <= 0 || str_is_nbr(command[0]))
        return 0;
    index_command = atoi(command[0]);
    if (index_command >= TAB_FUNC_SIZE)
        return 0;
    func_ptr[index_command](d, command, client);
}

void process_command(client_t *client, data_t *d)
{
    int size_commande = 0;
    char *pointeur = strstr(client->command1, "\r\n");

    if (pointeur == NULL) {
        return;
    } else {
        *pointeur = '\0';
        if (run_command(client, d) == 1)
            return;
        size_commande = (pointeur - client->command1) + 2;
        client->len_command -= size_commande;
        memmove(client->command1, pointeur + 2, client->len_command + 1);
        client->command1 = realloc(client->command1, client->len_command + 1);
        if (client->command1 == NULL)
            perror("Realloc error");
    }
}

void clients_request(int i, data_t *d)
{
    int deco = 0;

    if (FD_ISSET(d->_client_list[i]._sd_client, &d->_readfs)) {
        deco = dynamyc_buf(d->_client_list[i]._sd_client, &d->_client_list[i]);
        if (deco) {
            close_client(&d->_client_list[i], d);
            return;
        }
        process_command(&d->_client_list[i], d);
    }
}
