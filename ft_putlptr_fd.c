/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlptr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:53:45 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/08 19:06:20 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putlptr_fd(unsigned long long ptr, int fd)
{
    int len;

    len = ft_putlstr_fd("0x", 1);
    if (ptr == 0)
		return (len + write(1, "0", 1));
	else
		ft_puthex(ptr, fd, 0);
	return (len + ft_hexlen(ptr));
}