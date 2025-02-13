/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminette_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:42:51 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/13 16:31:18 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	find_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->lines[i])
	{
		j = 0;
		while (game->lines[i][j])
		{
			if (game->lines[i][j] == 'e')
			{
				game->exit_x = i;
				game->exit_y = j;
			}
			else if (game->lines[i][j] == 'c')
				game->counts.collectives++;
			j++;
		}
		i++;
	}
}

void	cover_bg(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height * 64)
	{
		j = game->width * 64;
		while (j < (game->width * 64) + 64)
		{
			mlx_pixel_put(game->mlx.connection, game->mlx.window, i, j,
				0x000000);
			j++;
		}
		i++;
	}
}

void	display_moves(t_game *game, int i)
{
	char	*moves;
	char	*str;

	str = "moves : ";
	moves = ft_itoa(i);
	str = ft_strjoin_up(str, moves);
	cover_bg(game);
	mlx_string_put(game->mlx.connection, game->mlx.window, (game->height * 64)
		/ 2, (game->width * 64) + 10, 0xFFFFFF, str);
	free(moves);
	free(str);
}
