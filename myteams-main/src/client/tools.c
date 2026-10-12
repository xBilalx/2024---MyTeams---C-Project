/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** tools
*/

#include "client.h"

size_t tablen(char **table)
{
    size_t count = 0;

    if (table == NULL)
        return 0;
    while (table[count] != NULL) {
        count++;
    }
    return count;
}

time_t str_to_time_t(char *time_string)
{
    struct tm tm;
    time_t res;

    if (strptime(time_string, "%d/%m/%Y %H:%M:%S", &tm) == NULL) {
        printf("Failed to parse time string\n");
        return (time_t)-1;
    }
    res = mktime(&tm);
    if (res == (time_t)-1) {
        printf("Failed to convert time\n");
        return (time_t)-1;
    }
    return res;
}

void free_char_array(char **array)
{
    int i = 0;

    if (array == NULL) {
        return;
    }
    for (i = 0; array[i] != NULL; i++) {
        free(array[i]);
        array[i] = NULL;
    }
    free(array);
    array = NULL;
}
