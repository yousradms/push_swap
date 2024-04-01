CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = push_swap

SRCF = push_swap.c parsing.c push.c reverse_rotate.c rotate.c swap.c ft_atoi.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_split.c ft_strcmp.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_substr.c crealist.c 
OBJF = $(SRCF:.c=.o)
# BONUSF =	


# OBJF = $(SRCF:.c=.o)

# OBJBF = $(BONUSF:.c=.o) 


all: $(NAME)

# bonus:$(OBJBF)
# 	ar -rc $(NAME) $(OBJBF)


$(NAME):$(OBJF)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJF) $(OBJBF)


fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:  clean