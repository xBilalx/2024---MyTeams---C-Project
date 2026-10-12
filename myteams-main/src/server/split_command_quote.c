/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** split_commande_quote
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct data_split {
    char **array;
    int command_count;
    int in_quote;
};

void add_to_array(char *str_start, char *str_end, struct data_split *d)
{
    int size_word = str_end - str_start;
    char *word = strndup(str_start, size_word);

    if (word[strlen(word) - 1] == '\"')
        word[strlen(word) - 1] = '\0';
    d->array = realloc(d->array, sizeof(char **) * (d->command_count + 1));
    d->array[d->command_count] = word;
    d->command_count++;
}

void ato_boucle(char *command, int i, char *start, struct data_split *d)
{
    if (((command + i)) != start)
        add_to_array(start, (command + i), d);
}

void if_first_quote(struct data_split *d, char *command, int i, char **start)
{
    if (d->in_quote && *(command + i) != '\0')
        *start = (command + i) + 1;
}

char **split_command_quote(char *command)
{
    struct data_split d = {malloc(sizeof(char *)), 0, 0};
    int i = 0;
    char *start = command;

    for (i = 0; *(command + i); i++) {
        if ((*(command + i)) == '\"') {
            d.in_quote = !d.in_quote;
            if_first_quote(&d, command, i, &start);
        }
        if ((*(command + i)) == ' ' && !d.in_quote) {
            ato_boucle(command, i, start, &d);
            start = (command + i) + 1;
        }
    }
    if (((command + i)) != start)
        add_to_array(start, (command + i), &d);
    d.array = realloc(d.array, sizeof(char *) * (d.command_count + 1));
    d.array[d.command_count] = NULL;
    return d.array;
}
