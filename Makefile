# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 15:15:08 by lrosch            #+#    #+#              #
#    Updated: 2022/03/22 11:49:29 by lrosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= push_swap.a

CC:= gcc

FLAGS+= -Wall -Wextra -Werror -g

SRC:=	push_swap.c sort_operations.c lst_utils.c error_checking.c \
		math_utils.c algorithms.c algorithm_utils.c bandaids.c \
		free_stuff.c more_bandaids.c

LIBFT:= ./libft+/libft/libft.a

OBJECTS:= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C ./libft+/libft
	@cp ${LIBFT} $(NAME)
	@${CC} $(FLAGS) -c $(SRC)
	@ar rc $(NAME) *.o
	${CC} ${FLAGS} ${NAME} -o push_swap

%.o: %.c
	@$(CC) $< -c $(FLAGS)

clean:
	@rm -f ./libft+/libft/*.o
	rm -f *.o

fclean: clean
	@rm -f push_swap.a
	rm -f push_swap
	@rm -f a.out
	@rm -f ./libft+/libft/libft.a
	rm -f $(NAME)

re: fclean
	@make all

bonus: all
