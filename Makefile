# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maricont <maricont@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 19:53:38 by maricont          #+#    #+#              #
#    Updated: 2023/10/06 13:16:48 by maricont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_list.c init.c move_stack.c push_swap.c sort.c util.c ft_split.c sort_short.c

SRCS_BONUS = checker_bonus.c ft_split.c init.c ft_list.c util.c get_next_line_bonus.c get_next_line_utils_bonus.c sort_short.c checker_util_bonus.c move_bonus.c move_stack.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

RM = rm -f
INCLUDE = -I ./

%.o : %.c
	${CC} ${CFLAGS} $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	${CC} ${CFLAGS} $(OBJS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	${CC} ${CFLAGS} $(OBJS_BONUS) -o $(NAME_BONUS)

clean :
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re bonus




