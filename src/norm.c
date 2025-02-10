/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:17:03 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/10 12:53:12 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	cleanup_resources(t_game *game)
{
	if (game->image.wall)
		mlx_destroy_image(game->mlx.connection, game->image.wall);
	if (game->image.img)
		mlx_destroy_image(game->mlx.connection, game->image.img);
	if (game->image.coin)
		mlx_destroy_image(game->mlx.connection, game->image.coin);
	if (game->image.exit)
		mlx_destroy_image(game->mlx.connection, game->image.exit);
	if (game->image.background)
		mlx_destroy_image(game->mlx.connection, game->image.background);
	if (game->mlx.window)
		mlx_destroy_window(game->mlx.connection, game->mlx.window);
	if (game->mlx.connection)
	{
		mlx_destroy_display(game->mlx.connection);
		free(game->mlx.connection);
	}
}

int	init_window(t_game *game)
{
	game->path.x = game->width * 64;
	game->path.y = game->height * 64;
	game->mlx.connection = mlx_init();
	if (!game->mlx.connection)
		return (0);
	game->mlx.window = mlx_new_window(game->mlx.connection, game->width * 64,
			game->height * 64, "so_long_bonus");
	if (!game->mlx.window)
	{
		cleanup_resources(game);
		return (0);
	}
	return (1);
}

int	load_images(t_game *game)
{
	game->image.wall = mlx_xpm_file_to_image(game->mlx.connection,
			game->path.wall_path, &game->path.x, &game->path.y);
	if (!game->image.wall)
		return (0);
	game->image.img = mlx_xpm_file_to_image(game->mlx.connection,
			game->path.file_path, &game->path.x, &game->path.y);
	if (!game->image.img)
		return (0);
	game->image.coin = mlx_xpm_file_to_image(game->mlx.connection,
			game->path.coin_path, &game->path.x, &game->path.y);
	if (!game->image.coin)
		return (0);
	game->image.exit = mlx_xpm_file_to_image(game->mlx.connection,
			game->path.exit_path, &game->path.x, &game->path.y);
	if (!game->image.exit)
		return (0);
	game->image.background = mlx_xpm_file_to_image(game->mlx.connection,
			game->path.back_ground, &game->path.x, &game->path.y);
	if (!game->image.background)
		return (0);
	return (1);
}

void	start_game(t_game *game)
{
	draw_map(game);
	mlx_hook(game->mlx.window, 02, 1, move, game);
	mlx_hook(game->mlx.window, 17, 0, close_win, game);
	mlx_loop(game->mlx.connection);
}

int	close_win(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}
