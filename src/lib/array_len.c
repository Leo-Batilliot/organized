/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-organized-leo.batilliot
** File description:
** array_len
*/
#include "../shell.h"

int my_array_len(char **array)
{
    int i = 0;

    if (array == NULL)
        return i;
    for (; array[i] != NULL; i++);
    return i;
}
