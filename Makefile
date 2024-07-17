CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = philo

SRCS_LIBFT = 42_library/ft_atoi.c 42_library/ft_isdigit.c 42_library/ft_memset.c 42_library/ft_strlen.c 42_library/ft_bzero.c 42_library/ft_isprint.c 42_library/ft_strchr.c		\
	42_library/ft_strncmp.c 42_library/ft_calloc.c 42_library/ft_memchr.c 42_library/ft_strdup.c 42_library/ft_strnstr.c 42_library/ft_isalnum.c 42_library/ft_memcmp.c 			\
	42_library/ft_strjoin.c 42_library/ft_strrchr.c 42_library/ft_isalpha.c 42_library/ft_memcpy.c 42_library/ft_strlcat.c 42_library/ft_tolower.c 42_library/ft_isascii.c			\
	42_library/ft_memmove.c 42_library/ft_strlcpy.c 42_library/ft_toupper.c 42_library/ft_substr.c 42_library/ft_strjoin.c 42_library/ft_strtrim.c 42_library/ft_split.c 			\
	42_library/ft_itoa.c 42_library/ft_strmapi.c 42_library/ft_striteri.c 42_library/ft_putchar_fd.c 42_library/ft_putstr_fd.c 42_library/ft_putendl_fd.c 42_library/ft_putnbr_fd.c	\
	42_library/ft_lstadd_back.c 42_library/ft_lst_add_front.c 42_library/ft_lstlast.c 42_library/ft_lstnew.c

SRCS_PHILO = tools/check_args.c tools/philo.c	\

OBJS = $(SRCS_LIBFT:.c=.o) $(SRCS_PHILO:.c=.o)

all : $(NAME)

$(NAME):$(OBJS)
	ar rc $(NAME) $(OBJS)
 	
clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
