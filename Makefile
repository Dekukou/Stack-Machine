##
## ETNA PROJECT, 04/11/2019 by fayoll_a
## AbstractVM
## File description:
##      MakeFile of the Stack Machine
##

CC   = gcc
NAME =	abstractvm
SRC  =	main.c                  \
		sources/my_putsth.c	    \
		sources/my_printf.c     \
		sources/chained_list.c  \
		sources/my_checkfile.c  \
		sources/my_operations.c \
		sources/my_printitem.c  \
		sources/my_putint.c     \
		sources/utils.c         \
		sources/utils2.c        \
		sources/interpreter.c
		
OBJ  =	$(SRC:%.c=%.o)
CFLAGS = -W -Werror -Wextra -Wall
LDFLAGES = -lmy
RM =    rm -f

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
		$(RM) $(OBJ)

fclean:			clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:    all clean fclean re
