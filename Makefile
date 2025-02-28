# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 18:04:28 by ehosta            #+#    #+#              #
#    Updated: 2025/02/28 16:33:51 by ehosta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

MAKE_DIR	:=	.make/
override	BUILD_DIR	:=	$(MAKE_DIR)$(shell git branch --show-current)/
override	SRC_DIR		:=	src/
override	PARSING_SRC	:=	check_file check_lines check_map check_xpm \
							create_map init_so_long
override	RENDER_SRC	:=	init_game render_map game_hooks display
override	UTILS_SRC	:=	fd tile xpm toolbox errors
override	SRCS		:=	main $(addprefix parsing/,$(PARSING_SRC)) \
							$(addprefix rendering/,$(RENDER_SRC)) \
							$(addprefix utils/,$(UTILS_SRC))
override	SRC			:=	$(addprefix $(SRC_DIR),$(addsuffix .c,$(SRCS)))
override	OBJ			:=	$(patsubst $(SRC_DIR)%.c,$(BUILD_DIR)%.o,$(SRC))
override	DEPS		:=	$(patsubst %.o,%.d,$(OBJ))
override	DIRS		:=	$(sort $(dir $(NAME) $(OBJ) $(DEPS)))

override	LIBFT		:=	lib/
override	MLX			:=	minilibx/

OFLAGS		:=	-O3
CFLAGS		:=	-Wall -Wextra -Werror -MMD -MP -g3
MAKEFLAGS	:=	--no-print-directory
RMFLAGS		:=	-rf
override	GCC		:=	cc
override	RM		:=	rm

.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT)libft.a $(MLX)libmlx.a $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)libft.a $(MLX)libmlx.a -L$(MLX)/ -lXext -lX11 -lm -o $(NAME)

$(LIBFT)libft.a: libft

$(MLX)libmlx.a: mlx

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(DIRS)
	$(CC) $(CFLAGS) -Iinclude/ -I$(LIBFT)/include -I$(MLX)/ -c $< -o $@

.PHONY: mlx
mlx: force
	make -C $(MLX) all

.PHONY: libft
libft: force
	make -C $(LIBFT) all

.PHONY: force
force:
	@true

.PHONY: clean
clean:
	make -C $(LIBFT) clean
	make -C $(MLX) clean
	$(RM) $(RMFLAGS) $(BUILD_DIR)

.PHONY: fclean
fclean: clean
	make -C $(LIBFT) fclean
	$(RM) $(RMFLAGS) $(NAME) $(MAKE_DIR)

.PHONY : re
re: fclean
	$(MAKE)

$(DIRS):
	@mkdir -p $@

-include $(DEPS)