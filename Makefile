CC			=	cc
CFLAGS		=	#-Wall -Wextra -Werror

LINUX_FLAGS	=	-ldl -lglfw -lm -I /MLX42/include/MLX42

UNAME		=	$(shell uname)
OS			=	$(shell cat /etc/os-release | grep -e NAME | cut -d= -f2 | tr -d '"')
OS_LIKE		=	$(shell cat /etc/os-release | grep ID_LIKE | cut -d= -f2)

BOLD		=	$(shell echo -e "\033[1m")
BLACK		=	$(shell echo -e "\033[30;1m")
RED			=	$(shell echo -e "\033[31;1m")
GREEN		=	$(shell echo -e "\033[32;1m")
YELLOW		=	$(shell echo -e "\033[33;1m")
BLUE		=	$(shell echo -e "\033[34;1m")
MAGENTA		=	$(shell echo -e "\033[35;1m")
CYAN		=	$(shell echo -e "\033[36;1m")
WHITE		=	$(shell echo -e "\033[37;1m")
RESET		=	$(shell echo -e "\033[0m")

SRC_DIR		=	src/
OBJ_DIR		=	obj/
LIB_DIR		=	libft/
INC_DIR		=	includes/
MLX42		=	MLX42/

GLFW_DIR	=	/Users/$(USER)/.brew/opt/glfw/lib/
BREW_FILE	=	/Users/$(USER)/.brewconfig.zsh

LIBFT		=	$(LIB_DIR)libftio.a
MLX			=	$(MLX42)libmlx42.a
LIB_GLFW	=	-lglfw

INC_LIB		=	-I$(LIB_DIR)
INC_SRC		=	-I$(INC_DIR)
INC_MLX		=	-I$(MLX42)include/MLX42

SRC_NAME	=	ft_better_split.c\
				ft_better_trim.c\
				ft_printmatrix.c\
				structprint.c\
				bresenham.c\
				ft_img_calc.c\
				ft_set_pixel.c\
				init_t_a.c\
				main.c\
				ft_get_map_size.c\
				ft_get_map.c\
				ft_init_map_xz.c\
				ft_exit.c\
				ft_rotate.c\
				ft_set_rot.c\
				ft_xtoi.c\
				matrix_multiply.c\

OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ			=	$(addprefix $(OBJ_DIR),$(OBJ_NAME))
SRC			=	$(addprefix $(SRC_DIR),$(SRC_NAME))

NAME		=	fdf

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)*/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)Compiling: $(RESET) $<"
	@$(CC) $(CFLAGS) -o $@ -c $^ $(INC_LIB) $(INC_MLX)

$(NAME): dependencies $(LIBFT) $(MLX) $(OBJ)
ifeq ($(UNAME), Linux)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(INC_GLFW) $(LIB_GLFW) -L $(GLFW_DIR) -L $(LIB_DIR) -lftio $(LINUX_FLAGS) -o $(NAME)
else ifeq ($(UNAME), Darwin)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(INC_GLFW) $(LIB_GLFW) -L $(GLFW_DIR) -L $(LIB_DIR) -lftio -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)
else
	echo "$(RED)OS ($(UNAME)) not supported$(RESET)"
endif
	@echo "$(GREEN)Done$(RESET)"

$(LIBFT):
	make -C $(LIB_DIR)

$(MLX):
	make -C $(MLX42)

dependencies:
	@echo "$(YELLOW)Checking dependencies...$(RESET)"
ifeq ($(UNAME), Darwin)
	@echo "$(YELLOW)Check for $(UNAME)...$(RESET)"
	@make $(BREW_FILE)
	@make $(GLFW_DIR)
else ifeq ($(UNAME), Linux)
	@echo "$(YELLOW)Check for $(UNAME)...$(RESET)"
ifeq ($(OS_LIKE), debian)
	@apt -y install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
else ifeq ($(OS_LIKE), arch)
	@sudo pacman -S --noconfirm glfw-x11
else
	@echo "$(RED)Your OS ($(OS_LIKE))is not supported$(RESET)"
endif
endif

	@echo "$(GREEN)Done$(RESET)"

$(GLFW_DIR) :
	@echo "$(MAGENTA) ----- INSTALLING GLFW ----- $(RESET)"
	brew install glfw3
	brew install glfw

$(BREW_FILE):
	@echo "$(MAGENTA) ----- INSTALLING BREW ----- $(RESET)"
	/bin/bash -c "$$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIB_DIR)
	make fclean -C $(MLX42)

re: fclean all $(MLX)