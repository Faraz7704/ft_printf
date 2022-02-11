/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:17:08 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/11 22:17:40 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "stdarg.h"

struct printf_data
{
    int precision;
    int width;
    int is_left_justify;
    int is_positive_sign;
    int is_hash;
    int is_zero;
    int is_space;
};

int                     ft_printf(const char *str, ...);
struct printf_data      ft_parse_flags(char *flag);
int                     pf_putlchar_fd(char c, int fd, struct printf_data data);
int                     pf_putlstr_fd(char *str, int fd, struct printf_data data);
int                     pf_putlnbr_fd(int nbr, int fd, struct printf_data data);
int                     ft_digitlen(int nbr);
int                     pf_putlhex_fd(unsigned int nbr, int fd, int isupper, struct printf_data data);
int                     pf_putlunbr_fd(unsigned int nbr, int fd, struct printf_data data);
int                     pf_putlptr_fd(unsigned long long ptr, int fd, struct printf_data data);
int                     pf_width(int n, int is_zero, int fd);
void	                ft_puthex(uintptr_t num, int fd, int isupper);
int                     ft_hexlen(uintptr_t num);

# endif