# Nom de l'exécutable
NAME = so_long

# Dossiers des sous-projets
LIBFT_DIR = libft
PRINTF_DIR = printf
MINILIBX_DIR = minilibx-linux

# Commandes et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lX11 -lXext -lm

# Trouver tous les fichiers source et objet
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Liens vers les librairies des sous-répertoires
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

# Drapeaux pour les librairies
LIBS = -L$(LIBFT_DIR) -lft \
       -L$(PRINTF_DIR) -lftprintf \
       -L$(MINILIBX_DIR) -lmlx
INC = -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MINILIBX_DIR)

# Règle par défaut
all: $(LIBFT) $(PRINTF) $(MINILIBX) $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)

# Compiler les objets
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Générer les librairies des sous-projets
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

# Nettoyer les objets et librairies compilés
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(MINILIBX_DIR) fclean

# Tout reconstruire
re: fclean all

# Pas de fichiers de sortie ici
.PHONY: all clean fclean re
