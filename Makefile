# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 16:03:14 by ael-hadd          #+#    #+#              #
#    Updated: 2022/01/03 12:43:41 by ael-hadd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libftX		=	./libftX/libftX.a

SERVER_SRCS	=	server.c
SERVER_NAME	=	server

CLIENT_SRCS	=	client.c
CLIENT_NAME	=	client

NAME		=	minitalk

$(NAME)		:	$(libftX) $(SERVER_NAME) $(CLIENT_NAME)

$(libftX)	:	./libftX
			@$(MAKE) -C ./libftX
			@echo "libftX compiled √"

$(SERVER_NAME)	:	$(SERVER_SRCS)
			@gcc -Wall -Werror -Wextra $(SERVER_SRCS) $(libftX) -o $(SERVER_NAME)
			@echo "server created successfully √"

$(CLIENT_NAME)	:	$(CLIENT_SRCS)
			@gcc -Wall -Werror -Wextra $(CLIENT_SRCS) $(libftX) -o $(CLIENT_NAME)
			@echo "client created successfully √"

all		:	$(NAME)

clean		:
			@$(MAKE) fclean -C ./libftX

fclean		: clean
			@rm -f $(SERVER_NAME) $(CLIENT_NAME)
			@echo "Everything is cleaned"

re		:	 fclean all

bonus		:	$(NAME)

.PHONY		:	all clean fclean re bonus