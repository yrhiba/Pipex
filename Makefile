NAME = pipex

SRCS = pipex.c

mlibft :
	make -C libft

all : mlibft
	cc pipex.c -o $(NAME) -L libft -l ft

clibft :
	make fclean -C libft

clean : clibft
	rm -rf pipex
