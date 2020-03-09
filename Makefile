# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armajchr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 10:53:16 by armajchr          #+#    #+#              #
#    Updated: 2019/10/01 15:05:34 by armajchr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB = libft.a
FLAG = -Wall -Wextra -Werror
OPTION = -c
SRC = checkerrors.c	\
	  gettetri.c	\
	  set_tetri.c	\
	  map.c			\
	  main.c
 
OBJETS = $(SRCLIB:.c=.o)

.PHONY: all clean fclean re
	 
all: $(NAME)
	 
$(NAME): $(LIB)
	    gcc -o $(NAME) $(FLAG) $(SRC) -L./libft -lft
		 
$(LIB):
	    make -C libft
		 
clean:
	    make -C libft clean
		 
fclean: clean
	    /bin/rm -f $(NAME)
		    make -C libft fclean
			 
re: fclean all
