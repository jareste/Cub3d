# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 17:10:25 by baltes-g          #+#    #+#              #
#    Updated: 2023/09/07 13:59:43 by jareste-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_bzero.c					\
		ft_isdigit.c				\
		ft_memmove.c				\
		ft_strlcpy.c				\
		ft_toupper.c				\
		ft_isalnum.c				\
		ft_isprint.c				\
		ft_memset.c					\
		ft_strlen.c					\
		ft_tolower.c				\
		ft_isalpha.c				\
		ft_memchr.c					\
		ft_strchr.c					\
		ft_strncmp.c				\
		ft_isascii.c				\
		ft_memcpy.c					\
		ft_strlcat.c				\
		ft_strrchr.c				\
		ft_strnstr.c				\
		ft_atoi.c					\
		ft_memcmp.c					\
		ft_calloc.c					\
		ft_strdup.c					\
		ft_substr.c					\
		ft_strjoin.c				\
		ft_strtrim.c				\
		ft_itoa.c					\
		ft_strmapi.c				\
		ft_striteri.c				\
		ft_putchar_fd.c				\
		ft_putstr_fd.c				\
		ft_putendl_fd.c				\
		ft_putnbr_fd.c				\
		ft_split.c					\
		ft_lstnew.c					\
		ft_lstadd_front.c			\
		ft_lstsize.c				\
		ft_lstlast.c				\
		ft_lstadd_back.c			\
		ft_lstdelone.c				\
		ft_lstclear.c				\
		ft_lstiter.c				\
		ft_lstmap.c					\
		ft_itoa_printf.c			\
		ft_printf.c					\
		ft_htoa_printf.c			\
		ft_ptoa_printf.c			\
		ft_printstr_printf.c		\
		ft_uitoa_printf.c			\
		ft_printchar_printf.c		\
		get_next_line_bonus.c		\
		get_next_line_utils_bonus.c	


OBJS	=	$(SRCS:.c=.o)

NAME	=	libft.a

LIB		=	ar rcs

INC		=	libft.h

RM		=	rm -f

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

all:	$(NAME)
 
%.o:%.c $(INC) Makefile
	@printf "        \rCompilant $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):: $(OBJS) $(INC)
	@echo
	@echo "Creant $@"
	@$(LIB) $(NAME) $(OBJS)

$(NAME)::
	@echo "Biel's Libft it's Up To Date. 😵‍💫"

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all bonus clean fclean re 

