NAME = push_swap.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
src =	main.c
		
OBJS = ${src:.c=.o}
LIBC = ar rcs
REMOVE = rm -f
LIBFT = libft.a
LDIR = libft/

${NAME}:${OBJS} ${LDIR}${LIBFT} 
		cp ${LDIR}${LIBFT} ${NAME} 
		${LIBC} ${NAME} ${OBJS}

all:${LDIR}${LIBFT} ${NAME}

${LDIR}${LIBFT}:
	${MAKE} -C ${LDIR}

clean :
		${REMOVE} ${OBJS}
		${REMOVE} ${LDIR}*.o
 
fclean :clean
		${REMOVE} ${NAME}
		${REMOVE} ${LDIR}${LIBFT}
re:fclean all
 
.PHONY: all clean fclean re 
