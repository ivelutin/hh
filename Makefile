# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/18 16:09:23 by ivelutin          #+#    #+#              #
#    Updated: 2017/12/12 18:49:17 by ivelutin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

SRC = \
ft_printf.c \
ft_vector.c \
ft_spec.c \
ft_parse.c \
ft_num.c \
ft_handle.c \
ft_char.c \
ft_str.c \
ft_wstr.c \
ft_xou.c \
ft_init.c \
ft_flagmod.c \
ft_bitmask.c \
ft_ladilla.c \
ft_clxou.c

LIBSRC = \
libft/ft_bzero.c \
libft/ft_memcpy.c \
libft/ft_memccpy.c \
libft/ft_memmove.c \
libft/ft_memchr.c \
libft/ft_memcmp.c \
libft/ft_strlen.c \
libft/ft_strdup.c \
libft/ft_strcpy.c \
libft/ft_strncpy.c \
libft/ft_strcat.c \
libft/ft_strncat.c \
libft/ft_strlcat.c \
libft/ft_strchr.c \
libft/ft_strrchr.c \
libft/ft_strstr.c \
libft/ft_strnstr.c \
libft/ft_strcmp.c \
libft/ft_strncmp.c \
libft/ft_atoi.c \
libft/ft_isalpha.c \
libft/ft_isdigit.c \
libft/ft_isalnum.c \
libft/ft_isascii.c \
libft/ft_isprint.c \
libft/ft_toupper.c \
libft/ft_tolower.c \
libft/ft_memalloc.c \
libft/ft_memdel.c \
libft/ft_strnew.c \
libft/ft_strdel.c \
libft/ft_strclr.c \
libft/ft_striter.c \
libft/ft_striteri.c \
libft/ft_strmap.c \
libft/ft_strmapi.c \
libft/ft_strequ.c \
libft/ft_strnequ.c \
libft/ft_strsub.c \
libft/ft_strjoin.c \
libft/ft_strtrim.c \
libft/ft_strsplit.c \
libft/ft_itoa.c \
libft/ft_putchar.c \
libft/ft_putstr.c \
libft/ft_putendl.c \
libft/ft_putnbr.c \
libft/ft_putchar_fd.c \
libft/ft_putstr_fd.c \
libft/ft_putendl_fd.c \
libft/ft_putnbr_fd.c \
libft/ft_lstnew.c \
libft/ft_lstdelone.c \
libft/ft_lstdel.c \
libft/ft_lstadd.c \
libft/ft_lstiter.c \
libft/ft_lstmap.c \
libft/ft_isspace.c\
libft/ft_memset.c\
libft/get_next_line.c\
libft/ft_itoa_base.c\
libft/ft_putwchar.c\
libft/ft_putwstr.c\
libft/ft_islower.c \
libft/ft_isupper.c \
libft/ft_realloc.c \
libft/ft_uimaxtoa_base.c \
libft/ft_imaxtoa.c \
libft/ft_findchr.c \
libft/ft_insrt_to_str.c \
libft/ft_strndup.c

OBJ = $(SRC:.c=.o)
LIBOBJ = $(LIBSRC:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

$(LIBOBJ): %.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

$(NAME): $(LIBOBJ) $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(LIBOBJ)
	@echo "\033[32mCreated libftprintf library\033[0m"

clean:
	@rm -rf $(OBJ) $(LIBOBJ)
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[32mRemoved Object files and library\033[0m"

re: fclean all

.PHONY: all clean fclean re
