# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjungoo <kjungoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 15:58:21 by kjungoo           #+#    #+#              #
#    Updated: 2022/07/28 17:07:53 by kjungoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAG = -Wall -Wextra -Werror
INCLUDES = ./libft.h

SRC_PART1 = \
	./ft_isalpha.c	\
	./ft_isdigit.c	\
	./ft_isalnum.c	\
	./ft_isascii.c	\
	./ft_isprint.c	\
	./ft_strlen.c	\
	./ft_memset.c	\
	./ft_bzero.c	\
	./ft_memcpy.c	\
	./ft_memmove.c	\
	./ft_strlcpy.c	\
	./ft_strlcat.c	\
	./ft_toupper.c	\
	./ft_tolower.c	\
	./ft_strchr.c	\
	./ft_strrchr.c	\
	./ft_strncmp.c	\
	./ft_memchr.c	\
	./ft_memcmp.c	\
	./ft_strnstr.c	\
	./ft_atoi.c		\
	./ft_calloc.c	\
	./ft_strdup.c	
	
SRC_PART2 = \
	./ft_substr.c		\
	./ft_strjoin.c		\
	./ft_strtrim.c		\
	./ft_split.c		\
	./ft_itoa.c			\
	./ft_strmapi.c		\
	./ft_striteri.c		\
	./ft_putchar_fd.c	\
	./ft_putstr_fd.c	\
	./ft_putendl_fd.c	\
	./ft_putnbr_fd.c

SRC_BONUS = \
	./ft_lstnew.c	\
	./ft_lstadd_front.c	\
	./ft_lstsize.c	\
	./ft_lstlast.c	\
	./ft_lstadd_back.c	\
	./ft_lstdelone.c	\
	./ft_lstclear.c	\
	./ft_lstiter.c	\
	./ft_lstmap.c


SRCS = \
	$(SRC_PART1)	\
	$(SRC_PART2)
	
OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

$(NAME) : $(OBJS)
	ar -crs $@ $^

bonus : $(OBJS) $(OBJS_BONUS)
	ar -crs $(NAME) $^

.PHONY: all clean fclean re bonus
