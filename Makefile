EXEC=ft_malcolm
FLAGS= -Wextra -Werror -Wall -MMD -MP
CC=cc
LANG=.c

SRCDIR=srcs/
INCDIR=includes/
LIBDIR=libft/
OBJDIR=.obj/
DEPDIR=.dep/

SRC= main
SRC= $(addsuffix $(LANG), $(SRC))
OBJ= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DEPS= $(addprefix $(DEPDIR)/,$(SRC:.c=.d))

-include $(DEPS)

LIBFT=$(LIBDIR)libft.a

all: $(EXEC)

$(EXEC) : $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -o $@ $(LIBFT)

$(LIBFT):
	# a voir comment call make $(MAKE) ?

%.o: %.c 
	mkdir -p $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm $(EXEC)
	make fclean # a foutre dans le libfft

clean:
	rm -r $(OBJDIR) $(DEPDIR)

re: fclean all

.PHONY: re clean fclean all





