# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 18:04:28 by ehosta            #+#    #+#              #
#    Updated: 2025/02/26 15:54:43 by ehosta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

MAKE_DIR	:=	.make/
override	BUILD_DIR	:=	$(MAKE_DIR)$(shell git branch --show-current)/
override	SRC_DIR		:=	src/
override	SRCS		:=	main
override	SRC			:=	$(addprefix $(SRC_DIR),$(addsuffix .c,$(SRCS)))
override	OBJ			:=	$(patsubst $(SRC_DIR)%.c,$(BUILD_DIR)%.o,$(SRC))
override	DEPS		:=	$(patsubst %.o,%.d,$(OBJ))
override	DIRS		:=	$(sort $(dir $(NAME) $(OBJ) $(DEPS)))

override	LIBFT		:=	libft/
override	MLX			:=	mlx/

OFLAGS		:=	-O3
CFLAGS		:=	-Wall -Wextra -Werror -MMD -MP -g3
MAKEFLAGS	:=	--no-print-directory
RMFLAGS		:=	-rf
override	GCC		:=	cc
override	RM		:=	rm

.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT)libft.a $(MLX)libmlx.a $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)libft.a $(MLX)libmlx.a -Lmlx/ -lXext -lX11 -lm -o $(NAME)

$(LIBFT)libft.a: libft

$(MLX)libmlx.a: mlx

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(DIRS)
	$(CC) $(CFLAGS) -Iinclude/ -Ilibft/include -Imlx/ -c $< -o $@

.PHONY: mlx
mlx: force
	make -C mlx all

.PHONY: libft
libft: force
	make -C $(LIBFT) all

.PHONY: force
force:
	@true

.PHONY: clean
clean:
	make -C $(LIBFT) clean
	$(RM) $(RMFLAGS) $(BUILD_DIR)

.PHONY: fclean
fclean:
	make -C $(LIBFT) fclean
	$(RM) $(RMFLAGS) $(NAME) $(MAKE_DIR)

.PHONY : re
re: fclean
	$(MAKE)

$(DIRS):
	@mkdir -p $@

-include $(DEPS)