/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putlnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:32:17 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/13 00:24:53 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void pf_putnbr_fd(int nbr, int fd)
{
    char    c;

    if (nbr < 0)
        nbr *= -1;
	if (nbr / 10)
		pf_putnbr_fd(nbr / 10, fd);
    ft_putchar_fd(c = nbr % 10 + '0', fd);
}

int pf_putlnbr_fd(int nbr, int fd, struct pf_data data)
{
    int len;
    int preclen;

    len = 0;
    if (nbr > 0 && data.is_positive_sign)
    {
        write(fd, "+", 1);
        len += 1;
    }
    else if (nbr > 0 && data.is_space)
    {
        write(fd, " ", 1);
        len += 1;
    }
    if (nbr < 0)
        ft_putchar_fd('-', fd);
    len += ft_digitlen(nbr);
    // printf("len: %d\n", len);
    // printf("widthlen: %d\n", data.width - len);
    if (!data.is_left_justify)
        len += pf_width(data.width - len + (nbr < 0), data.is_zero, fd);
    preclen = data.precision - len;
    // printf("preclen: %d\n", preclen);
    while (preclen > 0)
    {
        write(fd, "0", 1);
        preclen--;
        len++;
    }
    if (nbr == -2147483648)
		ft_putstr_fd("2147483648", fd);
    else
        pf_putnbr_fd(nbr, fd);
    if (data.is_left_justify)
        len += pf_width(data.width - len + (nbr < 0), data.is_zero, fd);
    return (len);
}