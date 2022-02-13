/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putlnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:32:17 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/13 19:40:03 by fkhan            ###   ########.fr       */
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
    if (nbr >= 0 && data.is_positive_sign)
    {
        write(fd, "+", 1);
        len += 1;
    }
    else if (nbr >= 0 && data.is_space)
    {
        write(fd, " ", 1);
        len += 1;
    }
    if (nbr < 0 && data.is_zero)
        ft_putchar_fd('-', fd);
    if (nbr == 0 && data.is_precision)
        len = 0;
    else
        len += ft_digitlen(nbr);
    // printf("len: %d\n", len);
    // printf("widthlen: %d\n", data.width - len);
    // printf("\ndata.precision: %d\n", data.precision);
    if (data.is_precision)
    {
        preclen = data.precision - len + (nbr < 0);
        if (preclen < 0)
            preclen = 0;
    }
    else
        preclen = 0;
    if (!data.is_left_justify)
        len += pf_width(data.width - len - preclen, data.is_zero && nbr != 0, fd);
    if (nbr < 0 && !data.is_zero)
        ft_putchar_fd('-', fd);
    // printf("preclen: %d\n", preclen);
    while (preclen > 0)
    {
        write(fd, "0", 1);
        preclen--;
        len++;
    }
    if (nbr == -2147483648)
		ft_putstr_fd("2147483648", fd);
    else if (!data.is_precision || (nbr != 0 && data.is_precision))
        pf_putnbr_fd(nbr, fd);
    if (data.is_left_justify)
        len += pf_width(data.width - len, data.is_zero, fd);
    return (len);
}