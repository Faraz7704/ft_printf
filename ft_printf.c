/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:30:01 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/07 20:33:21 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int    pf_lconvert(va_list ap, char format)
{
    int len;

    //printf("format: %c\n", format);
    //printf("av: %i\n", (int)va_arg(ap, int));
    len = 0;
    if (format == 'c' || format == '%')
        len = ft_putlchar_fd((char)va_arg(ap, int), 1);
    else if (format == 's')
        len = ft_putlstr_fd((char *)va_arg(ap, char *), 1);
    else if (format == 'p')
    {
        len = ft_putlstr_fd("0x10", 1);
        len += ft_putlhex_fd((int)va_arg(ap, int), 1, 0);
    }
    else if (format == 'd' || format == 'i')
        len = ft_putlnbr_fd((int)va_arg(ap, int), 1);
    else if (format == 'u')
        len = ft_putlunbr_fd((int)va_arg(ap, int), 1);
    else if (format == 'x')
        len = ft_putlhex_fd((int)va_arg(ap, int), 1, 0);
    else if (format == 'X')
        len = ft_putlhex_fd((int)va_arg(ap, int), 1, 1);
    //printf("len: %i\n", len);
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
            len += pf_lconvert(ap, *++str);
        else
            len += ft_putlchar_fd(*str, 1);
        str++;
    }
    va_end(ap);
    return (len);
}

int main(void)
{
    char *str = "more message";
    int ft_res = ft_printf("ft_printf: %p\n", str);
    int res = printf("printf: %p\n", str);
    printf("ft_res: %d\nres: %d\n", ft_res - 3, res);
    return (0);
}