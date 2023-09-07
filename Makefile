# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 00:35:07 by jsebasti          #+#    #+#              #
#    Updated: 2023/09/07 13:52:44 by jareste-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= cub3D
INC_DIR		= INC
LIB_DIR		= LIB
MKFL		= Makefile
SRC_DIR		= SRC/
OBJ_DIR		= OBJ/

MLX			= libmlx.a

INC_MLX		= mlx.h

# ----Libraryes----
PW_HEADER	= $(INC_DIR)/cub3d.h
LIB			= $(LIB_DIR)/libft/libft.a
LIB_L 		= $(LIB_DIR)/libft/

# =============

ifeq ($(shell uname -s),Linux)
	MLX_DIR		= LIB/minilibx_linux
	MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	MLX_FLAGS	= -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm
	MLX_CC		= -I/usr/include -I$(MLX_DIR)
	LIB_M 		= $(LIB_DIR)/minilibx_linux/
else
	MLX_DIR		= LIB/minilibx_opengl_20191021
	MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	LIB_M 		= $(LIB_DIR)/minilibx_opengl_20191021/
endif


# -------------
RM = rm -rf
MP = mkdir -p
CFLAGS = -g -Wall -Wextra -Werror
LIBC = ar -rcs
CC = clang
# =============

SRC_L	=	main.c					\
			PARSE/parse.c			\
			PARSE/colour.c			\
			PARSE/map.c				\
			PARSE/textures.c		\
			PARSE/utils.c			\
			PARSE/utils2.c			\
			PARSE/init.c			\
			PARSE/aux_setup_pl.c	\
			HOOKS/hooks.c			\
			HOOKS/wasd_hooks.c		\
			HOOKS/rot_hooks.c		\
			RENDER/draw_vertical.c	\
			RENDER/render.c			\
			RENDER/texture.c		\
			RENDER/pixel.c			\
			RENDER/minmap.c			\

SRC = $(addprefix $(SRC_DIR), $(SRC_L))

# -------------
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
# =============

all:
	@$(MAKE) -C $(LIB_L) --no-print-directory
	@$(MAKE) -C $(LIB_M) --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)%.o: %.c $(MKFL)
	@$(MP) $(dir $@)
	@printf "                       \rCompiling $<"
	@$(CC) $(CFLAGS) -MMD -I $(INC_DIR) $(MLX_CC) -c $< -o $@

$(NAME):: $(OBJ) $(LIB)
	@printf "\nLinking cub3d\n"
	@$(CC)  $(CFLAGS) $(OBJ) $(LIB) $(MLX_FLAGS) -o $(NAME)

$(NAME)::
	@echo "Hello, cub3d already compiled "

-include $(DEP)

clean:
	@$(MAKE) clean -C $(LIB_M) --no-print-directory
	@$(MAKE) clean -C $(LIB_L) --no-print-directory
	$(RM) $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIB_L) --no-print-directory
	@$(MAKE) clean -C $(LIB_M) --no-print-directory
	$(RM) $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) --no-print-directory

.PHONY: all clean fclean re
