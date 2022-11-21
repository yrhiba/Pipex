# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 21:48:43 by yrhiba            #+#    #+#              #
#    Updated: 2022/11/21 22:08:49 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
		ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove \
		ft_strlcpy ft_strlcat ft_strchr ft_strrchr ft_strncmp \
		ft_memchr ft_memcmp ft_strnstr ft_calloc ft_strdup \
		ft_tolower ft_atoi  ft_toupper ft_substr ft_strjoin \
		ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_strtrim \
		ft_split ft_itoa ft_strmapi ft_striteri ft_putnbr_fd \
		ft_printf ft_format ft_init_tab \
		ft_addchar ft_addstr \
		ft_converthex ft_itoa ft_isnum \
		ft_miniatoi \
		ft_check_format ft_check_flags ft_check_flags_utils \
		ft_format_c ft_format_s ft_format_s_utils \
		ft_format_d ft_format_u ft_format_x ft_format_x_utils \
		ft_format_p ft_lstnew ft_lstadd_front ft_lstsize \
		ft_lstlast ft_lstadd_back ft_lstdelone \
		ft_lstclear ft_lstiter ft_lstmap \
		get_next_line get_next_line_utils

OBJS_DIR = objs/

SRCS = $(FILES:=.c)
OBJS = $(addprefix $(OBJS_DIR), $(FILES:=.o))

OBJS_BONUS = $(OBJS) $(addprefix $(OBJS_DIR), $(BONUS_FILES:=.o))

CC = cc
FLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS_DIR)%.o : %.c libft.h
	@mkdir -p objs
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

clean :
	rm -rf $(OBJS_DIR)

fclean : clean
	rm -f libft.a

re : fclean all

bonus : all

.PHONEY : all clean fclean re bonus
