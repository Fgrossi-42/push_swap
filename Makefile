NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = ./Src/main \
		./Controls/ctrl_control \
		./Src/ctrl_split \
		./Controls/ctrl_arrcheck \
		./Src/instructions \
		./Src/instructions2 \
		./Solutions/solve_1 \
		./Solutions/solve_2 \
		./Solutions/solve_3 \
		./Solutions/solve_4 \
		./Solutions/solve_5 \
		./Solutions/solve_utils \
		./Solutions/solve_utils2 \
		./Src/utils \
		./Src/utils_arr \
		./Lis/lis_utils \
		./Lis/lis_utils2 \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $^ 

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
