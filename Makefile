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
NAME 			:= miniRT
MLX				:= mlx	
LIBFT			:= libft	

MF				:= Makefile

# Directories
INCS_DIR		:= incs
LIBS_DIR		:= libs
MLX_DIR			:= libs/$(MLX)
LIBFT_DIR		:= libs/$(LIBFT)
SRCS_DIR		:= srcs
GETLINE_DIR		:= get_line
LOGGER_DIR		:= logger
OBJS_CRT		:= create_objs
DEPS_CRT		:= create_deps


# Files

INC_FILES		:= scene.h \
				entity-data.h \
				camera.h \
				colours.h \
				file.h \
				vectors.h \
				materials.h \
				shapes.h \
				shape-maths.h \
				parsing.h \
				rendering.h \
				error-handler.h \
				ray.h \
				window.h \
				events.h \
				get_next_line.h \
				lights.h \
				time.h \
				logger.h

SRC_FILES		:= minirt.c \
				init-scene.c \
				parse-rtfile.c \
				parse-errors.c \
				parse-entities.c \
				parse-entity-shapes.c \
				parse-entity-params.c \
				parse-rtfile-line.c \
				parse-utils.c \
				render-scene.c \
				init-window.c \
				init-camera.c \
				events-window.c \
				rt-file.c \
				math-colours.c \
				math-convertions.c \
				math-in-range-utils.c \
				math-interval-absolutes.c \
				math-interval.c \
				math-rand-generation.c \
				math-shapes-calculations.c \
				math-shapes-calculations-square.c \
				math-shapes-normals.c \
				shapes-convertions.c \
				ray-cast.c \
				ambient-light.c \
				lights.c \
				colours-utils.c \
				colours-getters.c \
				vec3-operations.c \
				vec3-operations-2.c \
				vec3-float-operations.c \
				vec3-position-ops.c \
				pixel-operations.c \
				list-creation.c \
				list-iteration.c \
				memory-creation.c \
				memory-free.c \
				time-handler.c \
				$(GETLINE_DIR)/get_next_line.c \
				$(GETLINE_DIR)/get_next_line_utils.c \
				$(LOGGER_DIR)/print-scene.c \
				$(LOGGER_DIR)/log-viewport-data.c \

#create includes var with include names.
OBJS_DIR		:= .objs
DEPS_DIR		:= .deps
SRCS		 	:= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS		 	:= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
DEPS		 	:= $(patsubst $(SRCS_DIR)/%.c, $(DEPS_DIR)/%.d, $(SRCS))
INCS			:= $(addprefix $(INCS_DIR)/, $(INC_FILES))

# Compilation & flags
CC 				:= cc
GCC 			:= gcc
CFLAGS			:= -Wall -Wextra -Werror
OFLAGS			:= -O3
IFLAGS			:= -I$(INCS_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)
DFLAGS			:= -g -fsanitize=leak
LFLAGS			:= -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft  -lX11 -lXext -lm


all: $(MLX) $(LIBFT) $(OBJS_DIR) $(DEPS_DIR) $(NAME) 

$(NAME):: $(OBJS) $(MF) $(INCS) | $(MLX) $(LIBFT)
	@printf "\n$(GREEN)=>$(RESET) Compiling $(MAGENTA)$(NAME)$(RESET)\n"
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) $(OFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)
$(NAME):: $(OBJS) $(MF) | $(MLX) $(LIBFT) 
	@printf "\n$(GREEN)⭐⭐⭐ $(RESET) Compilation $(MAGENTA)$(NAME)$(RESET) completed ‍🖖 $(GREEN)⭐⭐⭐ $(RESET)\n\n"

debug:: $(OBJS) $(MF) $(INCS) | $(MLX) $(LIBFT)
	@printf "\n$(YELLOW)=======+++++  DEBUG MODE  +++==========$(RESET)\n"
	@printf "\n$(GREEN)=>$(RESET) Compiling $(MAGENTA)$(NAME)$(RESET)\n"
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS)  $(OBJS) -o $(NAME)-deb $(LFLAGS)
debug:: $(OBJS) $(MF) | $(MLX) $(LIBFT) 
	@printf "\n$(GREEN)⭐⭐⭐ $(RESET) Compilation $(MAGENTA)$(NAME)$(RESET) completed ‍🖖 $(GREEN)⭐⭐⭐ $(RESET)\n\n"
	@printf "\n$(YELLOW)=======+++++  DEBUG MODE  +++==========$(RESET)\n"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/*%.c $(MF) $(INCS) 
	@printf "$(GREEN)√ $(RESET)$(WHITE)%s$(RESET)\n  " "$<"
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

$(OBJS_DIR):
	@$(MAKE) create_objs

create_objs::
	@printf "\n$(GREEN)=>$(RESET) Creating $(WHITE)$(OBJS_DIR)$(RESET) dir\n" 
	@mkdir -vp .objs 
	@mkdir -vp .objs/get_line 
	@mkdir -vp .objs/logger 
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
	
$(MLX) : 
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

$(LIBFT) : 
	@printf "$(GREEN)=>$(RESET) Compiling $(MAGENTA)$(LIBFT)$(RESET) library\n" 
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo "\033[1;31mX\033[0m \033[1;37mRemoving Objects MLX\033[0m"
	@$(MAKE) -C $(MLX_DIR) clean
	@printf "$(RED)X$(RESET) Removing $(RED)$(NAME)$(RESET) Objects\n"
	@rm -vfR $(OBJS_DIR)/** 

fclean: clean
	@printf "$(RED)X$(RESET) Removing $(RED)$(NAME)$(RESET) exec\n"
	@rm -f $(NAME) $(NAME)-deb
	@rm -vRf .objs
	@rm -vRf .deps

re: fclean all
	@echo "\n==========================================="
	@echo "|| \033[1;32m√\033[0m Recompiled  \033[1;33m$(NAME)\033[0m"
	@echo "==========================================="

-include $(DEPS)
.PHONY: re clean fclean all create_deps create_objs
