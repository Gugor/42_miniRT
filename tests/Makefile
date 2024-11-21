BLACK		:= \033[1;30m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
MAGENTA		:= \033[1;35m
CYAN		:= \033[1;36m
WHITE		:= \033[1;37m
RESET		:= \033[1;0m


# Targets
NAME 			:= miniRT-tests
MF				:= Makefile
MLX				:= mlx	
LIBFT			:= libft	

INCS_DIR		:= ../incs
LIBS_DIR		:= ../libs
MLX_DIR			:= ../libs/$(MLX)
LIBFT_DIR		:= ../libs/$(LIBFT)


CC 				:= cc
GCC 			:= gcc
CFLAGS			:= -Wall -Wextra -Werror -O3
IFLAGS			:= -I$(INCS_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)
DFLAGS			:= -g -fsanitize=leak
LFLAGS			:= -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft

COMPILATION		:= comp

LISTS_TST1_SRCS 	:= ../srcs/list-creation.c \
						../srcs/list-iteration.c \
						test-lsts.c
LISTS_TST1_INCS		:= ../incs/scene.h \

$(COMPILATION) :
			$(CC) $(LISTS_TST1_SRCS) $(IFLAGS) $(CFLAGS) $(DFLAGS) -o lst-tst1 