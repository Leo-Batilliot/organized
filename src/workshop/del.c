/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-organized-leo.batilliot
** File description:
** delete
*/
#include "../shell.h"

int get_number(char *str)
{
    int res = 0;

    if (str == NULL)
        return -84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > '9' || str[i] < '0')
            return -84;
        res = res * 10 + (str[i] - 48);
    }
    return res;
}

int delete_node(node_t *current, node_t *previous, linked_list_t *list, int a)
{
    if (current->ID == a) {
        mini_printf(1, "%s n°%d - \"%s\" deleted.\n",
            current->type, current->ID, current->name);
        previous->next = current->next;
        free_node(current);
        return 0;
    }
    return 84;
}

int delete_loop(linked_list_t *list, int arg)
{
    node_t *current = list->head;
    node_t *previous = NULL;

    if (list->head->ID == arg) {
        mini_printf(1, "%s n°%d - \"%s\" deleted.\n",
            current->type, current->ID, current->name);
        previous = list->head;
        list->head = list->head->next;
        free_node(previous);
        return 0;
    }
    for (int i = 0; i >= 0; i++) {
        if (!current)
            return 84;
        if (delete_node(current, previous, list, arg) == 0)
            return 0;
        previous = current;
        current = current->next;
    }
}

int del(void *data, char **args)
{
    int arg = 0;
    linked_list_t *list = data;

    if (list->head == NULL || args[0] == NULL)
        return 84;
    for (int y = 0; args[y] != NULL; y++) {
        arg = get_number(args[y]);
        if (arg == -84)
            return 84;
        if (delete_loop(list, arg) == 84)
            return 84;
    }
    return 0;
}
