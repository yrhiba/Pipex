# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 04:22:23 by yrhiba            #+#    #+#              #
#    Updated: 2022/12/06 03:46:20 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

INC = pipex.h

SRCS =	pipex.c pipex_utils.c return_utils.c \
		getpipes.c getfds.c  startforking.c \
		getcmdargs.c

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
FLAGS = -Wall -Wextra -Werror

$(NAME) : mlibft $(OBJS)
	cc $(OBJS) -o $(NAME) -L libft -l ft

$(OBJS_DIR)%.o : %.c $(INC)
	@mkdir -p $(OBJS_DIR)
	cc $(FLAGS) -c $< -o $@ -Ilibft

all : $(NAME)

clean : clibft
	rm -rf $(OBJS_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

mlibft :
	make -C libft

clibft :
	make fclean -C libft

bonus : all

.PHONEY : all fclean clean re clibft mlibft
