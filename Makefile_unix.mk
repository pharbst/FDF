# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_unix.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 16:38:37 by pharbst           #+#    #+#              #
#    Updated: 2022/11/08 14:38:29 by pharbst          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Black			=	$(shell echo -e "\033[0;30m")
FBlack			=	$(shell echo -e "\033[1;30m")
Red				=	$(shell echo -e "\033[0;31m")
FRed			=	$(shell echo -e "\033[1;31m")
Green			=	$(shell echo -e "\033[0;32m")
FGreen			=	$(shell echo -e "\033[1;32m")
Brown/Orange	=	$(shell echo -e "\033[0;33m")
FBrown/Orange	=	$(shell echo -e "\033[1;33m")
FYellow			=	$(shell echo -e "\033[1;33m")
Yellow			=	$(shell echo -e "\033[0;33m")
Blue			=	$(shell echo -e "\033[0;34m")
FBlue			=	$(shell echo -e "\033[1;34m")
Purple			=	$(shell echo -e "\033[0;35m")
FPurple			=	$(shell echo -e "\033[1;35m")
Cyan			=	$(shell echo -e "\033[0;36m")
FCyan			=	$(shell echo -e "\033[1;36m")
FWhite			=	$(shell echo -e "\033[1;37m")
White			=	$(shell echo -e "\033[0;37m")
RESET			=	$(shell echo -e "\033[0m")

$(NAME):	glfw $(MLX42) $(LIBFTIO) $(OBJ)
	@$(CC) $(CFLAGS) $(LINUX_FLAGS) $(OBJ) $(INC_SRC) $(INC_LIBFTIO) $(INC_MLX) -L $(MLX_DIR) -lmlx42 -L $(LIBFT_DIR) -lftio -o  $(NAME)
	@echo "$(FGreen)Done"

$(OBJ_DIR)%.o:	$(SRC_DIR)*/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(FGreen)Compiling:$(RESET) $(notdir $<)"
	@$(CC) $(CFLAGS) -o $@ -c $(INC_LIBFTIO) $(INC_MLX) $^ $(INC_SRC)

glfw:
ifeq ($(OS_LIKE), arch)
	@sudo pacman -S --noconfirm glfw-x11
else ifeq ($(OS), arch)
	@pacman -S --noconfirm glfw-x11
else ifeq ($(OS_LIKE), debian)
	@apt -y install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
else ifeq ($(OS), debian)
	@apt -y install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
else
	$(error Linux distribution ($(OS), $(OS_LIKE) based) not supportet)
endif