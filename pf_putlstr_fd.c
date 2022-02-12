/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putlstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:20:40 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/12 02:26:07 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pf_putlstr_fd(char *str, int fd, struct pf_data data)
{
    int len;

    if (!str)
        len = 6;
    else
        len = ft_strlen(str);
    if (!data.is_left_justify)
        len += pf_width(data.width - len, data.is_zero, fd);
    if (!str)
        ft_putstr_fd("(null)", fd);
    else
        ft_putstr_fd(str, fd);
    if (data.is_left_justify)
        len += pf_width(data.width - len, data.is_zero, fd);
    return (len);
}