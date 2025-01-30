/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:56:11 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/30 00:30:21 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize(t_game *game)
{
	char	*ptr;

	ptr = "/home/souel-bo/Desktop/so_long/assets/background.xpm";
	game->path.file_path= "/home/souel-bo/Desktop/so_long/assets/player1.xpm";
	game->path.wall_path = "/home/souel-bo/Desktop/so_long/assets/wall.xpm";
	game->path.coin_path = "/home/souel-bo/Desktop/so_long/assets/coin2.xpm";
	game->path.exit_path = "/home/souel-bo/Desktop/so_long/assets/exit.xpm";
	game->path.back_ground = ptr;
}

void	open_game(t_game *game)
{
	initialize(game);
	if (check_t_game(game, 0, 0) == 1)
	{
		find_player(game, &game->pos.x, &game->pos.y);
		game->path.x = game->width * 32;
		game->path.y = game->height * 32;
		game->mlx.connection = mlx_init();
		game->mlx.window = mlx_new_window(game->mlx.connection, game->width
				* 32, game->height * 32, "so_long");
		if (!game->mlx.window)
			exit(0);
		game->image.wall = mlx_xpm_file_to_image(game->mlx.connection,
				game->path.wall_path, &game->path.x, &game->path.y);
		if (!game->image.wall)
			return mlx_destroy_window(game->mlx.connection, game->mlx.window), exit(0);
		game->image.img = mlx_xpm_file_to_image(game->mlx.connection,
				game->path.file_path, &game->path.x, &game->path.y);
		if (!game->image.img)
			return mlx_destroy_window(game->mlx.connection, game->mlx.window), exit(0);
		game->image.coin = mlx_xpm_file_to_image(game->mlx.connection,
				game->path.coin_path, &game->path.x, &game->path.y);
		if (!game->image.coin)
			return mlx_destroy_window(game->mlx.connection, game->mlx.window), exit(0);
		game->image.exit = mlx_xpm_file_to_image(game->mlx.connection,
				game->path.exit_path, &game->path.x, &game->path.y);
		if (!game->image.exit)
			return mlx_destroy_window(game->mlx.connection, game->mlx.window), exit(0);
		game->image.background = mlx_xpm_file_to_image(game->mlx.connection,
				game->path.back_ground, &game->path.x, &game->path.y);
		if (!game->image.background)
			return mlx_destroy_window(game->mlx.connection, game->mlx.window), exit(0);
		draw_map(game);
		mlx_hook(game->mlx.window, 02, 1, move, game);
		mlx_hook(game->mlx.window, 17, 0, close_win, game);
		mlx_loop(game->mlx.connection);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;
	char	*msg;

	fd = 0;
	msg = "invalid arguments : args should be ./so_long (map path)\n";
	if (argc != 2)
	{
		ft_putstr_fd(msg, 2);
		exit(1);
	}
	if (check_file_name(argv[1]) == 1)
		fd = open_file(argv[1]);
	else
	{
		ft_putstr_fd("map name should end up with (.ber)\n", 2);
		exit(1);
	}
	if (read_file(fd) == 1)
	{
		game = fill_t_game(fd, argv[1]);
		open_game(game);
	}
}
