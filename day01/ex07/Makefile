# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/20 11:49:06 by rtarasen          #+#    #+#              #
#    Updated: 2018/06/20 11:49:23 by rtarasen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace
CC = clang++
CFLAGS = -Wall -Wextra -Werror -I.
OBJ = $(FILES:.cpp=.o)

FILES = replace.cpp

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) *.o -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all