/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** data
*/

#ifndef DATA_H_
    #define DATA_H_
    #include <uuid/uuid.h>

struct user_teams_s;

typedef struct entity_team_s entity_t;
typedef struct entity_team_storage_s storage_t;
typedef enum typeEntity_s typeEntity_t;
typedef struct user_teams_s user_teams_t;



enum typeEntity_s {
    TRacine,
    Tteam,
    Tchannel,
    Tthread,
    Tcomment,
    Tmessage
};

struct entity_team_storage_s {
    entity_t *entity;
    struct entity_team_storage_s *next;
};

struct entity_team_s {
    char *_name;
    char *desc;
    uuid_t uuid;
    char str_uuid[37];
    user_teams_t *creator;
    user_teams_t *recipient;
    typeEntity_t type_entity;
    storage_t *list_entity;
    char date[32];
};

struct user_teams_s {
    char *_name;
    uuid_t uuid;
    char str_uuid[37];
    storage_t *listMessage;
    struct user_teams_s *next;
    char date[32];
};

typedef struct data_teams_s {
    user_teams_t *user_list;
    storage_t *team_list;
    entity_t *racine;
} teams_data_t;

#endif /* !DATA_H_ */
