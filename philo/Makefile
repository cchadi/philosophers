CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g3

NAME = philo 

SRCS_PHILO = tools/ft_atoi.c tools/linked_list.c tools/utils.c \
	main.c parsing.c ft_start.c routine.c checking.c \

OBJS = $(SRCS_PHILO:.c=.o)

all : $(NAME)

$(NAME):$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
