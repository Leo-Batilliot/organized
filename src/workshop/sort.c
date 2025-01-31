/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-organized-leo.batilliot
** File description:
** sort
*/
#include "../shell.h"

char **get_conditions_by_level(char **array)
{
    int count = 0;
    char **res = malloc(sizeof(char *) * (my_array_len(array) + 1));

    if (!res)
        return NULL;
    for (int i = 0; array[i] != NULL; i++) {
        if (my_strcmp(array[i], "ID") == 0) {
            res[count] = array[i];
            res[count + 1] = NULL;
            return res;
        }
        if (my_strcmp(array[i], "-r") != 0) {
            res[count] = array[i];
            count++;
        }
    }
    res[count] = NULL;
    return res;
}

int sort_by_level(linked_list_t *list, char **args)
{
    char **conditions = get_conditions_by_level(args);
    char *conditions_done[3] = {NULL, NULL, NULL};

    if (!conditions)
        return 84;
    for (int i = 0; conditions[i] != NULL; i++) {
        list->head = merge_sort(list->head, conditions[i], conditions_done);
        conditions_done[i] = conditions[i];
    }
    free(conditions);
    return 0;
}

int valid_args(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        if (my_strcmp(array[i], "NAME") != 0 &&
            my_strcmp(array[i], "TYPE") != 0 &&
            my_strcmp(array[i], "-r") != 0 &&
            my_strcmp(array[i], "ID") != 0)
            return 84;
    return 0;
}

int sort(void *data, char **args)
{
    linked_list_t *list;
    int reverse = 0;

    if (data == NULL || args[0] == NULL)
        return 84;
    if (valid_args(args) == 84)
        return 84;
    list = (linked_list_t *)data;
    if (list->head == NULL)
        return 84;
    for (int i = 0; args[i] != NULL; i++)
        if (my_stralphacmp(args[i], "-r") == 0)
            reverse = 1;
    if (sort_by_level(list, args) == 84)
        return 84;
    if (reverse)
        list->head = reverse_list(list->head);
    return 0;
}
