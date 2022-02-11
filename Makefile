# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 11:40:15 by fkhan             #+#    #+#              #
#    Updated: 2022/02/11 22:26:02 by fkhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= libftprintf.a
LIBFT			= libft.a
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
LIB 			= ar -rcs
RM				= rm -f

SRCS 			= ft_printf.c ft_printf_flags.c pf_putlchar_fd.c \
				  pf_putlstr_fd.c pf_putlnbr_fd.c ft_digitlen.c \
				  pf_putlhex_fd.c pf_putlunbr_fd.c pf_putlptr_fd.c \
				  pf_width.c ft_puthex.c ft_hexlen.c

OBJS 			= $(SRCS:.c=.o)

$(NAME): 		$(OBJS)
				cp libft/$(LIBFT) .
				mv $(LIBFT) $(NAME)
				$(LIB) $(NAME) $(OBJS)

%.o: 			%.c
				$(CC) $(CFLAGS) -c $< -o $@		

all: 			$(NAME)

bonus:			all

clean:	 		
				$(RM) $(OBJS)

fclean: 		clean
				$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all bonus clean fclean re