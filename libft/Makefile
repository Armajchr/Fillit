# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armajchr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 15:39:36 by armajchr          #+#    #+#              #
#    Updated: 2019/09/11 16:18:17 by armajchr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binaries
CC		=	/usr/bin/gcc
AR		=	/usr/bin/ar
RANLIB	=	/usr/bin/ranlib
RM		=	/bin/rm

# Directories
HEADER	=	.

# Compilation flags
CFLAGS	=	-Wall -Wextra -Werror

# Files
SRC	= ft_strcmp.c		\
			ft_strrchr.c	\
			ft_memccpy.c	\
			ft_strcpy.c		\
			ft_strstr.c		\
			ft_isalnum.c	\
			ft_memchr.c		\
			ft_strdup.c		\
			ft_tolower.c	\
			ft_isalpha.c	\
			ft_memcmp.c		\
			ft_strlcat.c	\
			ft_toupper.c	\
			ft_atoi.c		\
			ft_isascii.c	\
			ft_memcpy.c		\
			ft_strlen.c		\
			ft_isdigit.c	\
			ft_memmove.c	\
			ft_strncat.c	\
			ft_isprint.c	\
			ft_memset.c		\
			ft_strncmp.c	\
			ft_strcat.c		\
			ft_strncpy.c	\
			ft_strrev.c		\
			ft_strchr.c		\
			ft_strnstr.c	\
			ft_strtrim.c	\
			ft_strnbword.c	\
			ft_strlen_word.c	\
			ft_get_word.c	\
			ft_strsplit.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_bzero.c		\
			ft_strlcat.c	\
			ft_lstnew.c		\
			ft_print_lst.c	\
			ft_print_elem_lst.c	\
			ft_lstadd.c		\
			ft_lstiter.c	\
			ft_putnbr.c		\
			ft_putchar.c	\
			ft_putstr.c		\
			ft_putendl.c	\
			ft_memalloc.c	\
			ft_memdel.c		\
			ft_strnew.c		\
			ft_strdel.c		\
			ft_strclr.c		\
			ft_striter.c	\
			ft_striteri.c	\
			ft_strequ.c		\
			ft_strsub.c		\
			ft_strjoin.c	\
			ft_list_size.c	\
			ft_lstmap.c		\
			ft_itoa.c		\
			ft_strnequ.c	\
			ft_strmap.c		\
			ft_strmapi.c	\
			ft_lstdelone.c	\
			ft_lstdel.c		\
			get_next_line.c

OBJ		=	$(patsubst %.c,%.o,$(SRC))
HFILES	=	$(HEADER)/libft.h

# Name
NAME	=	libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):	$(OBJ) $(HFILES) Makefile
			@echo "Building $(NAME) ..."
			@$(AR) rc $(NAME) $(OBJ)
			@$(RANLIB) $(NAME)
			@echo "The library $(NAME) is ready"

%.o:		%.c
			@echo "Creating $@ ..."
			@$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

clean:
			@$(RM) -f $(OBJ)

fclean: clean
			@$(RM) -f $(NAME)

re: fclean all
