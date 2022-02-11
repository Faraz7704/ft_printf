/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putlhex_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:29:29 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/11 22:55:53 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pf_putlhex_fd(unsigned int nbr, int fd, int isupper, struct pf_data data)
{
	int	len;
	int	preclen;

	len = 0;
	if (data.is_hash)
	{
		if (isupper)
			write(fd, "0X", 2);
		else
			write(fd, "0x", 2);
		len += 2;
	}
	if (nbr == 0)
		len++;
	else
		len += ft_hexlen(nbr);
	if (!data.is_left_justify)
        len += pf_width(data.width - len, data.is_zero, fd);
	preclen = data.precision - len;
    while (preclen > 0)
    {
        write(fd, "0", 1);
        preclen--;
		len++;
    }
	if (nbr == 0)
		write(fd, "0", 1);
	else
		ft_puthex(nbr, fd, isupper);
	if (data.is_left_justify)
        len += pf_width(data.width - len, data.is_zero, fd);
	return (len);
}