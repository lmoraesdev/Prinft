# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 14:08:36 by lbatista          #+#    #+#              #
#    Updated: 2021/09/24 14:09:47 by lbatista         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIB			= ar -rcs
LIB1		= ranlib
RM			= /bin/rm -f

INCS		= libft.h
SRCS		= ft_strlen.c ft_memcpy.c ft_strlcpy.c ft_strchr.c ft_strdup.c \
			ft_strjoin.c ft_uitoa_base.c ft_isdigit.c ft_appendchr.c \
			ft_isascii.c ft_isprint.c ft_strlcat.c ft_memset.c ft_strndup.c

OBJS		= $(SRCS:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS) $(INCS)
			$(LIB)	$(NAME) $(OBJS)
			$(LIB1) $(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
