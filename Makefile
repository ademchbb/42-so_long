# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/15 12:04:05 by adchebbi          #+#    #+#              #
#    Updated: 2026/04/15 13:02:55 by adchebbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************** PROGRAM **************** #
#                                           #
NAME        = so_long
#                                           #
# ***************************************** #


# **************** COMPILER *************** #
#                                           #
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
#                                           #
# ***************************************** #


# ************* DIRECTORIES *************** #
#                                           #
SRC_DIR     = src
INC_DIR     = include
LIBFT_DIR   = libft
MLX_DIR     = minilibx-linux
#                                           #
# ***************************************** #


# **************** FILES ****************** #
#                                           #
SRCS        = $(SRC_DIR)/main.c \
              $(SRC_DIR)/parsing.c \
              $(SRC_DIR)/map_check.c \
              $(SRC_DIR)/flood_fill.c \
              $(SRC_DIR)/game_init.c \
              $(SRC_DIR)/render.c \
              $(SRC_DIR)/movement.c \
              $(SRC_DIR)/cleanup.c
#                                           #
OBJS        = $(SRCS:.c=.o)
#                                           #
LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx_Linux.a
#                                           #
MLX_FLAGS   = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
#                                           #
# ***************************************** #


# **************** COLORS ***************** #
#                                           #
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
RED         = \033[0;31m
BLUE        = \033[0;34m
RESET       = \033[0m
#                                           #
# ***************************************** #


# **************** RULES ****************** #
#                                           #
all: $(LIBFT) $(MLX) $(NAME)
#                                           #
$(LIBFT):
	@printf "$(YELLOW)📚 Compiling libft...$(RESET)\n"
	@make -C $(LIBFT_DIR) --silent
	@printf "$(GREEN)✅ Libft ready$(RESET)\n"
#                                           #
$(MLX_DIR):
	@printf "$(YELLOW)📥 Cloning MiniLibX...$(RESET)\n"
	@git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR) --quiet
	@printf "$(GREEN)✅ MiniLibX cloned$(RESET)\n"

$(MLX): | $(MLX_DIR)
	@printf "$(YELLOW)📚 Compiling mlx...$(RESET)\n"
	@chmod +x $(MLX_DIR)/configure
	@make -C $(MLX_DIR) --silent
	@printf "$(GREEN)✅ MLX ready$(RESET)\n"
#                                           #
$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@printf "$(BLUE)🔧 Linking $(NAME)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@printf "$(GREEN)✅ $(NAME) compiled successfully$(RESET)\n"
#                                           #
%.o: %.c
	@printf "$(YELLOW)🔨 Compiling $<$(RESET)\n"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@
#                                           #
clean:
	@printf "$(RED)🧹 Cleaning object files$(RESET)\n"
	@make clean -C $(LIBFT_DIR) --silent
	@[ -d $(MLX_DIR) ] && make clean -C $(MLX_DIR) --silent || true
	@$(RM) $(OBJS)
#                                           #
fclean: clean
	@printf "$(RED)🧼 Full clean$(RESET)\n"
	@make fclean -C $(LIBFT_DIR) --silent
	@$(RM) $(NAME)
	@sleep 1
	@clear
#                                           #
re: fclean all
#                                           #
.PHONY: all clean fclean re
#                                           #
# ***************************************** #