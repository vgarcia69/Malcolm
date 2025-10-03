EXEC=ft_malcolm
CC=cc
FORMAT=.c
SRCDIR=srcs/
INCDIR=includes/
LIBDIR=libft/
OBJDIR=.obj/
DEPDIR=.dep/

FLAGS= -Wextra -Werror -Wall -I$(INCDIR) -MMD -MP

SRCFILE= main address

SRC= $(addprefix $(SRCDIR), $(addsuffix $(FORMAT), $(SRCFILE)))
OBJ= $(addprefix $(OBJDIR), $(SRC:$(FORMAT)=.o))
DEPS= $(addprefix $(DEPDIR),$(SRC:$(FORMAT)=.d))

-include $(DEPS)

LIBFT=$(LIBDIR)libft.a

all: $(EXEC)

$(EXEC) : $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) -o $@ $(LIBFT)

$(LIBFT):
	$(MAKE) --no-print-directory -C $(LIBDIR)

$(OBJDIR)%.o: %$(FORMAT) $(INCDIR) Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -f $(EXEC)
	$(MAKE) --no-print-directory fclean -C $(LIBDIR)

clean:
	rm -rf $(OBJDIR) $(DEPDIR)

re: fclean all

.PHONY: re clean fclean all





