
NAME = push_swap

CC = gcc
CLFAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = main \
		ctrl_control \
		ctrl_split \
		ctrl_arrcheck \
		instructions \
		instructions2 \
		solve_1 \
		solve_2 \
		solve_3 \
		solve_4 \
		solve_5 \
		solve_utils \
		solve_utils2 \
		utils \
		utils_arr \
		lis_utils \
		lis_utils2 \


SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addsuffix .o, $(FILES))

$(NAME): $(OBJS)
	@printf "povero gabbbiano, ha perduto la cumbaaagnaaaaa\n"
	$(CC) -o $(NAME) $^ 

%.o : %.c
	$(CC) -c $^ 

all: $(NAME)

deb: $(SRCS)
	$(CC) $(CFLAGS) $^ -o $(NAME) -g

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re: clean all

.PHONY: all clean fclean re deb

