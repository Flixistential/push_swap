NAME = push_swap
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
		sort5_utils.c\
		final_algo.c\
		count_moves.c\
		sort_case.c\
		push_swap_utils3.c\
		push_swap_utils4.c\
		sort_case5.c
		
OBJS = ${src:.c=.o}
REMOVE = rm -f
LIBFT = libftps.a
LDIR = libftps/

${NAME}:${OBJS} ${LDIR}${LIBFT}
		$(CC) $(CFLAGS) $(src) ${LDIR}${LIBFT} -o $(NAME)

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
