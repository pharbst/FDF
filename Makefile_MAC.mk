# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_MAC.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 18:19:35 by pharbst           #+#    #+#              #
#    Updated: 2022/12/05 08:53:44 by pharbst          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Black			=	$(shell echo "\033[0;30m")
FBlack			=	$(shell echo "\033[1;30m")
Red				=	$(shell echo "\033[0;31m")
FRed			=	$(shell echo "\033[1;31m")
Green			=	$(shell echo "\033[0;32m")
FGreen			=	$(shell echo "\033[1;32m")
Brown/Orange	=	$(shell echo "\033[0;33m")
FBrown/Orange	=	$(shell echo "\033[1;33m")
FYellow			=	$(shell echo "\033[1;33m")
Yellow			=	$(shell echo "\033[0;33m")
Blue			=	$(shell echo "\033[0;34m")
FBlue			=	$(shell echo "\033[1;34m")
Purple			=	$(shell echo "\033[0;35m")
FPurple			=	$(shell echo "\033[1;35m")
Cyan			=	$(shell echo "\033[0;36m")
FCyan			=	$(shell echo "\033[1;36m")
FWhite			=	$(shell echo "\033[1;37m")
White			=	$(shell echo "\033[0;37m")
RESET			=	$(shell echo "\033[0m")
TICK			=	$(shell echo "\xE2\x9C\x94")

LIB_GLFW	=	-lglfw

GLFW_DIR	=	/Users/$(USER)/.brew/opt/glfw/lib/
BREW_FILE	=	/Users/$(USER)/.brewconfig.zsh

$(NAME):	header glfw MLX_header $(MLX42) libftio_header $(LIBFTIO) obj_header $(OBJ) linking_header
	@$(CC) $(CFLAGS) $(OBJ) $(MLX42) $(INC_GLFW) $(LIB_GLFW) -L $(GLFW_DIR) -L $(LIBFT_DIR) -lftio -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)
	@printf "$(FGreen)[$(TICK)]\n"

$(OBJ_DIR)%.o:	$(SRC_DIR)*/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $(INC_LIBFTIO) $(INC_MLX) $^ $(INC_SRC)

glfw: $(BREW_FILE) $(GLFW_DIR)

$(GLFW_DIR):
	@echo "$(FPurple) ----- INSTALLING GLFW ----- $(RESET)"
	brew install glfw3
	brew install glfw

$(BREW_FILE):
	@echo "$(FPurple) ----- INSTALLING BREW ----- $(RESET)"
	@curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh