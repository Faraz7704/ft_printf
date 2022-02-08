/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:17:08 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/08 19:05:14 by fkhan            ###   ########.fr       */
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
int     ft_putlhex_fd(unsigned int nbr, int fd, int isupper);
int     ft_putlunbr_fd(unsigned int nbr, int fd);
int     ft_putlptr_fd(unsigned long long ptr, int fd);
char    *ft_rm_whitespace(const char *str);
void	ft_puthex(uintptr_t num, int fd, int isupper);
int     ft_hexlen(uintptr_t num);

# endif