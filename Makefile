# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabasset <mabasset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 12:22:32 by mabasset          #+#    #+#              #
#    Updated: 2022/04/20 10:08:32 by mabasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
SRC = check.c main.c swap.c push.c rotate.c rev_rotate.c utility.c find.c findcomb.c movecount.c initializer.c
SRC_CHECK = check.c checker.c swap.c push.c rotate.c rev_rotate.c utility.c initializer.c
FLAG = -Wall -Werror -Wextra
LIBFT = libft/libft.a

$(NAME):
		make re -C libft
		gcc $(FLAG) -o $(NAME) $(SRC) $(LIBFT)

bonus:
		make re -C libft
		gcc $(FLAG) -o $(BONUS) $(SRC_CHECK) $(LIBFT)

all:	$(NAME) bonus

clean:
		rm -f $(NAME) $(BONUS) $(LIB)

fclean:	clean
		make fclean -C libft

re:		fclean all

.PHONY:	all clean fclean re