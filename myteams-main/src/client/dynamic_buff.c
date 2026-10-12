/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** dynamic_buff
*/

#include "client.h"

static void process_command(int fd, char **cmd, int *lencmd)
{
    int size_commande = 0;
    char *pointeur = strstr(*cmd, "\r\n");

    if (pointeur == NULL) {
        return;
    }
    while (pointeur != NULL) {
        *pointeur = '\0';
        read_rep(*cmd);
        size_commande = (pointeur - *cmd) + 2;
        *lencmd -= size_commande;
        memmove(*cmd, pointeur + 2, *lencmd + 1);
        *cmd = realloc(*cmd, *lencmd + 1);
        if (*cmd == NULL)
            perror("Realloc error");
        pointeur = strstr(*cmd, "\r\n");
    }
}

static int dynamic_buff(int fd, char **cmd, int *lencmd)
{
    int read_max = 100;
    char buff[read_max];
    int con = 0;

    bzero(buff, read_max);
    con = read(fd, buff, read_max);
    if (con <= 0)
        return 0;
    *cmd = realloc(*cmd, *lencmd + con + 1);
    memcpy(*cmd + *lencmd, buff, con);
    *lencmd = *lencmd + con;
    (*cmd)[*lencmd] = '\0';
    return 1;
}

void serveur_request(int fd, char **cmd, int *lencmd)
{
    dynamic_buff(fd, cmd, lencmd);
    process_command(fd, cmd, lencmd);
}
