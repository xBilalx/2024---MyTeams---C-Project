/*
** EPITECH PROJECT, 2024
** Epitech [WSL: Ubuntu]
** File description:
** manage_quote
*/

void change_tilde_to_space(char **str)
{
    for (int i = 0; (*str)[i] != '\0'; i++) {
        if ((*str)[i] == '~') {
            (*str)[i] = ' ';
        }
    }
}

void change_space_to_tilde(char **str)
{
    int quote = 0;

    for (int i = 0; (*str)[i] != '\0'; i++) {
        if ((*str)[i] == ' ' && quote == 1) {
            (*str)[i] = '~';
        }
        if ((*str)[i] == '"' && quote == 0) {
            quote = 1;
            continue;
        }
        if ((*str)[i] == '"' && quote == 1)
            quote = 0;
    }
}
