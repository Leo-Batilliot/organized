/*
** EPITECH PROJECT, 2024
** mini printf
** File description:
** mini print f
*/
#include "../shell.h"

int my_putchar(int output, char c)
{
    write(output, &c, 1);
}

int my_putstr(int output, char *str)
{
    int i;

    if (output != 1 && output != 2)
    if (str == NULL)
        return 84;
    for (i = 0; str[i] != '\0'; i = i + 1);
    write(output, str, i);
    return 0;
}

int my_put_nbr(int output, long nb)
{
    char res[1];

    if (nb < 0) {
        my_putstr(output, "-");
        nb = - nb;
    }
    if (nb >= 10) {
        my_put_nbr(output, nb / 10);
    }
    res[0] = nb % 10 + '0';
    my_putstr(output, res);
}

static void process_format(int output, char specifier, va_list ap)
{
    switch (specifier) {
        case 's':
            my_putstr(output, va_arg(ap, char *));
            break;
        case 'd':
            my_put_nbr(output, va_arg(ap, int));
            break;
        case 'i':
            my_put_nbr(output, va_arg(ap, int));
            break;
        case 'c':
            my_putchar(output, (char) va_arg(ap, int));
            break;
        case '%':
            my_putstr(output, "%");
        case 'l':
            my_put_nbr(output, va_arg(ap, long int));
            break;
    }
}

int mini_printf(int output, char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    while (*format) {
        if (*format == '%') {
            format++;
            process_format(output, *format, ap);
            format++;
        } else {
            my_putchar(output, *format);
            format++;
            }
    }
    va_end(ap);
    return 0;
}
