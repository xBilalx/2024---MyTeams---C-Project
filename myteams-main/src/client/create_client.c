/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** create_client
*/

#include "client.h"

struct client_t globalConstClient = {0, 0, NULL, NULL};

int error_handling(int num, char *msg)
{
    printf("%s", msg);
    return num;
}

int help_message(void)
{
    printf("USAGE: ./myteams_cli ip port\n");
    printf("       ip   is the server ip");
    printf("address on which the server socket listens\n");
    printf("       port is the port number on");
    printf("which the server socket listens\n");
    return 0;
}

static int message_recive_checker(char *reponses)
{
    char **tmp = NULL;
    int res = 0;

    if (strncmp(reponses, "-2", 2) == 0) {
        tmp = split_command(reponses);
        res = client_event_private_message_received(tmp[1], tmp[2]);
    }
    return res;
}

static int read_input(char *buff, int size)
{
    int n = 0;
    char c = ' ';

    bzero(buff, size);
    while (n < size - 1) {
        c = getchar();
        if (c == '\n')
            break;
        buff[n] = c;
        n++;
    }
    buff[n] = '\0';
    return n;
}

int init_select_tab(fd_set *readfds, fd_set *writefds, int socket)
{
    FD_ZERO(&(*readfds));
    FD_SET(socket, &(*readfds));
    FD_SET(STDIN_FILENO, &(*readfds));
    FD_SET(socket, &(*writefds));
    if (FD_ISSET(socket, &(*writefds))) {
    }
}

int init_client(char *port, char *ip)
{
    char buff[512];
    fd_set readfds;
    fd_set writefds;
    char *bf = NULL;
    int bilal = 0;

    (&globalConstClient)->socket = open_tcp(port, ip);
    if (globalConstClient.socket == -1)
        return error_handling(84, "Unable to connect");
    for (;;) {
        init_select_tab(&readfds, &writefds, globalConstClient.socket);
        select(globalConstClient.socket + 1, &readfds, &writefds, NULL, NULL);
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            read_input(buff, sizeof(buff));
            find_commande(buff);
        }
        if (FD_ISSET(globalConstClient.socket, &readfds))
            serveur_request(globalConstClient.socket, &bf, &bilal);
    }
}

int main(int argc, char *argv[])
{
    if (argc == 3)
        return init_client(argv[2], argv[1]);
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        return help_message();
    } else {
        return error_handling(84, "Bad arguments!");
    }
    return 0;
}
