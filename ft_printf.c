/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:30:01 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/09 17:01:41 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h>

static int parse_wp(va_list ap, char** format)
{
    int len;
    char *flags;

    len = 0;
    while (*format && is_flag(**format))
    {
        if (**format == '#')
        {
            ft_putlchar_fd('%', 1);
        }
    }
    return (len);
}

static int    parse_printf(va_list ap, char *format)
{
    int len;
    
    // printf("format: %c\n", format);
    //printf("av: %i\n", (int)va_arg(ap, int));
    len = parse_wp(ap, &format);
    if (*format == 'c')
        len = ft_putlchar_fd((char)va_arg(ap, int), 1);
    else if (*format == 's')
        len = ft_putlstr_fd((char *)va_arg(ap, char *), 1);
    else if (*format == 'p')
        len += ft_putlptr_fd((unsigned long long)va_arg(ap, unsigned long long), 1);
    else if (*format == 'd' || format == 'i')
        len = ft_putlnbr_fd((int)va_arg(ap, int), 1);
    else if (*format == 'u')
        len = ft_putlunbr_fd((int)va_arg(ap, int), 1);
    else if (*format == 'x')
        len = ft_putlhex_fd((int)va_arg(ap, unsigned int), 1, 0);
    else if (*format == 'X')
        len = ft_putlhex_fd((int)va_arg(ap, unsigned int), 1, 1);
    else if (*format == '%')
        len = ft_putlchar_fd('%', 1);
    return (len);
}

int ft_printf(const char *str, ...)
{
    int     len;
    va_list ap;
    
    len = 0;
    va_start(ap, str);
    while (*str)
    {
        if (*str == '%')
            len += parse_printf(ap, *(++str));
        else
            len += ft_putlchar_fd(*str, 1);
        str++;
    }
    va_end(ap);
    return (len);
}

// int main(void)
// {
//     int ft_res = ft_printf("% d", (int)-2147483648);
//     printf("\n");
//     int res = printf("% d", (int)-2147483648);
//     printf("\n");
//     printf("ft_res: %d\nres: %d\n", ft_res, res);
//     return (0);
// }