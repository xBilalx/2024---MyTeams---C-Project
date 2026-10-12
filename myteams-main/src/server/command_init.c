/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** command_init
*/

#include "server.h"

void (*func_ptr[TAB_FUNC_SIZE])(data_t *, char **, client_t *) = {
    login, //0
    logout, //1
    users, //2
    user, //3
    send_mess, //4
    messages, //5
    subscribe, //6
    subscibed, //7
    unsubscribes, //8,
    use, //9
    create, //10
    list, // 11
    info, // 12
};
