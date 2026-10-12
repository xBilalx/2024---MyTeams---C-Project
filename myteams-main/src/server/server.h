/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <strings.h>
    #include <unistd.h>
    #include <arpa/inet.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <stdbool.h>
    #include <netinet/in.h>
    #include <sys/time.h>
    #include <asm-generic/socket.h>
    #define REP_200 "200 Command okay.\n"
    #define REP_220 "220 Service ready for new user.\n"
    #define REP_221 "221 Service closing control connection.\n"
    #define REP_230 "230 User logged in, proceed.\n"
    #define REP_250 "250 Requested file action okay, completed.\n"
    #define REP_331 "331 Please specify the password.\n"
    #define REP_421 "421 Service not available, closing control connection.\n"
    #define REP_425 "425 Can't open data connection.\n"
    #define REP_4251 "425 Can't open data connection.\n"
    #define REP_530 "530 Please login with USER and PASS.\n"
    #define REP_500 "500 Syntax error, command unrecognized.\n"
    #define REP_503 "503 Login with USER first.\n"
    #define REP_550 "550 Failed to change directory.\n"
    #include <sys/queue.h>
    #include "data.h"
    #define TAB_FUNC_SIZE 13
    #include "../../libs/myteams/logging_server.h"

enum UseContext {
    ContextNothing,
    ContextTeam,
    ContextChannel,
    ContextThread,
};

typedef struct useFeature_s {
    enum UseContext usecontext;
    storage_t **storage;
    entity_t *entity;
} useFeature_t;

typedef struct clien_s {
    int _sd_client;
    int _sd_data;
    int _id;
    char *_ip;
    char *command1;
    char user[64];
    int len_command;
    int connected;
    int _user_check;
    user_teams_t *teams_user;
    useFeature_t useFeature;
}client_t;

typedef struct data_s {
    struct sockaddr_in _address;
    socklen_t addrlen;
    char *_path;
    fd_set _readfs;
    int _max_client;
    int port_serveur;
    int _master_socket;
    int _max_sd;
    client_t *_client_list;
    teams_data_t *data_teams;
}data_t;

void login(data_t *data_serv, char **command, client_t *client_tcp);
void logout(data_t *data_serv, char **command, client_t *client_tcp);
void users(data_t *data_serv, char **command, client_t *client_tcp);
void user(data_t *data_serv, char **command, client_t *client_tcp);
void send_mess(data_t *data_serv, char **command, client_t *client_tcp);
void messages(data_t *data_serv, char **command, client_t *client_tcp);
void subscribe(data_t *data_serv, char **command, client_t *client_tcp);
void subscibed(data_t *data_serv, char **command, client_t *client_tcp);
void unsubscribes(data_t *data_serv, char **command, client_t *client_tcp);
void use(data_t *data_serv, char **command, client_t *client_tcp);
void create(data_t *data_serv, char **command, client_t *client_tcp);
void list(data_t *data_serv, char **command, client_t *client_tcp);
void info(data_t *data_serv, char **command, client_t *client_tcp);

extern void (*func_ptr[TAB_FUNC_SIZE])(data_t *, char **, client_t *);

void clients_request(int i, data_t *d);
int set_socket(data_t *d);
void init_data_serv(int port, data_t *d, char *path);
int run_serveur(int ar, char *argc[]);
user_teams_t *create_user(char *name, teams_data_t *data_teams);
teams_data_t *init_data_teams(void);
user_teams_t *user_exist(char *name, teams_data_t *data_teams);
bool str_is_nbr(char *str);
void add_entity(entity_t *entity, storage_t **head);
entity_t *create_entity(char *name, char *desc, typeEntity_t type,
    user_teams_t *creator);
void close_client(client_t *client, data_t *d);
void display_event_create(data_t *d, entity_t *ent, client_t *cli_tcp,
    entity_t *father);
void change_tilde_to_space(char **str);
void change_space_to_tilde(char **str);
char **split_command_quote(char *command);

#endif /* !SERVER_HPP_ */
