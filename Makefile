# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 23:06:25 by pharbst           #+#    #+#              #
#    Updated: 2022/09/16 23:10:44 by pharbst          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

DEPNAME	= libftio

#BNAME	=

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -I includes -g		#-g flag is for debugging remove it to compile faster

SRCDIR	=	./src

OBJDIR	=	./obj

BOBJDIR	=	./bobj

FILES	=

#BFILES	=

Black			=	\033[0;30m
FBlack			=	\033[1;30m
Red				=	\033[0;31m
FRed			=	\033[1;31m
Green			=	\033[0;32m
FGreen			=	\033[1;32m
Brown/Orange	=	\033[0;33m
FBrown/Orange	=	\033[1;33m
FYellow			=	\033[1;33m
Yellow			=	\033[0;33m
Blue			=	\033[0;34m
FBlue			=	\033[1;34m
Purple			=	\033[0;35m
FPurple			=	\033[1;35m
Cyan			=	\033[0;36m
FCyan			=	\033[1;36m
FWhite			=	\033[1;37m
White			=	\033[0;37m
NC				=	\033[0m

OBJS	=	$(addprefix $(OBJDIR)/, $(FILES:.c=.o))

#BOBJS	=	$(addprefix $(BOBJDIR)/, $(BFILES:.c=.o))

all:	start $(NAME) end

bonus:	bstart $(BNAME) bend

start:
	@echo "$(FYellow)make $(NAME)...$(NC)"

bstart:
	@echo "$(FYellow)make $(BNAME)...$(NC)"

end:
	@echo "$(FGreen)$(NAME) done$(NC)"

bend:
	@echo "$(Green)$(BNAME) done$(NC)"

$(NAME):	OSTART $(OBJS) OEND
	@echo "$(FWhite)dependencie $(DEPNAME) needed$(NC)"
	@make -C ./libft
#	@cp libft/libft.a $(NAME)
	@echo "$(FPurple)linking $(DEPNAME) in $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lftio

#$(BNAME):	BOSTART $(BOBJS) BOEND
#	@make -C ./libft
#	@$(CC) $(CFLAGS) -o $(BNAME) -Llibft -lftio $(BOBJS)

$(OBJDIR)/%.o:	$(SRCDIR)/*/%.c ./includes/push_swap.h
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
	@make clean -C ./libft
	@echo "$(FRed)make clean pushswap$(Red)"
	rm -rf $(OBJDIR)
	rm -rf $(BOBJDIR)

fclean:
	@make fclean -C ./libft
	@echo "$(FRed)make flcean pushswap$(Red)"
	rm -rf $(OBJDIR)
	rm -rf $(BOBJDIR)
	rm -rf $(NAME)
	rm -rf $(BNAME)
	@printf "$(NC)"

re:	rec fclean all rend

rec:
	@echo "$(FPurple)recompiling...$(NC)"

rend:
	@echo "$(FGreen)recompiled$(NC)"

git:	commit push

commit:
	git commit -m "$(msg)"

push:
	git push -u $(branch)

.PHONY:	all bonus clean fclean re OSTART OEND rend rec"