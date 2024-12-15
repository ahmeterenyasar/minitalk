# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 12:48:45 by ayasar            #+#    #+#              #
#    Updated: 2024/12/15 11:01:43 by ayasar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server.c
CLIENT = client.c
SERVER_B = server_bonus.c
CLIENT_B = client_bonus.c
SERVER_NAME = server
CLIENT_NAME = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

all: $(FT_PRINTF_LIB) $(SERVER_NAME) $(CLIENT_NAME)

$(FT_PRINTF_LIB):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(SERVER_NAME): $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(SERVER) $(FT_PRINTF_LIB) -o $(SERVER_NAME)

$(CLIENT_NAME): $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(CLIENT) $(FT_PRINTF_LIB) -o $(CLIENT_NAME)

clean:
	@$(MAKE) clean -C $(FT_PRINTF_DIR)
	$(RM) $(SERVER_NAME) $(CLIENT_NAME)

fclean: clean
	@$(MAKE) fclean -C $(FT_PRINTF_DIR)

re: fclean all

bonus: $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(SERVER_B) $(FT_PRINTF_LIB) -o $(SERVER_NAME)
	$(CC) $(CFLAGS) $(CLIENT_B) $(FT_PRINTF_LIB) -o $(CLIENT_NAME)

.PHONY: all re fclean clean bonus
