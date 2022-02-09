/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:00:05 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/09 19:00:11 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  ft_isflag(char format)
{
    if (format == '-' || format == '0' || format == '.' || format == '#' || format == ' ' || format == '+')
        return (1);
    return (0;)
}

static char *ft_findflags(char *flagtypes, char *flag)
{
    int i;

    i = 0;
    while (*flag && ft_isflag(*flag))
    {
        i = 0;
        while (flagtypes[i])
        {
            if (*flag == flagtypes[i])
                flagtypes[i] = '1';
            i++;
        }
        flag++;
    }
    if (flagtypes[1] && flagtypes[5])
        flagtypes[1] = '0';
    return (flagtypes);
}

// "-" width: left justify, default is right
// "+" numbers (d, i, u): to show positive sign
// " " numbers (d, i, u): add space instead of positive sign
// "#" hexdecimal (x, X): show 0x or 0X
// "0" width: add 0 instead of space
// "." numbers (d, i, u, x, X): add leading 0's if the value is shorter than the precision number

int ft_parse_flags(char *flag)
{
    int     i;
    char    flagtypes[] = {'-', '0', '.', '#', ' ', '+'};
    int     len;

    flagtypes = ft_findflags(&flagtypes[0], flag);
    if (flagtypes[0] == '-')
    {
        
    }
    if (flagtypes[1] == '0')
    {
        
    }
    if (flagtypes[2] == )
    {
        
    }
    if (flagtypes[3] == )
    {
        
    }
    if (flagtypes[4] == )
    {
        
    }
    if (flagtypes[5] == )
    {
        
    }
    return (len);
}