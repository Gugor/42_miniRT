# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 16:24:04 by hmontoya          #+#    #+#              #
#    Updated: 2024/11/19 16:27:13 by hmontoya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./
DEPS = libft.h Makefile 
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
	  ft_toupper.c ft_tolower.c ft_bzero.c ft_memcpy.c ft_strchr.c ft_strrchr.c ft_strcmp.c \
	  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_strnstr.c ft_memchr.c ft_memcmp.c ft_memmove.c \
	  ft_strlcpy.c ft_strlcat.c ft_atoi.c ft_calloc.c ft_strdup.c ft_strjoin.c ft_substr.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strmapi.c \
	  ft_striteri.c ft_strtrim.c ft_split.c ft_lstclear.c ft_lstadd_front.c ft_lstadd_back.c \
	  ft_lstdelone.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstmap.c ft_lstiter.c \
	  ft_isspace.c ft_skipspaces.c
OBJS  = $(SRCS:.c=.o) 
$(NAME) : $(OBJS) $(DEPS) 
	@echo "\033[1;32m== \033[0m \033[1;37mCreating Library \033[1;35m$@\033[0m"
	@printf "\033[1;37m|-> \033[0m"
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

%.o : %.c $(DEPS) 
	@printf "\033[1;32m√\033[0m \033[1;37m%s\033[0m\n  " "$<"
	$(CC) -c $< $(CFLAGS) -o $@

clean: $(OBJS)
	@echo "\033[1;31mX\033[0m \033[1;37mRemoving Objects\033[0m"
	@rm -vf $(OBJS) $(BOBJ)

fclean: clean
	@rm -fv $(NAME)
re: fclean all

.PHONY : clean fclean re all
