/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_
    #include <stdio.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <time.h>
    #include <sys/select.h>
    #include "../../libs/myteams/logging_client.h"
    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

char **split_command1(const char *command);
int error_handling(int num, char *msg);
int help_message(void);
int open_tcp(char *port, char *ip);
int find_commande(char *cmd);
char **split_cmd(char *str);
int ask_status_to_serv(char *username);
int ask_uuid_to_serve(char *username);
char **split_command(const char *command);
time_t str_to_time_t(char *time_string);
size_t tablen(char **table);
char **split_msg(char *command);
void read_rep(char *rep);
char *concatstr(char **strings);
char *strptime(const char *s, const char *format, struct tm *tm);
void free_char_array(char **array);
void serveur_request(int fd, char **cmd, int *lencmd);
char *concatstr_without_first(char **strings);
char **split_command_quote(char *command);
struct client_t {
    int socket;
    int status;
    char *username;
    char *uuid;
};
extern struct client_t globalConstClient;
int help(char **);
int login(char **);
int logout(char **);
int users(char **);
int user(char **);
int send_msg(char **);
int messages(char **);
int subscribe(char **);
int subscribed(char **);
int unsubscribes(char **);
int create(char **);
int use(char **);
int list(char **);
int error(char **);
int message_recieve(char **);
int event(char **po);
int info(char **inf);

int ask_for_login(char *);
int ask_for_logout(char *);
int ask_for_users(char *);
int ask_for_user(char *);
int ask_for_send_msg(char *);
int ask_for_messages(char *);
int ask_for_subscribe(char *);
int ask_for_subscribed(char *);
int ask_for_unsubscribes(char *);
int ask_for_create(char *);
int ask_for_use(char *);
int ask_for_list(char *);
int ask_for_error(char *);
int ask_for_message_recieve(char *);
int ask_for_info(char *username);
int ask_for_help(char *);
extern const int (*func_ptr[17])(char **);
extern const int (*func_ask_ptr[15])(char *);
extern const char *str_cmd[14];
#endif /* !CLIENT_H_ */
