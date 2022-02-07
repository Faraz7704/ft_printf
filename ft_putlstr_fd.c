/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:20:40 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/08 00:36:56 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putlstr_fd(char *str, int fd)
{
    if (!str)
    {
        ft_putstr_fd("(null)", fd);
        return (6);
    }
    ft_putstr_fd(str, fd);
    return (ft_strlen(str));
}