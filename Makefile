# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrosset <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 14:28:23 by mrosset           #+#    #+#              #
#    Updated: 2025/01/07 14:28:26 by mrosset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CLIENT_NAME = client
SERVER_NAME = server
CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT_SRCS = client.c
SERVER_SRCS = server.c
all: 

clean:

fclean: clean

re: fclean all

.PHONY: all clean fclean re