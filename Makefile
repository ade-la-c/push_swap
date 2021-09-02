# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/01 15:02:21 by ade-la-c          #+#    #+#              #
#    Updated: 2021/09/02 15:19:21 by ade-la-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

SRCS			= srcs/main.c \
				srcs/actions.c \
				srcs/utils/utils.c \
				srcs/algo/algo_3.c \
				srcs/algo/algo_5.c \
				srcs/algo/big_algo/big_algo.c \
				#srcs/algo/big_algo/sort_stb.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc

RM				= rm -f

CFLAGS			= -Wall -Werror -Wextra -I. #-g -fsanitize=address

LIB				= -L ./includes/libft -lft

CL_GREY			= \033[38;2;128;128;128m

CL_GREEN		= \033[38;2;0;153;0m

CL_RESET		= \033[0m

.c.o:
				@${CC} ${CFLAGS} -c $^ -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
						@echo "$(CL_GREEN)-> COMPILING LIBFT$(CL_RESET)"
						@echo "$(CL_GREY)"
						@$(MAKE) -C ./includes/libft bonus
						@echo "$(CL_RESET)"
						@echo "$(CL_GREEN)-> COMPILING PUSH_SWAP$(CL_RESET)"
						@echo "$(CL_GREY)"
						$(CC) ${CFLAGS} -o$(NAME) $(OBJS) $(LIB)
						@echo "$(CL_RESET)"

clean:
						@echo "$(CL_GREEN)-> CLEAN$(CL_RESET)"
						@echo "$(CL_GREY)"
						@$(MAKE) -C ./includes/libft clean
						$(RM) $(OBJS)
						@echo "$(CL_RESET)"

fclean:				clean
						@echo "$(CL_GREEN)-> FCLEAN$(CL_RESET)"
						@echo "$(CL_GREY)"
						@$(MAKE) -C ./includes/libft fclean
						$(RM) $(NAME)
						@echo "$(CL_RESET)"

re:					fclean all

mclean:				all clean

.PHONY:				all clean fclean re
