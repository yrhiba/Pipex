# Pipex
A pipe is a form of redirection (transfer of standard output to some other destination)

Program name :

     pipex

Makefile :

            all clean fclean re

External functs :

    open, close, read, write, malloc, free, perror,
    strerror, access, dup, dup2, execve, exit, fork, pipe,
    unlink, wait, waitpid

Program will be executed as follows :

       ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
  
Should behave like shell cmd bellow :

      < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
  
Support « and » when the first parameter is "here_doc" :

      ./pipex here_doc LIMITER cmd cmd1 file

Should behave like :

      cmd << LIMITER | cmd1 >> file
 
