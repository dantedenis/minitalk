# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 09:38:50 by bstrong           #+#    #+#              #
#    Updated: 2021/11/25 12:05:22 by bstrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIST =	ft_atoi.c		ft_bzero.c		ft_calloc.c \
		ft_isalnum.c	ft_isalpha.c	ft_isascii.c \
		ft_isdigit.c	ft_isprint.c	ft_memchr.c \
		ft_memcmp.c		ft_memcpy.c		ft_memset.c \
		ft_putchar_fd.c	ft_putendl_fd.c	ft_split.c\
		ft_strchr.c		ft_strdup.c		ft_strlcat.c \
		ft_strlcpy.c	ft_strlen.c		ft_strncmp.c \
		ft_strnstr.c	ft_strrchr.c	ft_tolower.c \
		ft_itoa.c		ft_memmove.c	ft_toupper.c \
		ft_striteri.c	ft_strjoin.c	ft_strmapi.c \
		ft_strtrim.c	ft_substr.c		ft_putstr_fd.c	ft_putnbr_fd.c


LIST_B =	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c \
			ft_lstlast.c	ft_lstadd_back.c	ft_lstiter.c \
			ft_lstclear.c	ft_lstdelone.c		ft_lstmap.c

OBJ = $(patsubst %.c,%.o,$(LIST))
OBJ_B = $(patsubst %.c,%.o,$(LIST_B))

D_FILES = $(patsubst %.c,%.d,$(LIST) $(LIST_B))

FLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $?

%.o : %.c
	clang $(FLAGS) -c $< -o $@

include $(wildcard $(D_FILES))

bonus: $(OBJ) $(OBJ_B)
	ar rcs $(NAME) $?

clean:
	rm -f $(OBJ) $(OBJ_B) $(D_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
