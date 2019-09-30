# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/27 19:28:12 by rtarasen          #+#    #+#              #
#    Updated: 2018/06/27 20:17:12 by rtarasen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = iter
CC = clang++
CFLAGS = -Wall -Wextra -Werror -I.
OBJ = $(FILES:.cpp=.o)

FILES = iter.cpp

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) *.o -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all