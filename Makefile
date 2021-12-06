# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 12:42:26 by bstrong           #+#    #+#              #
#    Updated: 2021/10/20 12:42:26 by bstrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SRC_SERVER =	./src/main_server.c ./src/ft_messange.c
SRC_CLIENT =	./src/main_client.c ./src/ft_messange.c

HEADER = minitalk.h

LIBS = -L./libft -lft
LIBFT = libft.a

OBJ_SERVER = $(patsubst %.c,%.o,$(SRC_SERVER))
OBJ_CLIENT = $(patsubst %.c,%.o,$(SRC_CLIENT))

FLAGS = -Wall -Wextra -Werror

CC = clang

.PHONY : all clean fclean re

all: $(LIBFT) $(SERVER) $(CLIENT)

bonus: all

$(LIBFT):
	make -C ./libft all

$(SERVER): $(OBJ_SERVER) $(HEADER)
	$(CC) $(OBJ_SERVER) $(LIBS) -o $@

$(CLIENT): $(OBJ_CLIENT) $(HEADER)
	$(CC) $(OBJ_CLIENT) $(LIBS) -o $@

%.o : %.c
	$(CC) $(FLAGS) -I ./  -I ./libft -c $< -o $@

clean:
	make -C ./libft clean
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	make -C ./libft fclean 
	rm -f $(SERVER)
	rm -f $(CLIENT)

re: fclean all