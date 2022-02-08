# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 11:40:15 by fkhan             #+#    #+#              #
#    Updated: 2022/02/08 19:06:42 by fkhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= libftprintf.a
LIBFT			= libft.a
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
LIB 			= ar -rcs
RM				= rm -f

SRCS 			= ft_printf.c ft_putlchar_fd.c ft_putlstr_fd.c \
				  ft_putlnbr_fd.c ft_digitlen.c ft_putlhex_fd.c \
				  ft_putlunbr_fd.c ft_putlptr_fd.c ft_rm_whitespace.c \
				  ft_puthex.c ft_hexlen.c

OBJS 			= $(SRCS:.c=.o)

$(NAME): 		$(OBJS)
				cp libft/$(LIBFT) .
				mv $(LIBFT) $(NAME)
				$(LIB) $(NAME) $(OBJS)

%.o: 			%.c
				$(CC) $(CFLAGS) -c $< -o $@		

all: 			$(NAME)

clean:	 		
				$(RM) $(OBJS)

fclean: 		clean
				$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re