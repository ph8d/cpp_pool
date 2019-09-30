# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 19:21:33 by rtarasen          #+#    #+#              #
#    Updated: 2018/06/18 19:21:35 by rtarasen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CC = clang++
CFLAGS = -Wall -Wextra -Werror -I.
OBJ = $(FILES:.cpp=.o)

FILES = phonebook.cpp PhoneBook.class.cpp Contact.class.cpp

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) *.o -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all