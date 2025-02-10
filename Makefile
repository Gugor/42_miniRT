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
GUI_DIR			:= GUI
COLOR_DIR		:= color
EVENTS_DIR		:= events
INTERSEC_DIR	:= intersections
LIGHTS_DIR		:= lights
MATHS_DIR		:= maths
MEMORY_DIR		:= memory
PARSING_DIR		:= parsing
RENDER_DIR		:= render
VIEWPORT_DIR	:= viewport
MISC_DIR		:= misc

GETLINE_DIR		:= get_line
LOGGER_DIR		:= logger
OBJS_CRT		:= create_objs
DEPS_CRT		:= create_deps


# Files

INC_FILES		:= scene.h \
				entity-data.h \
				camera.h \
				gui.h \
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
				$(MISC_DIR)/list-creation.c \
				$(MISC_DIR)/list-iteration.c \
				$(MISC_DIR)/time-handler.c \
				$(VIEWPORT_DIR)/init-window.c \
				$(VIEWPORT_DIR)/init-camera.c \
				$(RENDER_DIR)/render-scene.c \
				$(RENDER_DIR)/ray-cast.c \
				$(RENDER_DIR)/pixel-operations.c \
				$(RENDER_DIR)/multithread.c \
				$(PARSING_DIR_DIR)/rt-file.c \
				$(PARSING_DIR)/init-scene.c \
				$(PARSING_DIR)/parse-rtfile.c \
				$(PARSING_DIR)/parse-errors.c \
				$(PARSING_DIR)/parse-entities.c \
				$(PARSING_DIR)/parse-entity-shapes.c \
				$(PARSING_DIR)/parse-entity-params.c \
				$(PARSING_DIR)/parse-rtfile-line.c \
				$(PARSING_DIR)/parse-utils.c \
				$(MEMORY_DIR)/memory-creation.c \
				$(MEMORY_DIR)/memory-free.c \
				$(MATHS_DIR)/math-convertions.c \
				$(MATHS_DIR)/math-in-range-utils.c \
				$(MATHS_DIR)/math-interval-absolutes.c \
				$(MATHS_DIR)/math-interval.c \
				$(MATHS_DIR)/math-rand-generation.c \
				$(MATHS_DIR)/vec3-operations.c \
				$(MATHS_DIR)/vec3-operations-2.c \
				$(MATHS_DIR)/vec3-float-operations.c \
				$(MATHS_DIR)/vec3-position-ops.c \
				$(LIGHTS_DIR)/ambient-light.c \
				$(LIGHTS_DIR)/lights.c \
				$(LIGHTS_DIR)/lights-utils.c \
				$(INTERSEC_DIR)/math-shapes-calculations.c \
				$(INTERSEC_DIR)/math-shape-calculations-cylinder.c \
				$(INTERSEC_DIR)/math-shape-calculations-square.c \
				$(INTERSEC_DIR)/math-shapes-normals.c \
				$(events)/config-flags-manager.c \
				$(events)/events-camera-displace.c \
				$(events)/events-camera-movement.c \
				$(events)/events-window.c \
				$(events)/init-events.c \
				$(COLOR_DIR)/math-colours.c \
				$(COLOR_DIR)/colours-utils.c \
				$(COLOR_DIR)/colours-getters.c \
				$(GETLINE_DIR)/get_next_line.c \
				$(GETLINE_DIR)/get_next_line_utils.c \
				$(LOGGER_DIR)/print-scene.c \
				$(LOGGER_DIR)/log-viewport-data.c \
				$(GUI_DIR)/entities-panel.c \

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
	@mkdir -vp .objs/GUI 
	@mkdir -vp .objs/color 
	@mkdir -vp .objs/events 
	@mkdir -vp .objs/intersections 
	@mkdir -vp .objs/lights 
	@mkdir -vp .objs/maths 
	@mkdir -vp .objs/memory 
	@mkdir -vp .objs/misc 
	@mkdir -vp .objs/parsing 
	@mkdir -vp .objs/render
	@mkdir -vp .objs/viewport 
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
