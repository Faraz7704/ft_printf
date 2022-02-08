/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlhex_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:29:29 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/08 19:04:46 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putlhex_fd(unsigned int nbr, int fd, int isupper)
{
    if (nbr == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(nbr, fd, isupper);
	return (ft_hexlen(nbr));
}