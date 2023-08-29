CC = gcc
CFLAG = -Wall -Werror -Wextra

NAME = push_swap
NAME_BONUS = checker
HEADER= ./headers/

SRCS = 	main.c \
		push_swap_list_utils.c push_swap_list_utils2.c push_swap_list_utils3.c push_swap_list_utils4.c \
		command_utils.c command_utils2.c command_utils3.c \
		input_utils.c input_utils_2.c input_utils_3.c \
		solution.c solution_2.c solution_3.c solution_4.c \
		sort.c

SRCS_BONUS = ./bonus/main_bonus.c \
			./bonus/push_swap_input_bonus.c ./bonus/push_swap_input_bonus2.c \
			./bonus/push_swap_utils_bonus.c ./bonus/push_swap_utils_bonus2.c \
			./bonus/command_utils_bonus.c ./bonus/command_utils_bonus2.c ./bonus/command_utils_bonus3.c \
			push_swap_list_utils.c push_swap_list_utils2.c push_swap_list_utils3.c push_swap_list_utils4.c \
			command_utils.c command_utils2.c command_utils3.c \
			input_utils.c input_utils_2.c input_utils_3.c \
			solution.c solution_2.c solution_3.c solution_4.c \
			sort.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

%.o : %.c
	 $(CC) $(CFLAG) $^ -o $@ -c -I $(HEADER)

$(NAME_BONUS) : $(OBJS_BONUS) 
				$(CC) $(CFLAG) $^ -o $@

clean : 
		rm -rf $(OBJS)
		rm -rf $(OBJS_BONUS)

fclean : clean 
	     rm -rf $(NAME)
		 rm -rf $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re bonus
