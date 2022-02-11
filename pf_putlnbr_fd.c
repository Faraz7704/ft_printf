/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putlnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:32:17 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/11 22:04:53 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pf_putlnbr_fd(int nbr, int fd, struct printf_data data)
{
    int len;
    int preclen;

    len = 0;
    if (data.is_positive_sign)
    {
        write(fd, "+", 1);
        len += 1;
    }
    else if (data.is_space)
    {
        write(fd, " ", 1);
        len += 1;
    }
    len += ft_digitlen(nbr);
    if (!data.is_left_justify)
        len += pf_width(data.width - len, data.is_zero, fd);
    preclen = data.precision - len;
    while (preclen > 0)
    {
        write(fd, "0", 1);
        preclen--;
        len++;
    }
    ft_putnbr_fd(nbr, fd);
    if (data.is_left_justify)
        len += pf_width(data.width - len, data.is_zero, fd);
    return (len);
}