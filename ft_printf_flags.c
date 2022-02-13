/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:00:05 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/13 18:22:05 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void pf_resetdata(struct pf_data *data)
{
    data->width = 0;
    data->is_precision = 0;
    data->is_left_justify = 0;
    data->is_zero = 0;
    data->is_hash = 0;
    data->is_positive_sign = 0;
    data->is_space = 0;
    data->precision = 0;
}

static int  ft_isflag(char format)
{
    if (format == '-' || format == '0' || format == '#' || format == ' ' || format == '+')
        return (1);
    return (0);
}

static void pf_setflagbool(const char *flag, struct pf_data *data)
{
    while (*flag && ft_isflag(*flag))
    {
        if (*flag == '-')
            data->is_left_justify = 1;
        else if (*flag == '0')
            data->is_zero = 1;
        else if (*flag == '#')
            data->is_hash = 1;
        else if (*flag == '+')
            data->is_positive_sign = 1;
        else if (*flag == ' ')
            data->is_space = 1;
        flag++;
    }
}

static void pf_setflagvalue(const char **flag, struct pf_data *data)
{
    while (**flag && ft_isflag(**flag))
        (*flag)++;
    // printf("\nstart flag: %s\n", *flag);
    while (**flag && (ft_isdigit(**flag) || **flag == '.')) {
        // printf("\nstart flag: %s\n", *flag);
        if (**flag == '.')
        {
            data->is_precision = 1;
            (*flag)++;
            if (ft_isdigit(**flag))
            {
                data->precision = ft_atoi(*flag);
                // printf("precision: %d\n", data->precision);
                *flag += ft_digitlen(data->precision);
            }
        }
        else if (!data->width)
        {
            data->width = ft_atoi(*flag);
            // printf("width: %d\n", data->width);
            *flag += ft_digitlen(data->width);
        }
    }
    // printf("final flag: %c\n", **flag);
}

struct pf_data ft_parse_flags(const char **flag)
{
    struct pf_data  data;

    pf_resetdata(&data);
    pf_setflagbool(*flag, &data);
    pf_setflagvalue(flag, &data);
    if (data.is_zero && data.precision)
        data.is_zero = 0;
    return (data);
}