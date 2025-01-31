/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-organized-leo.batilliot
** File description:
** linked_list
*/
#include "../shell.h"

char *my_strdup(char *str)
{
    char *res;
    int i = 0;
    int len;

    if (str == NULL)
        return NULL;
    len = my_strlen(str);
    res = malloc(sizeof(char) * (len + 1));
    if (!res || res == NULL)
        return NULL;
    res[len] = '\0';
    for (; i < len; i++)
        res[i] = str[i];
    return res;
}

int add_node(char *type, char *name, linked_list_t *list)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        return 84;
    node->type = my_strdup(type);
    node->name = my_strdup(name);
    if (node->type == NULL || node->name == NULL)
        return 84;
    node->ID = list->nb;
    list->nb++;
    node->next = list->head;
    list->head = node;
    mini_printf(1, "%s n°%d - \"%s\" added.\n",
        node->type, node->ID, node->name);
    return 0;
}

void free_node(node_t *node)
{
    if (node == NULL)
        return;
    free(node->name);
    node->name = NULL;
    free(node->type);
    node->type = NULL;
    free(node);
    return;
}

void free_list(linked_list_t *list)
{
    node_t *current;
    node_t *next = list->head;

    while (next != NULL) {
        current = next;
        next = current->next;
        free_node(current);
    }
    free(list);
}

linked_list_t *init_list(void)
{
    linked_list_t *list = malloc(sizeof(linked_list_t));

    if (!list)
        return NULL;
    list->head = NULL;
    list->nb = 0;
    return list;
}
