NAME = pipex

SRCS = pipex.c


all : mlibft
	cc pipex.c -o $(NAME) -L libft -l ft -I libft

mlibft :
	@make -C libft

clibft :
	make fclean -C libft

clean : clibft
	rm -rf pipex
