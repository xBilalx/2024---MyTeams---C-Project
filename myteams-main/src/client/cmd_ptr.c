/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** cmd_ptr
*/

#include "client.h"

const int (*func_ptr[17])(char **) = {
    help,         // 0
    login,        // 1
    logout,       // 2
    users,        // 3
    user,         // 4
    send_msg,     // 5
    messages,     // 6
    subscribe,    // 7
    subscribed,   // 8
    unsubscribes, // 9
    use,           //10
    create,        //11
    list,          //12
    info,           //13
    message_recieve, //14
    event,           //15
    error,           //16
};

const int (*func_ask_ptr[15])(char *) = {
    ask_for_help,         // 0
    ask_for_login,        // 1
    ask_for_logout,       // 2
    ask_for_users,        // 3
    ask_for_user,         // 4
    ask_for_send_msg,     // 5
    ask_for_messages,     // 6
    ask_for_subscribe,    // 7
    ask_for_subscribed,   // 8
    ask_for_unsubscribes, // 9
    ask_for_use,          //10
    ask_for_create,        //11
    ask_for_list,          //12
    ask_for_info,           //13
    ask_for_message_recieve, //14
};

const char *str_cmd[14] = {
    "/help",
    "/login",
    "/logout",
    "/users",
    "/user",
    "/send",
    "/messages",
    "/subscribe",
    "/subscribed",
    "/unsubscribes",
    "/use",
    "/create",
    "/list",
    "/info",
};
