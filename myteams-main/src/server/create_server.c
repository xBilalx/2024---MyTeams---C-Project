/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** create_server
*/

#include "server.h"
#include <uuid/uuid.h>

int set_socket(data_t *d)
{
    int sockfd = 0;
    int new_sockfd = 0;
    int opt = 1;
    char buf[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        perror("Socket failed\n"), exit(84);
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
        &opt, sizeof(opt)) == -1)
        perror("SetSocket failed\n"), exit(84);
    if (bind(sockfd, (struct sockaddr*)&d->_address,
        sizeof(d->_address)) == 1)
        perror("Bind failed\n"), exit(84);
    if (listen(sockfd, d->_max_client) == 1)
        perror("Listen failed\n"), exit(84);
    return sockfd;
}

int help_message(void)
{
    printf("USAGE: ./myteams_server port\n\n");
    printf("       port   is the port number on which the ");
    printf("server socket listens.\n");
    return 0;
}

int check_arg(int ar, char *argc[])
{
    int port_num = 0;

    if (ar != 2) {
        help_message();
        return 1;
    }
    port_num = atoi(argc[1]);
    if (port_num < 1 || port_num > 65535) {
        printf("Error: port value is not valide.\n");
        return 1;
    }
    return 0;
}

int main(int ar, char *argc[])
{
    int error = 0;

    error = check_arg(ar, argc);
    if (error)
        return 84;
    run_serveur(ar, argc);
}
