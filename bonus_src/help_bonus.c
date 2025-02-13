/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:24:10 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/13 14:33:31 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	free_textures(t_game *game)
{
	int	i;

	i = 0;
	while (game->image.coin[i] && i < 4)
	{
		if (game->image.coin[i])
			mlx_destroy_image(game->mlx.connection, game->image.coin[i]);
		i++;
	}
	i = 0;
	while (game->image.img[i] && i < 8)
	{
		if (game->image.img[i])
			mlx_destroy_image(game->mlx.connection, game->image.img[i]);
		i++;
	}
	i = 0;
	while (game->image.enemy[i] && i < 6)
	{
		if (game->image.enemy[i])
			mlx_destroy_image(game->mlx.connection, game->image.enemy[i]);
		i++;
	}
}

int	clean_game(t_game *game)
{
	mlx_destroy_image(game->mlx.connection, game->image.wall);
	free_textures(game);
	mlx_destroy_image(game->mlx.connection, game->image.exit);
	mlx_destroy_image(game->mlx.connection, game->image.background);
	mlx_destroy_window(game->mlx.connection, game->mlx.window);
	mlx_destroy_display(game->mlx.connection);
	free(game->mlx.connection);
	free_split(game->lines);
	free(game);
	return (0);
}

int	ft_close(t_game *game)
{
	clean_game(game);
	exit(0);
	return (0);
}

void	ft_start_game(t_game *game)
{
	game->mlx.connection = mlx_init();
	get_hight(game);
	get_path(game);
	game->mlx.window = mlx_new_window(game->mlx.connection, game->height * 64,
			game->width * 70, "so_long_bonus");
	get_xpm(game);
	game->frame = 0;
	game->player_frame = 0;
	game->enemy_frame = 0;
	display_image(game);
	mlx_loop_hook(game->mlx.connection, animate, game);
	mlx_hook(game->mlx.window, 02, 1, move, game);
	mlx_hook(game->mlx.window, 17, 0, ft_close, game);
	mlx_loop(game->mlx.connection);
}

void	function(t_game *game)
{
	game->pos.x = 0;
	game->pos.y = 0;
	find_player(game, &game->pos.x, &game->pos.y);
	find_exit(game);
	ft_start_game(game);
}
