# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 13:40:02 by pharbst           #+#    #+#              #
#    Updated: 2022/12/05 09:01:02 by pharbst          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME		=	$(shell uname)
OS			=	$(shell cat /etc/os-release | grep -e NAME | cut -d= -f2 | tr -d '"')
OS_LIKE		=	$(shell cat /etc/os-release | grep ID_LIKE | cut -d= -f2)



# Compiler
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
CFLAGS			+=	-g
LINUX_FLAGS	=	-ldl -lglfw -lm

# Project
NAME		=	fdf

# srcfiles
SRC_NAME	=	main.c \
				draw_line.c \
				get_img_coords.c \
				img_draw.c \
				offset.c \
				recalc_img.c \
				rotate.c \
				set_pixel.c \
				y_scale.c \
				zoom.c \
\
				img_init.c \
				init_map_coords.c \
				init_map.c \
				init_matrix.c \
				t_a_init.c \
\
				checkkeys.c \
				keyaction_arrow.c \
				keyaction_rotation.c \
				keyaction_special.c \
				keyaction_y.c \
				keyaction_zoom.c \
				keyhook_arrow.c \
				keyhook_numpad.c \
				keyhook_special.c \
				keyhooks.c \
\
				free_map.c \
				ft_better_split.c \
				ft_better_trim.c \
				ft_exit.c \
				ft_xtoi.c \
				map_size.c \
				matrix_multiply.c \
				read_map.c \
				reset_coords.c \

# directorys
INC_DIR		=	includes/
SRC_DIR		=	src/
OBJ_DIR		=	obj/
LIBFT_DIR	=	libft/
MLX_DIR		=	MLX42/

# librarys
LIBFTIO		=	$(LIBFT_DIR)libftio.a
MLX42		=	$(MLX_DIR)libmlx42.a

# Include
INC_SRC		=	-I includes
INC_LIBFTIO	=	-I $(LIBFT_DIR)includes
INC_MLX		=	-I $(MLX_DIR)include

# object
OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ			=	$(addprefix $(OBJ_DIR),$(OBJ_NAME))
SRC			=	$(addprefix $(SRC_DIR),$(SRC_NAME))


ifeq ($(UNAME), Linux)
	include Makefile_unix.mk
else ifeq ($(UNAME), Darwin)
	include Makefile_MAC.mk
else
	$(error OS ($(UNAME)) is not supported)
endif

# Rules
all:
	@./spinner.sh make $(NAME)

$(MLX42):
	@make -C $(MLX_DIR) > /dev/null

$(LIBFTIO):
	@make -C $(LIBFT_DIR) > /dev/null

fclean: header
	@./spinner.sh make cleanall

cleanall:
	@printf "$(FRed)FCleaning$(RESET)						  	      "
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@make fclean -C $(MLX_DIR) > /dev/null
	@make fclean -C $(LIBFT_DIR) > /dev/null
	@printf "$(FGreen)[$(TICK)]\n$(RESET)"

re:
	@./spinner.sh make header cleanall $(NAME)

git:	commit push

commit:
	git commit -m "$(msg)"

push:
	git push -u $(branch)

update:
	git pull
	make update -C ./libft

header:
	@printf "$(FYellow)╔═══════════════════════════════════════════════════════════════════════╗\n\
║   __/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_____/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_             ║\n\
║    _\\\\/\\\\\\\\\\\\///////////__\\\\/\\\\\\\\\\\\////////\\\\\\\\\\\\__\\\\/\\\\\\\\\\\\///////////__            ║\n\
║     _\\\\/\\\\\\\\\\\\_____________\\\\/\\\\\\\\\\\\______\\\\//\\\\\\\\\\\\_\\\\/\\\\\\\\\\\\_____________           ║\n\
║      _\\\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_____\\\\/\\\\\\\\\\\\_______\\\\/\\\\\\\\\\\\_\\\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_____          ║\n\
║       _\\\\/\\\\\\\\\\\\///////______\\\\/\\\\\\\\\\\\_______\\\\/\\\\\\\\\\\\_\\\\/\\\\\\\\\\\\///////______         ║\n\
║        _\\\\/\\\\\\\\\\\\_____________\\\\/\\\\\\\\\\\\_______\\\\/\\\\\\\\\\\\_\\\\/\\\\\\\\\\\\_____________        ║\n\
║         _\\\\/\\\\\\\\\\\\_____________\\\\/\\\\\\\\\\\\_______/\\\\\\\\\\\\__\\\\/\\\\\\\\\\\\_____________       ║\n\
║          _\\\\/\\\\\\\\\\\\_____________\\\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/___\\\\/\\\\\\\\\\\\_____________      ║\n\
║           _\\\\///______________\\\\////////////_____\\\\///______________     ║\n\
║                                                                       ║\n\
╚═══════════════════════════════════════════════════════════════════════╝\n"

MLX_header:
	@printf "$(FBlue)Compiling MLX42							      $(Reset)"

libftio_header:
	@printf "$(FGreen)[$(TICK)]\n$(FBlue)Compiling Libftio						      $(Reset)"

obj_header:
	@printf "$(FGreen)[$(TICK)]\n$(FBlue)Compiling .o files$(RESET)						      "

linking_header:
	@printf "$(FGreen)[$(TICK)]\n$(Green)Linking $(PRONAME)$(RESET)						  	      "