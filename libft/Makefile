# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 16:28:26 by vgarcia           #+#    #+#              #
#    Updated: 2025/01/17 09:25:28 by vgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCFILE = ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_strlen.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strncmp.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_printf_utils.c\
		ft_printf_writechars.c\
		ft_printf_writenbrs.c\
		ft_printf.c\
		ft_strcpy.c\
		get_next_line.c

EXEC = libft.a
CC=cc
SRCDIR=srcs/
OBJDIR=.obj/
DEPDIR=.dep/
FORMAT=.c
FLAGS= -Wextra -Werror -Wall -MMD -MP

SRC= $(addprefix $(SRCDIR), $(SRCFILE))
OBJ= $(addprefix $(OBJDIR), $(SRC:$(FORMAT)=.o))
DEPS= $(addprefix $(DEPDIR),$(SRC:$(FORMAT)=.d))

-include $(DEPS)

all: $(EXEC)

$(EXEC) : $(OBJ)
	@ar rcs $(EXEC) $(OBJ)

$(OBJDIR)%.o: %$(FORMAT) libft.h Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -f $(EXEC)

clean:
	rm -rf $(OBJDIR) $(DEPDIR)

re: fclean all

.PHONY: re clean fclean all
