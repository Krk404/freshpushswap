NAME = push_swap

FLAGS = -Wall -Wextra -Werror -g3
CC = gcc
LIBFT = libft/libft.a

SRCS = check.c stack.c operations.c main.c  simplification.c sort_small_stack.c\
		radix_sort.c utils.c security.c
OBJS = $(SRCS:.c=.o)

.c.o:
				${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all:	push_swap 

$(LIBFT):
				make -C libft 
				make -C libft bonus



push_swap:			$(LIBFT) $(OBJS)
				$(CC) ${OBJS} $(FLAGS) -Llibft/ -lft -o $(NAME)

clean:
				rm -rf $(OBJS)
				make -C libft clean

fclean:			clean
				rm -rf $(NAME) $(LIBFT)

re:				fclean all

.PHONY: all libft clean fclean re
