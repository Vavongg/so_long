NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
LFLAGS = libmlx.a libmlx_Linux.a -lX11 -lXext

SRC = 	src/main.c \
		src/parsing/check_map.c src/parsing/load_map.c src/parsing/parsing.c \
		src/utils/get_next_line.c src/utils/ft_utils1.c src/utils/ft_utils2.c src/utils/free_errors.c \

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

RESET = \033[0m
BOLD = \033[1m
GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m
CYAN = \033[36m
BLUE = \033[34m

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/src
	@echo "$(CYAN)───────────────────────────────$(RESET)"
	@echo "$(BOLD)📁 Création du dossier objet...$(RESET)"
	@echo "$(CYAN)───────────────────────────────$(RESET)"

$(NAME): $(OBJ)
	@$(MAKE) --no-print-directory -C minilibx-linux/ > /dev/null 2>&1 && mv minilibx-linux/libmlx.a . && mv minilibx-linux/libmlx_Linux.a .
	@echo "$(BLUE)⚙️  Compilation de la MiniLibX terminée$(RESET)"
	@$(CC) $(OBJ) -o $@ $(LFLAGS)
	@echo "$(GREEN)✅ Compilation réussie !$(RESET)"
	@echo "$(CYAN)───────────────────────────────$(RESET)"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)⚙️  Compilation : $<$(RESET)"

clean:
	@make -C minilibx-linux clean > /dev/null 2>&1
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Suppression des fichiers objets terminée.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f libmlx.a libmlx_Linux.a
	@echo "$(RED)Suppression de l'exécutable $(NAME) et des bibliothèques libmlx.a et libmlx_Linux.a.$(RESET)"


re: fclean all

.PHONY: all clean fclean re bonus
