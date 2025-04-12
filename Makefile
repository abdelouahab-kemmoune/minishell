NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = lexer.c minishell.c parsing.c ./libft/ft_strdup.c ./libft/strndup.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $@ 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
