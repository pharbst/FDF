# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 23:06:25 by pharbst           #+#    #+#              #
#    Updated: 2022/10/17 16:20:26 by pharbst          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SHELL=	/bin/bash

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
NC				=	$(shell echo -e "\033[0m")

NAME	=	fdf

DEPNAME	=	libftio, mlx42

#BNAME	=

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -I includes -I libft/includes -g		#-g flag is for debugging remove it to compile faster

SRCDIR	=	./src

OBJDIR	=	./obj

BOBJDIR	=	./bobj

FILES	=	main.c\
			ft_get_map.c\
			ft_better_split.c\
			ft_xtoi.c\
			structprint.c\
			ft_set_pixel.c\
			ft_get_map_size.c\
			ft_better_trim.c\

#BFILES	=

OBJS	=	$(addprefix $(OBJDIR)/, $(FILES:.c=.o))

#BOBJS	=	$(addprefix $(BOBJDIR)/, $(BFILES:.c=.o))

all:	start $(NAME) end

#bonus:	bstart $(BNAME) bend

start:
	@echo "            ################   ########                      ################"
	@echo "           ################    ###########                  ################"
	@echo "          #####                ####   ######               #####"
	@echo "         #####                 ####     #####             #####"
	@echo "        #####                  ####      ####            #####"
	@echo "       ###############         ####       ####          ###############"
	@echo "      ###############          ####       #####        ##############"
	@echo "     #####                     ####       ####        #####"
	@echo "    #####                      ####      #####       #####"
	@echo "   #####                       ####     #####       #####"
	@echo "  #####                        ####   #####        #####"
	@echo " #####                         ##########         #####"
	@echo "#####                          #######           #####"
	@echo "$(FYellow)make $(NAME)...$(NC)"

#bstart:
#	@echo "$(FYellow)make $(BNAME)...$(NC)"

end:
	@echo "$(FGreen)$(NAME) done$(NC)"

#bend:
#	@echo "$(Green)$(BNAME) done$(NC)"

$(NAME):	OSTART $(OBJS) OEND
	@echo "$(FWhite)dependencie $(DEPNAME) needed$(NC)"
	@make -C ./libft
	@make -C ./MLX42
#	@cp libft/libft.a $(NAME)
	@echo "$(FPurple)linking $(DEPNAME) in $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lftio -LMLX42 -lmlx42 -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"


#$(BNAME):	BOSTART $(BOBJS) BOEND
#	@make -C ./libft
#	@$(CC) $(CFLAGS) -o $(BNAME) -Llibft -lftio $(BOBJS)

$(OBJDIR)/%.o:	$(SRCDIR)/*/%.c ./includes/fdf.h
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf  "$(NC)$@; "

#$(BOBJDIR)/%.o:	$(SRCDIR)/*/%.c ./includes/checker.h
#	@mkdir -p $(BOBJDIR)
#	@$(CC) $(CFLAGS) -o $@ -c $<
#	@printf "$(NC)$@; "

OSTART:
	@echo "$(Blue)creating object files...$(NC)"
#BOSTART:
#	@echo "$(Blue)creating object files...$(NC)"

OEND:
	@echo ""
	@echo "$(Green)object files created$(NC)"
#BOEND:
#	@echo ""
#	@echo "$(Green)object files created$(NC)"

clean:
	@echo "$(FRed)make clean $(NAME)$(Red)"
	rm -rf $(OBJDIR)
#	rm -rf $(BOBJDIR)

fclean:
	@echo "$(FRed)make flcean $(NAME)$(Red)"
	rm -rf $(OBJDIR)
#	rm -rf $(BOBJDIR)
	rm -rf $(NAME)
#	rm -rf $(BNAME)
	@printf "$(NC)"

re:	rec fclean all rend

reall:	rec fclean libftfclean all rend

libftfclean:
	@make fclean -C /libft

rec:
	@echo "$(FPurple)recompiling...$(NC)"

rend:
	@echo "$(FGreen)recompiled$(NC)"

git:	commit push

commit:
	git commit -m "$(msg)"

push:
	git push -u

.PHONY:	all bonus clean fclean re OSTART OEND rend rec"