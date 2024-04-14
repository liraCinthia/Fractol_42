LIBFT_PATH		=	./libraries/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./libraries/minilibx-linux
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	main.c color.c event_hooks.c fractol_m_j.c fractol.c mlx_handler.c utils.c

SOURCES_DIR		=	sources

OBJ_DIR			=	objects

HEADER			=	./include/fractol.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			=	$(SOURCES:$(SOURCES_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME			=	fractol

CC				=	cc
RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-L. -lXext -L. -lX11


$(OBJ_DIR)/%.o:		$(SOURCES_DIR)/%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJ_DIR) $(MINILIBX) $(OBJECTS) $(HEADER)
					$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) \
					$(MLXFLAGS) -lm -o $(NAME)

$(LIBFT):
					$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
					$(MAKE) -C $(MINILIBX_PATH)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(MAKE) -C $(LIBFT_PATH) clean
					$(MAKE) -C $(MINILIBX_PATH) clean
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(MAKE) -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft minilibx
