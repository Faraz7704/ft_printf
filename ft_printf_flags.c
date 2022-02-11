/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:00:05 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/11 22:55:45 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  ft_isflag(char format)
{
    if (format == '-' || format == '0' || format == '.' || format == '#' || format == ' ' || format == '+')
        return (1);
    return (0);
}

struct pf_data ft_parse_flags(char *flag)
{
    struct pf_data  data;

    // data = (pf_data)malloc(sizeof(pf_data));
    // if (!data)
    //     return (NULL);
    while (*flag && (ft_isflag(*flag) || ft_isdigit(*flag)))
    {
        data.is_left_justify = *flag == '-';
        data.is_zero = *flag == '0';
        data.is_hash = *flag == '#';
        data.is_positive_sign = *flag == '+';
        data.is_space = *flag == ' ';
        data.precision = *flag == '.';
        if (ft_isdigit(*flag))
        {
            if (!data.precision)
                data.width = ft_atoi(flag);
            else
                data.precision = ft_atoi(flag);
            flag += ft_digitlen(data.width);
        }
        else
            flag++;
    }
    return (data);
}