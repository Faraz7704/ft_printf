/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:17:08 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/07 15:31:36 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "stdarg.h"

int     ft_printf(const char *str, ...);
int     ft_putlchar_fd(char c, int fd);
int     ft_putlstr_fd(char *str, int fd);
int     ft_putlnbr_fd(int nbr, int fd);
int     ft_digitlen(int nbr);
int     ft_putlhex_fd(int nbr, int fd, int isupper);

# endif