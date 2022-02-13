/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putlhex_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:29:29 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/13 19:39:33 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pf_putlhex_fd(unsigned int nbr, int fd, int isupper, struct pf_data data)
{
	int	len;
	int	preclen;

	len = 0;
	if (data.is_hash && nbr != 0)
	{
		if (isupper)
			write(fd, "0X", 2);
		else
			write(fd, "0x", 2);
		len += 2;
	}
	if (nbr == 0 && data.is_precision)
        len = 0;
	else if (nbr == 0)
		len++;
	else
		len += ft_hexlen(nbr);
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
	if (nbr == 0 && !data.is_precision)
		write(fd, "0", 1);
	else if (!data.is_precision || (nbr != 0 && data.is_precision))
		ft_puthex(nbr, fd, isupper);
	if (data.is_left_justify)
        len += pf_width(data.width - len, data.is_zero, fd);
	return (len);
}