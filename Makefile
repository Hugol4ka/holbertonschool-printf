# Compilation
CC = gcc
# Options de sécurité
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
# Fichiers sources
SRC = _printf.c \
      get_print_func.c \
      print_char.c \
      print_string.c \
      print_percent.c \
      print_int.c \
      print_base.c \
      print_float.c

OBJ = $(SRC:.c=.o)
NAME = libprintf.a # Ou le nom de ton exécutable si tu as un main.c

# Règle par défaut
all: $(NAME)

# Création d'une bibliothèque statique (souvent demandé pour printf)
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

# Règle pour compiler les fichiers .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJ)

# Nettoyage complet
fclean: clean
	rm -f $(NAME)

# Re-compiler de zéro
	re: fclean all