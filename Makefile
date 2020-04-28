# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 17:18:28 by arbocqui          #+#    #+#              #
#    Updated: 2020/02/27 19:33:51 by arbocqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21_sh

SRCS_PATH = srcs/
OBJ_PATH  = obj/
LIBFT_PATH = libft/

LIBFT = libft/libft.a

CC = gcc

CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra

#CFLAGS = -g3 -fsanitize=address

INC = -I ./includes/ -I ./$(LIBFT_PATH)/

SRCS_NAME = main.c \
			display.c \
			display_misc.c \
			env.c \
			env_misc.c \
			error.c \
			finder.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJ) $(INC) $(LIBFT) -o $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@$(CC) -c $(CFLAGS) $(INC) $< -o $@
	@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"

clean:
	@make -C $(LIBFT_PATH)/ clean
	@$(RM) -rf $(OBJ_PATH)
	@echo "\033[31mObjects files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@make -C $(LIBFT_PATH)/ fclean
	@$(RM) -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
