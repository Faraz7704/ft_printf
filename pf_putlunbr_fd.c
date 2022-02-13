/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putlunbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:29:29 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/13 19:44:27 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static unsigned int ft_udigitlen(unsigned int nbr)
{
    int i;

    i = 0;
    if (nbr <= 0)
        i++;
    while (nbr != 0)
    {
        nbr /= 10;
        i++;
    }
    return (i);
}

static void ft_putunbr_fd(unsigned int nbr, int fd)
{
    char    c;
    
	if (nbr / 10)
		ft_putunbr_fd(nbr / 10, fd);
    ft_putchar_fd(c = nbr % 10 + '0', fd);
}

int pf_putlunbr_fd(unsigned int nbr, int fd, struct pf_data data)
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
    if (nbr == 0 && data.is_precision)
        len = 0;
    else
        len += (int)ft_udigitlen(nbr);
    // printf("\nlen: %d\n", len);
    // printf("\ndata.width: %d\n", data.width);
    if (data.is_precision)
    {
        preclen = data.precision - len;
        if (preclen < 0)
            preclen = 0;
    }
    else
        preclen = 0;
    if (!data.is_left_justify)
        len += pf_width(data.width - len - preclen, data.is_zero && nbr != 0, fd);
    while (preclen > 0)
    {
        write(fd, "0", 1);
        preclen--;
        len++;
    }
    if (!data.is_precision || (nbr != 0 && data.is_precision))
        ft_putunbr_fd(nbr, fd);
    if (data.is_left_justify)
        len += pf_width(data.width - len, data.is_zero, fd);
    return (len);
}