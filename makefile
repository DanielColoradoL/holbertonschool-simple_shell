CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu89
SRC = $(wildcard *.c)
NAME = hsh
RM = rm

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(SRC):
	echo "Make a clone from github"

clean:
	$(RM) -f *~ $(NAME)
