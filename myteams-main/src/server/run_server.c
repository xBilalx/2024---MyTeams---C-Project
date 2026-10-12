/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** run_server
*/

#include "server.h"

void add_client_to_select(data_t *d)
{
    int sd = 0;

    for (int i = 0; i < d->_max_client; i++) {
        if (d->_client_list[i]._sd_client > 0) {
            FD_SET(d->_client_list[i]._sd_client, &d->_readfs);
        }
        if (d->_client_list[i]._sd_client > d->_max_sd) {
            d->_max_sd = d->_client_list[i]._sd_client;
        }
    }
}

void add_client_to_struct(data_t *d)
{
    int new_socket = 0;

    new_socket = accept(d->_master_socket,
        (struct sockaddr*)&d->_address, &d->addrlen);
    for (int i = 0; i < d->_max_client; i++) {
        if (d->_client_list[i]._sd_client == 0) {
            d->_client_list[i]._sd_client = new_socket;
            return;
        }
    }
    close(new_socket);
}

int run_serveur(int ar, char *argc[])
{
    data_t *d = malloc(sizeof(data_t));
    struct sockaddr_in address;
    fd_set writedfs;

    init_data_serv(atoi(argc[1]), d, argc[2]);
    d->_master_socket = set_socket(d);
    while (1) {
        FD_ZERO(&d->_readfs);
        FD_SET(d->_master_socket, &d->_readfs);
        FD_SET(d->_master_socket, &writedfs);
        if (FD_ISSET(d->_master_socket, &writedfs));
        d->_max_sd = d->_master_socket;
        add_client_to_select(d);
        select(d->_max_sd + 1, &d->_readfs, &writedfs, NULL, NULL);
        if (FD_ISSET(d->_master_socket, &d->_readfs))
            add_client_to_struct(d);
        for (int i = 0; i < d->_max_client; i++)
            clients_request(i, d);
    }
}
