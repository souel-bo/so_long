/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:34:13 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/13 17:30:10 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	move(int keycode, void *ptr)
{
	t_game		*game;
	int			new_x;
	int			new_y;
	static int	ii = 1;

	game = (t_game *)ptr;
	game->keycode = keycode;
	new_x = game->pos.x;
	new_y = game->pos.y;
	aplly_key(&new_x, &new_y, game);
	handle_movement(game, &ii, new_x, new_y);
	display_image(game);
	return (0);
}

int	animate_coins(t_game *game)
{
	static int	count = 0;

	if (count % 20000 == 0)
	{
		count = 0;
		if (game->frame == 3)
			game->frame = 0;
		else
			game->frame++;
		display_image(game);
	}
	count++;
	return (0);
}

int	animate_player(t_game *game)
{
	static int	count = 0;

	if (count % 18000 == 0)
	{
		count = 0;
		if (game->player_frame == 7)
			game->player_frame = 0;
		else
			game->player_frame++;
		display_image(game);
	}
	count++;
	return (0);
}

int	animate_enemy(t_game *game)
{
	static int	count = 0;

	if (count % 18000 == 0)
	{
		count = 0;
		if (game->enemy_frame == 5)
			game->enemy_frame = 0;
		else
			game->enemy_frame++;
		display_image(game);
	}
	count++;
	return (0);
}

int	animate(t_game *game)
{
	animate_coins(game);
	animate_player(game);
	animate_enemy(game);
	return (0);
}
