/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:18:09 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/13 16:32:11 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	get_basic_xpm(t_game *game)
{
	game->image.wall = mlx_xpm_file_to_image(game->mlx.connection,
			game->path.wall_path, &game->path.x, &game->path.y);
	game->image.background = mlx_xpm_file_to_image(game->mlx.connection,
			game->path.back_ground, &game->path.x, &game->path.y);
	game->image.exit = mlx_xpm_file_to_image(game->mlx.connection,
			game->path.exit_path, &game->path.x, &game->path.y);
}

void	get_coin_xpm(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->image.coin[i] = mlx_xpm_file_to_image(game->mlx.connection,
				game->coins[i], &game->path.x, &game->path.y);
		i++;
	}
}

void	get_player_xpm(t_game *game)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		game->image.img[j] = mlx_xpm_file_to_image(game->mlx.connection,
				game->player[j], &game->path.x, &game->path.y);
		j++;
	}
}

void	get_enemy_xpm(t_game *game)
{
	int	k;

	k = 0;
	while (k < 6)
	{
		game->image.enemy[k] = mlx_xpm_file_to_image(game->mlx.connection,
				game->enemy[k], &game->path.x, &game->path.y);
		k++;
	}
}

void	get_xpm(t_game *game)
{
	get_basic_xpm(game);
	get_coin_xpm(game);
	get_player_xpm(game);
	get_enemy_xpm(game);
}
