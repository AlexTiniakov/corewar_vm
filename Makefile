# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/07 14:30:48 by dskrypny          #+#    #+#              #
#    Updated: 2018/09/23 17:16:28 by dskrypny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SOURCE = core.c \
		 cycles.c \
		 cycle_term.c\
		 error.c \
		 finder.c \
		 forks.c \
		 ft_cycle.c\
		 ft_print_info.c \
		 main.c \
		 map.c \
		 players.c \
		 stuff_funcs.c \
		 asm_op.c \
		 operations/anding.c \
		 operations/addition.c \
		 operations/aff.c \
		 operations/alive.c \
		 operations/forking.c \
		 operations/jump.c \
		 operations/load.c \
		 operations/load_index.c \
		 operations/long_forking.c \
		 operations/long_load.c \
		 operations/long_load_index.c \
		 operations/oring.c \
		 operations/store.c \
		 operations/store_index.c \
		 operations/substract.c \
		 operations/xoring.c

OBJ_DIR = ./objects/
SRC_DIR = ./source/

MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

OBJ = $(addprefix $(OBJ_DIR), $(SOURCE:.c=.o))

HEADER = op.h

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIB) $(MLX)
	@echo "$(NAME) compiled"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@mkdir $(OBJ_DIR)/operations

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
