/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-organized-leo.batilliot
** File description:
** main
*/
#include "shell.h"

int main(int ac, char **av)
{
    int res;
    linked_list_t *list = init_list();

    if (!list || list == NULL)
        return 84;
    res = workshop_shell(list);
    free_list(list);
    if (res == 84)
        return 84;
    return 0;
}
