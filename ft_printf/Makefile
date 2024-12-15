NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRCS = ft_printf.c ft_fun.c ft_put.c

OBJS = $(SRCS:.c=.o)
			
all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
		
fclean:	clean
	$(RM) $(NAME)
		
re: fclean all

.PHONY: all re clean fclean