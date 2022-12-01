MLX = minilibx-linux/minilibx.a
LIBFT = libft/libft.a

$(MLX):
	make -C minilibx-linux

$(LIBFT):
	make -C libft

$(NAME): $(MLX)
	$(CC) -c $(SRCS) -l$(MLX) -l$(LIBFT) -o $(NAME)

clean:
	make -C minilibx-linux clean
	make -C libft clean
