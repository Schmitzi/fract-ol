# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 10:05:21 by mgeiger-          #+#    #+#              #
#    Updated: 2023/12/12 13:49:52 by mgeiger-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -g -O3 -march=native
EXTRA	=	-lmlx -lXext -lX11 -lm
RM		=	rm -f

RED		=	\e[0;91m
BLUE	=	\e[0;94m
GREEN	=	\e[0;92m
YELLOW	=	\e[0;33m
WHITE	=	\e[0;97m
BOLD	=	\e[1m
U_LINE	=	\e[4m
RESET	=	\e[0m

FILES	=	controls \
			draw \
			error \
			extra \
			init \
			main \
			utils

SRC_DIR = 	./
SRC 	= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))

OBJ_DIR	= 	obj/
OBJ		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c -o $@ $<

all:	$(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compliling fract-ol$(RESET)"
	@$(CC) $(CFLAGS) $(EXTRA) -o $(NAME) $(OBJ)
	@echo "$(GREEN)Fract-ol built$(RESET)"

clean:
	@$(RM) $(OBJ)
	@if [ -d "obj" ]; then \
		rm -r obj/; \
	fi
	@echo "$(RED)Removed .o files$(RESET)"

fclean:	clean
	@$(RM) $(NAME)
	@echo "$(RED)All files cleaned$(RESET)"

re:		fclean all
	@echo "$(GREEN)Successfully cleaned and rebuilt program$(RESET)"
	
gitpush:
	@make fclean > /dev/null 2>&1
	@git add * > /dev/null 2>&1
	@echo "$(YELLOW)Added all files$(RESET)"
	@git commit -m "Fract-ol" > /dev/null 2>&1
	@echo "$(YELLOW)Commited files$(RESET)"
	@git push > /dev/null 2>&1
	@echo "$(GREEN)Files pushed$(RESET)"
	@git status

.PHONY:		all clean fclean re fractol gitpush
