# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 11:40:15 by fkhan             #+#    #+#              #
#    Updated: 2022/02/17 16:40:26 by fkhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= libft.a
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
LIB 			= ar -rcs
RM				= rm -f

SRCS 			= ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
				  ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
				  ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
				  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
				  ft_memcmp.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c \
				  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
				  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS 			= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
				  ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
				  ft_lstnew.c ft_lstsize.c

OBJS 			= $(SRCS:.c=.o)
BONUS_OBJS 		= $(BONUS:.c=.o)

$(NAME): 		$(OBJS)
				$(LIB) $(NAME) $(OBJS)

%.o: 			%.c
				$(CC) $(CFLAGS) -c $< -o $@		

all: 			$(NAME)

bonus:			$(BONUS)
				$(LIB) $(NAME) $(BONUS_OBJS)

clean:	 		
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean: 		clean
				$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all bonus clean fclean re