/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-organized-leo.batilliot
** File description:
** sorting_algorythm
*/
#include "../shell.h"

int compare_nodes(node_t *a, node_t *b, char *criteria)
{
    if (my_strcmp(criteria, "TYPE") == 0)
        return my_stralphacmp(a->type, b->type);
    if (my_strcmp(criteria, "NAME") == 0)
        return my_stralphacmp(a->name, b->name);
    if (my_strcmp(criteria, "ID") == 0)
        return (a->ID - b->ID);
    return 0;
}

int prev_conds(node_t *a, node_t *b, char **conds)
{
    int total = 0;

    for (int i = 0; conds[i] != NULL; i++) {
        if (my_strcmp(conds[i], "TYPE") == 0)
            total += my_stralphacmp(a->type, b->type);
        if (my_strcmp(conds[i], "NAME") == 0)
            total += my_stralphacmp(a->name, b->name);
        if (total != 0)
            return 1;
    }
    return 0;
}

node_t *merge_sorted(node_t *a, node_t *b, char *criteria, char **conds)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    if (conds[0] != NULL && prev_conds(a, b, conds) != 0) {
        a->next = merge_sorted(a->next, b, criteria, conds);
        return a;
    }
    if (compare_nodes(a, b, criteria) <= 0) {
        a->next = merge_sorted(a->next, b, criteria, conds);
        return a;
    } else
        b->next = merge_sorted(a, b->next, criteria, conds);
    return b;
}

node_t *merge_sort(node_t *head, char *criteria, char **conds)
{
    node_t *left;
    node_t *right;
    node_t *mid;
    node_t *slow;
    node_t *fast;

    if (!head || !head->next)
        return head;
    slow = head;
    fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    mid = slow->next;
    slow->next = NULL;
    left = merge_sort(head, criteria, conds);
    right = merge_sort(mid, criteria, conds);
    return merge_sorted(left, right, criteria, conds);
}

node_t *reverse_list(node_t *head)
{
    node_t *prev = NULL;
    node_t *current = head;
    node_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
