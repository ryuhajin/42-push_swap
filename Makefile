CC = cc

CFLAG = -Wall -Werror -Wextra -g

NAME = push_swap

SRCS = sort.c push_swap_utils.c input_utils.c input_utils_2.c input_utils_3.c main.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

bonus : all

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

%.o : %.c
	 $(CC) $(CFLAG) $^ -o $@ -c -I ./push_swap.h

clean : 
		rm -rf $(OBJS)

fclean : clean 
	     rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
