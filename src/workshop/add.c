/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-organized-leo.batilliot
** File description:
** add
*/
#include "../shell.h"

int incorrect_add_type(char *str)
{
    if (my_strcmp(str, "WIRE") == 0 ||
        my_strcmp(str, "ACTUATOR") == 0 ||
        my_strcmp(str, "DEVICE") == 0 ||
        my_strcmp(str, "PROCESSOR") == 0 ||
        my_strcmp(str, "SENSOR") == 0)
        return 0;
    return 84;
}

int add(void *data, char **args)
{
    if (args[0] == NULL)
        return 84;
    for (int i = 0; args[i + 1] != NULL; i++) {
        if (i % 2 != 0)
            continue;
        if (incorrect_add_type(args[i]) == 84)
            return 84;
        if (add_node(args[i], args[i + 1], data) == 84)
            return 84;
    }
    if (my_array_len(args) % 2 != 0)
        return 84;
    return 0;
}
