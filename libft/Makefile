# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 14:02:00 by arbocqui          #+#    #+#              #
#    Updated: 2020/02/25 13:56:39 by arbocqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strlen.c \
	  ft_countendl.c \
	  ft_strjoin_nul.c \
	  ft_strjoinf.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_itoa.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_lstnew.c \
	  ft_lstmap.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_unused.c \
	  get_next_line.c \
	  ft_free_tab.c

HEADER = /usr/local/include/libft.h

BIN_FOLDER = ./bin/

YELLOW = \033[0;33m

GREEN = \033[0;32m

END_COLOR = \033[0m

OBJ = $(addprefix $(BIN_FOLDER),$(SRC:.c=.o))

all: $(NAME)

bin:
	@mkdir bin

$(NAME): bin  $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@printf "$(GREEN) LIBFT DONE SUCESS! $(END_COLOR)"

$(BIN_FOLDER)%.o :%.c
	@gcc $< -c -I $(HEADER) -o $@ -Wall -Wextra -Werror
	@printf "$(YELLOW) Compiling:$(END_COLOR) $<  $(GREEN)[OK] $(END_COLOR)              \r"

clean:
	@rm -rf $(BIN_FOLDER)
	@printf "$(GREEN) Clean libft done $(END_COLOR)\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "$(GREEN) Fclean libft done $(END_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
