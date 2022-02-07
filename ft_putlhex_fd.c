/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlhex_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:29:29 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/07 20:31:20 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putlhex_fd(int nbr, int fd, int isupper)
{
    char    c;
    int     len;

	if (nbr < 0)
		nbr *= -1;
	if (nbr >= 16)
		len = ft_putlhex_fd(nbr / 16, fd, isupper);
    else
        len = 0;
    if (isupper)
        c = "0123456789ABCDEF"[nbr % 16];
    else
        c = "0123456789abcdef"[nbr % 16];
    len += ft_putlchar_fd(c, fd);
    return (len);
}