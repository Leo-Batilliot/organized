/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-organized-leo.batilliot
** File description:
** disp
*/
#include "../shell.h"

int disp(void *data, char **args)
{
    node_t *node = ((linked_list_t *)data)->head;

    if (args[0] != NULL) {
        mini_printf(2, "disp does not take arguments\n");
        return 84;
    }
    if (node == NULL) {
        mini_printf(2, "No hardware to be displayed\n");
        return 0;
    }
    while (node != NULL) {
        mini_printf(1, "%s n°%d - \"%s\"\n", node->type, node->ID, node->name);
        node = node->next;
    }
    return 0;
}
