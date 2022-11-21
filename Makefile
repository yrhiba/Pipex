NAME = pipex

SRCS = pipex.c

all : 
	cc pipex.c -o $(NAME)

clean :
	rm -rf pipex