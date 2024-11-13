# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 12:52:15 by kdi-noce          #+#    #+#              #
#    Updated: 2022/01/31 16:27:36 by kdi-noce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = printf/libftprintf.a
CC = gcc
CFLAG = -Wall -Werror -Wextra
OPTION = -c
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: server client

server:	server.c $(LIB)
		CC $(CFLAG) $(LIB) server.c -o server

client:	client.c $(LIB)
		CC $(CFLAG) $(LIB) fct_alter.c client.c -o client
 		
$(LIB): printf/
		make -C printf
		
clean:
		/bin/rm -rf $(OBJ)
		make -C printf clean

fclean: clean
		/bin/rm -rf server client
		make -C printf fclean

re: fclean all

.PHONY: clean fclean re all