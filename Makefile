# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/07 14:30:48 by dskrypny          #+#    #+#              #
#    Updated: 2018/09/19 15:38:02 by dskrypny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SOURCE = cycles.c \
		 finder.c \
		 forks.c \
		 main.c \
		 map.c \
		 operations.c \
		 operations1.c \
		 operations2.c \
		 operations3.c \
		 players.c \
		 asm_op.c

OBJ_DIR = ./objects/
SRC_DIR = ./source/

OBJ = $(addprefix $(OBJ_DIR), $(SOURCE:.c=.o))

HEADER = op.h

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIB)
	@echo "$(NAME) compiled"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	@gcc $(FLAGS) -c -o $@ $< 

clean:
	@make clean -C libft/
	@rm -rf $(OBJ)
	@echo "obj files deleted"

fclean: clean
	@make fclean -C libft/
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@echo "$(NAME) file deleted"

re: fclean all

vpath %.c $(SRC_DIR)
