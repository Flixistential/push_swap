NAME = push_swap.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
src =	main.c\
		push_swap_utils.c\
		push_swap_utils2.c\
		moves.c\
		moves2.c\
		ft_atol_toi.c\
		sort.c\
		sort_utils.c\
		sort5_utils.c
		
OBJS = ${src:.c=.o}
LIBC = ar rcs
REMOVE = rm -f
LIBFT = libftps.a
LDIR = libftps/

${NAME}:${OBJS} ${LDIR}${LIBFT} 
		cp ${LDIR}${LIBFT} ${NAME} 
		${LIBC} ${NAME} ${OBJS}

all:${LDIR}${LIBFT} ${NAME}

${LDIR}${LIBFT}:
	${MAKE} -C ${LDIR}

clean :
		${REMOVE} ${OBJS}
		${REMOVE} ${LDIR}*.o

vis: all
	./push_swap_visualizer/build/bin/visualizer
 
fclean :clean
		${REMOVE} ${NAME}
		${REMOVE} ${LDIR}${LIBFT}
re:fclean all
 
.PHONY: all clean fclean re 
