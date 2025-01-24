# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 09:54:47 by mrosset           #+#    #+#              #
#    Updated: 2025/01/24 09:55:02 by mrosset          ###   ########.fr        #
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

all: $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE) $(CLIENT_NAME) $(SERVER_NAME) 

$(CLIENT_NAME): $(CLIENT_SRCS) $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE)
		$(CC) $(CFLAGS) -o $@ $(CLIENT_SRCS) -L$(LIBFT_DIRECTORY) -lft -L$(FT_PRINTF_DIRECTORY) -lftprintf

$(SERVER_NAME): $(SERVER_SRCS) $(FT_PRINTF_ARCHIVE)
		$(CC) $(CFLAGS) -o $@ $(SERVER_SRCS) -L$(FT_PRINTF_DIRECTORY) -lftprintf

$(LIBFT_ARCHIVE):
		$(MAKE) -C $(LIBFT_DIRECTORY)

$(FT_PRINTF_ARCHIVE):
		$(MAKE) -C $(FT_PRINTF_DIRECTORY)
clean: 
		$(MAKE) -C $(LIBFT_DIRECTORY) clean
		$(MAKE) -C $(FT_PRINTF_DIRECTORY) clean

fclean: clean
		$(MAKE) -C $(LIBFT_DIRECTORY) fclean
		$(MAKE) -C $(FT_PRINTF_DIRECTORY) fclean
		rm -rf $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re