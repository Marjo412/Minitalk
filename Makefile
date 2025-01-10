# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 14:28:23 by mrosset           #+#    #+#              #
#    Updated: 2025/01/10 12:07:14 by mrosset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SERVER_NAME = server
CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT_SRCS = client.c
SERVER_SRCS = server.c
LIBFT_DIRECTORY = libft
LIBFT_ARCHIVE = $(LIBFT_DIRECTORY)/libft.a
FT_PRINTF_DIRECTORY = ft_printf
FT_PRINTF_ARCHIVE = $(FT_PRINTF_DIRECTORY)/libftprintf.a

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRCS) $(LIBFT_ARCHIVE)
		$(CC) $(CFLAGS) -o $@ $(CLIENT_SRCS) -L$(LIBFT_DIRECTORY) -lft

$(SERVER_NAME): $(SERVER_SRCS) $(libft)
		$(CC) $(CFLAGS) -o $@ $(SERVER_SRCS) -L$(LIBFT_DIRECTORY) -lft

$(LIBFT_ARCHIVE):
		$(MAKE) -c $(LIBFT_DIRECTORY)
clean: 
		$(MAKE) -C $(LIBFT_DIRECTORY) clean

fclean: clean
		$(MAKE) -C $(LIBFT_DIRECTORY) fclean
		rm -rf $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re