/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** tcp
*/

#include "client.h"


static int create_socket(void)
{
    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_desc == -1) {
        perror("Échec de la création du socket");
    }
    return socket_desc;
}

static int connect_to_server(int socket_desc, const char *port, const char *ip)
{
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
        perror("Adresse IP invalide");
        close(socket_desc);
        return -1;
    }
    if (connect(socket_desc, (struct sockaddr*)&server_addr,
        sizeof(server_addr)) < 0) {
        perror("Échec de la connexion");
        close(socket_desc);
        return -1;
    }
    return socket_desc;
}

int open_tcp(char *port, char *ip)
{
    int connected_socket;
    int socket_desc = create_socket();

    if (socket_desc == -1) {
        return -1;
    }
    connected_socket = connect_to_server(socket_desc, port, ip);
    if (connected_socket == -1) {
        close(socket_desc);
    }
    return connected_socket;
}
