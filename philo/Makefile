CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

NAME = philo 

SRCS_PHILO = tools/ft_atoi.c tools/get_current.c tools/linked_list.c \
	main.c routine.c parsing.c ft_start.c checking.c \

OBJS = $(SRCS_PHILO:.c=.o)

all : $(NAME)

$(NAME):$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
