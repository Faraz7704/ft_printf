/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlunbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:29:29 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/08 00:18:40 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putlunbr_fd(unsigned int nbr, int fd)
{
    char    c;
    int     len;
    
	if (nbr / 10)
		len = ft_putlunbr_fd(nbr / 10, fd);
    else
        len = 0;
    len += ft_putlchar_fd(c = nbr % 10 + '0', fd);
    return (len);
}