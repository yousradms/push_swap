CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = push_swap

SRCF = push_swap.c parsing.c algo_1.c algo_2.c stack_3_4_5.c push.c reverse_rotate.c rotate.c swap.c ft_atoi.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_substr.c crealist.c 
OBJF = $(SRCF:.c=.o)

all: $(NAME)

$(NAME):$(OBJF)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJF) $(OBJBF)


fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:  clean