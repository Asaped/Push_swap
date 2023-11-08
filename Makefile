NAME		=	push_swap

SRCS		=	push_swap.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

RM			=	rm -f

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean		: 
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re

