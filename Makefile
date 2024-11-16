BLACK		:= \033[1;30m
RED		:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
MAGENTA		:= \033[1;35m
CYAN		:= \033[1;36m
WHITE		:= \033[1;37m
RESET		:= \033[1;0m


# Targets
NAME 		:= miniRT
MLX		:= mlx
BSD_LIB = $(shell pkg-config --libs bsd)

MF		:= Makefile

# Directories
INCS_DIR		:= incs
LIBS_DIR		:= libs
MLX_DIR			:= libs/$(MLX)
SRCS_DIR		:= srcs
LOG_DIR			:= $(SRCS_DIR)/log
OBJS_CRT		:= create_objs
DEPS_CRT		:= create_deps


# Files

INC_FILES		:= scene.h \
				camera.h \
				colours.h \
				file.h \
				mrt-math.h \
				materials.h \
				shapes.h \
				parsing.h \
				ft_strings.h \
				error-handler.h \
				ray.h \
				window.h \
				lights.h

SRC_FILES		:= minirt.c \
				scene.c \
				parse-inputfile.c \
				parse-errors.c \
				ft_strings.c \
				string-iterate.c \
				string-verify.c \
				string-write.c \

			#create includes var with include names.
OBJS_DIR		:= .objs
DEPS_DIR		:= .deps
SRCS		 	:= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS		 	:= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
DEPS		 	:= $(patsubst $(SRCS_DIR)/%.c, $(DEPS_DIR)/%.d, $(SRCS))
INCS			:= $(addprefix $(INCS_DIR)/, $(INC_FILES))

# Compilation & flags
CC 			:= cc
CFLAGS			:= -Wall -Wextra -Werror -O3
UNAMEL			:= "Compiling for Linux"
IFLAGS			:= -I$(INCS_DIR) -I$(MLX_DIR)
DFLAGS			:= -g -fsanitize=leak
LFLAGS			:= -L$(MLX_DIR) -lmlx


all: $(MLX) $(OBJS_DIR) $(DEPS_DIR) $(NAME) 

$(NAME):: $(OBJS) $(MF) $(INCS) | $(MLX) 
	@printf "\n$(GREEN)=>$(RESET) Compiling $(MAGENTA)$(NAME)$(RESET)\n"
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS)  $(OBJS) -o $(NAME) $(LFLAGS)
$(NAME):: $(OBJS) $(MF) | $(MLX)  
	@printf "\n$(GREEN)⭐⭐⭐ $(RESET) Compilation $(MAGENTA)$(NAME)$(RESET) completed ‍🖖 $(GREEN)⭐⭐⭐ $(RESET)\n\n"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/*%.c $(MF) $(INCS) 
	@printf "$(GREEN)√ $(RESET)$(WHITE)%s$(RESET)\n  " "$<"
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

$(OBJS_DIR):
	@$(MAKE) create_objs
create_objs::
	@printf "\n$(GREEN)=>$(RESET) Creating $(WHITE)$(OBJS_DIR)$(RESET) dir\n" 
	@mkdir -vp .objs 
	@chmod 755 $(OBJS_DIR)
create_objs:: 
	@printf " 🌟 $(WHITE) Objects Folders Created $(RESET)🌟 \n" 

$(DEPS_DIR):
	@$(MAKE) create_deps
create_deps:: 
	@printf "\n$(GREEN)=>$(RESET) Creating $(WHITE)$(DEPS_DIR)$(RESET) dir\n" 
	@mkdir -vp .deps
	@chmod 755 $(DEPS_DIR)
create_deps::
	@printf " 🌟 $(WHITE) Dependencies Folders Created $(RESET) 🌟 \n\n" 

$(MLX) : $(MLX_DIR)/Makefile $(MLX_DIR)/mlx.h
	@printf "$(GREEN)=>$(RESET) Compiling $(MAGENTA)$(MLX)$(RESET) library\n" 
	@printf "$(GREEN)::$(RESET) Looking for Graphic Dependencies for $(MAGENTA)minilibx$(RESET) library\n" 
	@printf "$(GREEN)::$(RESET) This can take a while depending the state of your dependencies\n" 
	@if ! sudo -n true 2>/dev/null; then \
		echo ""; \
		echo "$(RED)::->$(RESET) You don't have sudo access. Ask your system admin to install the following dependencies: "; \
		echo "\t >_ $(WHITE)sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev$(RESET)"; \
		echo ""; \
		echo  "$(RED)::->$(RESET) If you are sure that you have installed all this dependencies. Just execute the next code to skip this step."; \
		echo "\t >_ $(WHITE)touch .mlx$(RESET)"; \
		echo ""; \
	else \
		exit; \
	fi 
	@if [ ! -f .mlx ]; then \
		sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev && \
		touch .mlx; \
	fi
	@$(MAKE) -C $(MLX_DIR)

clean:
	@echo "\033[1;31mX\033[0m \033[1;37mRemoving Objects MLX\033[0m"
	@$(MAKE) -C $(MLX_DIR) clean
	@printf "$(RED)X$(RESET) Removing $(RED)$(NAME)$(RESET) Objects\n"
	@rm -vfR $(OBJS_DIR)/** 

fclean: clean
	@printf "$(RED)X$(RESET) Removing $(RED)$(NAME)$(RESET) exec\n"
	@rm -f $(NAME)
	@rm -vRf .objs
	@rm -vRf .deps

re: fclean all
	@echo "\n==========================================="
	@echo "|| \033[1;32m√\033[0m Recompiled  \033[1;33m$(NAME)\033[0m"
	@echo "==========================================="

-include $(DEPS)
.PHONY: re clean fclean all create_deps create_objs
