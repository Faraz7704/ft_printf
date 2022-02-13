/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:30:01 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/13 19:15:47 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// %[flags][width][.precision]specifier

// "-" width: left justify, default is right [DONE]
// "+" numbers (d, i, u): to show positive sign [DONE]
// " " numbers (d, i, u): add space instead of positive sign [DONE]
// "#" hexdecimal (x, X): show 0x or 0X [DONE]
// "0" width: add 0 instead of space [DONE]
// "." numbers (d, i, u, x, X): add leading 0's if the value is shorter than the precision number [DONE]

static int    parse_printf(va_list ap, const char **format, int fd)
{
    int len;
    
    struct pf_data data = ft_parse_flags(format);
    // printf("\nformat: %c\n", **format);
    len = 0;
    // write(1, "|", 1);
    if (**format == 'c')
        len = pf_putlchar_fd((char)va_arg(ap, int), fd, data);
    else if (**format == 's')
        len = pf_putlstr_fd((char *)va_arg(ap, char *), fd, data);
    else if (**format == 'p')
        len += pf_putlptr_fd((unsigned long long)va_arg(ap, unsigned long long), fd, data);
    else if (**format == 'd' || **format == 'i')
        len = pf_putlnbr_fd((int)va_arg(ap, int), fd, data);
    else if (**format == 'u')
        len = pf_putlunbr_fd((int)va_arg(ap, int), fd, data);
    else if (**format == 'x' || **format == 'X')
        len = pf_putlhex_fd((int)va_arg(ap, unsigned int), fd, **format == 'X', data);
    else if (**format == '%')
        len = pf_putlchar_fd('%', fd, data);
    // write(1, "|", 1);
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
        {
            str++;
            len += parse_printf(ap, &str, 1);
        }
        else
            len += write(1, str, 1);
        str++;
    }
    va_end(ap);
    return (len);
}

// int main(void)
// {
//     int ft_res = ft_printf("%01.2d", 0);
//     printf("\n");
//     int res = printf("%01.2d", 0);
//     printf("\n");
//     printf("ft_res: %d\nres: %d\n", ft_res, res);
//     return (0);
// }