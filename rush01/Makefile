# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/01 21:01:49 by rtarasen          #+#    #+#              #
#    Updated: 2018/07/01 21:05:53 by rtarasen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm
CC = clang++
CFLAGS = -Wall -Wextra -Werror
OBJ = $(FILES:.cpp=.o)

FILES = CPUModule.class.cpp GraphicalMode.class.cpp MemoryModule.class.cpp \
		NcursesMode.class.cpp NetworkModule.class.cpp OSInfoModule.class.cpp \
		SysMonitor.class.cpp TimeModule.class.cpp UserModule.class.cpp \
		Utilities.class.cpp main.cpp

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) *.o -lncurses -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all