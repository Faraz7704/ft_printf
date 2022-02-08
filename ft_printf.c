/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:30:01 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/08 23:02:49 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h>

static int  pf_parseflags(va_list ap, char format)
{
    if ()
    return (0);
}

static int    pf_parse(va_list ap, char format)
{
    int len;

    // printf("format: %c\n", format);
    //printf("av: %i\n", (int)va_arg(ap, int));
    len = 0;
    if (format == 'c')
        len = ft_putlchar_fd((char)va_arg(ap, int), 1);
    else if (format == 's')
        len = ft_putlstr_fd((char *)va_arg(ap, char *), 1);
    else if (format == 'p')
        len += ft_putlptr_fd((unsigned long long)va_arg(ap, unsigned long long), 1);
    else if (format == 'd' || format == 'i')
        len = ft_putlnbr_fd((int)va_arg(ap, int), 1);
    else if (format == 'u')
        len = ft_putlunbr_fd((int)va_arg(ap, int), 1);
    else if (format == 'x')
        len = ft_putlhex_fd((int)va_arg(ap, unsigned int), 1, 0);
    else if (format == 'X')
        len = ft_putlhex_fd((int)va_arg(ap, unsigned int), 1, 1);
    else if (format == '%')
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
        {
            str = ft_rm_whitespace(++str);
            len += pf_parse(ap, *str);
            str = ft_rm_whitespace(++str);
            len += pf_parse(ap, *str);
        }
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