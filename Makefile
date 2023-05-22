
NAME = libftprintf.a

FUNCTIONS = ft_printf.c \
			print_char.c \
			print_hex.c \
			print_nbr.c \
			print_ptr.c \
			print_str.c \
			print_uns.c

SRCS_PATH = ./srcs
INCL_PATH = ./includes

SRCS = $(addprefix $(SRC_PATH)/,$(FUNCTIONS))
OBJS = $(addprefix $(OBJ_PATH)/,$(FUNCTIONS:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all