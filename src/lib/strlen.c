/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-organized-leo.batilliot
** File description:
** strlen
*/
#include "../shell.h"

int my_strlen(char *str)
{
    int i = 0;

    if (str == NULL)
        return i;
    for (; str[i] != '\0'; i++);
    return i;
}
