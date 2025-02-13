/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:45:11 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/13 17:26:33 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_wall_and_player(t_game *game, int i, int j)
{
	if (game->lines[i][j] == '1')
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window,
			game->image.wall, j * 64, i * 64);
	else if (game->lines[i][j] == 'P')
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window,
			game->image.img[game->player_frame], game->pos.x * 64, game->pos.y
			* 64);
}

void	put_coin_and_enemy(t_game *game, int i, int j)
{
	if (game->lines[i][j] == 'c')
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window,
			game->image.coin[game->frame], j * 64, i * 64);
	else if (game->lines[i][j] == 'N')
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window,
			game->image.enemy[game->enemy_frame], j * 64, i * 64);
}

void	display_image(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->lines[i])
	{
		j = 0;
		while (game->lines[i][j])
		{
			put_wall_and_player(game, i, j);
			put_coin_and_enemy(game, i, j);
			if (game->counts.collectives == 0 && game->lines[i][j] == 'e')
				mlx_put_image_to_window(game->mlx.connection, game->mlx.window,
					game->image.exit, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	aplly_key(int *new_x, int *new_y, t_game *game)
{
	if (game->keycode == ESC_KEY)
	{
		clean_game(game);
		exit(0);
	}
	else if (game->keycode == 'a')
		*new_x -= 1;
	else if (game->keycode == 'd')
		*new_x += 1;
	else if (game->keycode == 'w')
		*new_y -= 1;
	else if (game->keycode == 's')
		*new_y += 1;
}
