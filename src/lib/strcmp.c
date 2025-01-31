/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-organized-leo.batilliot
** File description:
** strcmp
*/
#include "../shell.h"

int my_strcmp(char *str, char *res)
{
    if (str == NULL || res == NULL)
        return 84;
    if (my_strlen(str) != my_strlen(res))
        return 84;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != res[i])
            return (str[i] - res[i]);
    return 0;
}

int my_stralphacmp(const char *str, const char *res)
{
    if (str == NULL || res == NULL)
        return 84;
    for (int i = 0; str[i] != '\0' || res[i] != '\0'; i++)
        if (str[i] != res[i])
            return (str[i] - res[i]);
    return 0;
}
