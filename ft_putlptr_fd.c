/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlptr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:53:45 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/08 02:04:03 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlenlong(uintptr_t num)
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

void	ft_puthexlong(uintptr_t num, int fd)
{
	if (num >= 16)
	{
		ft_puthexlong(num / 16, fd);
		ft_puthexlong(num % 16, fd);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd((num + '0'), 1);
		else
            ft_putchar_fd((num - 10 + 'a'), fd);
	}
}

int ft_putlptr_fd(unsigned long long ptr, int fd)
{
    int len;

    len = ft_putlstr_fd("0x", 1);
    if (ptr == 0)
		return (len + write(1, "0", 1));
	else
		ft_puthexlong(ptr, fd);
	return (len + ft_hexlenlong(ptr));
}