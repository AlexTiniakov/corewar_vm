# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/07 14:30:48 by dskrypny          #+#    #+#              #
#    Updated: 2018/09/28 13:28:16 by dskrypny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = corewar
NAME2 = asm

SRC_ASM = asm_main.c\
		asm_check_code_structure.c \
		asm_check_operation.c \
		asm_check_symbols.c \
		asm_description_mod.c \
		asm_error_manager.c \
		asm_label_fix.c \
		asm_op.c \
		asm_op_argtype_checker.c \
		asm_token_manager.c \
		asm_tokenizer.c \
		asm_tokenizer2.c \
		asm_utillity.c \
		asm_validate_token.c \
		asm_validate_token2.c \
		asm_write_file.c

SRC_VM = core.c \
		cycle_term.c\
		cycle_visual.c\
		error.c \
		finder.c \
		forks.c \
		ft_checkout.c \
		ft_cycle.c \
		ft_print_info.c \
		ft_print_lines.c \
		ft_print_pause.c \
		ft_print_players.c \
		ft_print_winner.c \
		ft_put_frame.c \
		ft_reader.c \
		ft_spin_visual.c \
		header_validation.c \
		main.c \
		map.c \
		players.c \
		stuff_funcs.c \
		stuff_funcs2.c \
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

FLAGS = -Wall -Wextra -Werror
MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

OBJ_ASM = $(addprefix $(OBJ_DIR_ASM)/,$(SRC_ASM:.c=.o))
OBJ_VM = $(addprefix $(OBJ_DIR_VM)/, $(SRC_VM:.c=.o))

SRC_DIR_ASM = assem/src
OBJ_DIR_ASM = assem/obj
INC_DIR_ASM = assem/includes

OBJ_DIR_VM = vm/objects
SRC_DIR_VM = vm/source

LIB_ASM = assem/libft/libft.a
LIB_VM = vm/libft/libft.a


all: $(NAME1) $(NAME2)
 
$(NAME1): $(OBJ_VM)
	@make -C vm/libft/
	@gcc $(FLAGS) $(OBJ_VM) -o $(NAME1) $(LIB_VM) $(MLX)
	@echo "\033[32mcorewar is created!\033[0m"

$(OBJ_DIR_VM)/%.o: $(SRC_DIR_VM)/%.c
	@mkdir -p $(OBJ_DIR_VM)
	@mkdir -p $(OBJ_DIR_VM)/operations
	@gcc $(FLAGS) -c -o $@ $<

$(NAME2): $(OBJ_ASM)
	@make -C assem/libft/
	@gcc -o $(NAME2) $(FLAGS) $(OBJ_ASM) -Iincludes $(LIB_ASM)
	@echo "\033[32masm is created!\033[0m"

$(OBJ_DIR_ASM)/%.o: $(SRC_DIR_ASM)/%.c
	@mkdir -p assem/obj
	@gcc -c $(FLAGS) -Iincludes $< -o $@

clean:
	@rm -rf $(OBJ_DIR_ASM)
	@rm -rf $(OBJ_DIR_VM)
	@make -C vm/libft/ clean
	@make -C assem/libft/ clean

fclean: clean
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@make -C vm/libft/ fclean
	@make -C assem/libft/ fclean

re: fclean all