/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdarg.h>

typedef struct node {
    char *type;
    char *name;
    unsigned int ID;
    struct node *next;
} node_t;

typedef struct linked_list {
    node_t *head;
    int nb;
} linked_list_t;

int my_array_len(char **array);
int my_strcmp(char *str, char *res);
int my_strlen(char *str);
char *my_strdup(char *str);
void free_node(node_t *node);
void free_list(linked_list_t *list);
int add_node(char *, char *, linked_list_t *);
int main(int, char **);
int add(void *data, char **args);
int del(void *data, char **args);
int sort(void *data, char **args);
int disp(void *data, char **args);
int mini_printf(int output, char *format, ...);
int workshop_shell(void *data);
linked_list_t *init_list(void);
node_t *reverse_list(node_t *head);
int my_stralphacmp(const char *str, const char *res);
node_t *merge_sort(node_t *head, char *criteria, char **conds);
node_t *merge_sorted(node_t *a, node_t *b, char *criteria, char **conds);
int prev_conds(node_t *a, node_t *b, char **conds);
int compare_nodes(node_t *a, node_t *b, char *criteria);


#endif /* SHELL_H */
