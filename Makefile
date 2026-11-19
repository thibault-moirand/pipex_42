

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = use.c	\
	use2.c \
	use3.c \
	pipex.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
