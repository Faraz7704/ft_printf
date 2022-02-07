/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlhex_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:29:29 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/08 01:57:09 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_puthex(unsigned int num, int fd, int isupper)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, fd, isupper);
		ft_puthex(num % 16, fd, isupper);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (isupper)
				ft_putchar_fd((num - 10 + 'A'), fd);
			else
				ft_putchar_fd((num - 10 + 'a'), fd);
		}
	}
}

int ft_putlhex_fd(unsigned int nbr, int fd, int isupper)
{
    if (nbr == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(nbr, fd, isupper);
	return (ft_hexlen(nbr));
}