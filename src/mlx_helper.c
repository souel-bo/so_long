/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:13:34 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/13 18:01:19 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_images(t_game *game, int i, int j)
{
	if (game->lines[i][j] == '1')
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window,
			game->image.wall, j * 64, i * 64);
	else if (game->lines[i][j] == 'B' && !(i == game->pos.y
			&& j == game->pos.x))
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window,
			game->image.exit, j * 64, i * 64);
	else if (game->lines[i][j] == 'P')
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window,
			game->image.img, game->pos.x * 64, game->pos.y * 64);
	else if (game->lines[i][j] == 'V')
	{
		game->counts.collectives++;
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window,
			game->image.coin, j * 64, i * 64);
	}
}

int	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->counts.collectives = 0;
	while (game->lines[i])
	{
		j = 0;
		while (game->lines[i][j])
		{
			put_images(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

void	ext(t_game *game)
{
	mlx_loop_end(game->mlx.connection);
	ft_printf("you win\n");
	cleanup_game(game);
	exit(0);
}

void	handle_movement(t_game *game, int *ii, int new_x, int new_y)
{
	int	i;

	i = *ii;
	if (game->lines[new_y][new_x] != '1' && (game->keycode == 'a'
			|| game->keycode == 's' || game->keycode == 'd'
			|| game->keycode == 'w'))
	{
		if (game->lines[new_y][new_x] == 'V')
		{
			game->counts.collectives--;
			game->lines[new_y][new_x] = 'x';
		}
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window,
			game->image.background, (game->pos.x) * 64, (game->pos.y) * 64);
		game->pos.x = new_x;
		game->pos.y = new_y;
		ft_printf("moves : %d\n", i++);
	}
	if (game->counts.collectives == 0 && game->lines[new_y][new_x] == 'B')
		ext(game);
	*ii = i;
}

int	move(int keycode, void *ptr)
{
	t_game		*game;
	int			new_x;
	int			new_y;
	static int	ii = 1;

	game = (t_game *)ptr;
	game->keycode = keycode;
	if (game->keycode == ESC_KEY)
	{
		cleanup_game(game);
		exit(0);
	}
	new_x = game->pos.x;
	new_y = game->pos.y;
	aplly_key(game->keycode, &new_x, &new_y);
	handle_movement(game, &ii, new_x, new_y);
	draw_map(game);
	return (0);
}
