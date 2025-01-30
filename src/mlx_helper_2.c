/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:15:33 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/29 22:39:04 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_exit_collec(t_game *data, t_counts *elements)
{
	int	i;
	int	j;

	i = 0;
	while (data->lines[i])
	{
		j = 0;
		while (data->lines[i][j] != '\n' && data->lines[i][j] != '\0')
		{
			if (data->lines[i][j] == 'C' || data->lines[i][j] == 'E')
			{
				free(elements);
				free_split(data->lines);
				ft_error("map not valid : flodd_fill failed\n", data);
			}
			j++;
		}
		i++;
	}
}

int	cleanup_game(t_game *game)
{
	mlx_destroy_image(game->mlx.connection, game->image.wall);
	mlx_destroy_image(game->mlx.connection, game->image.coin);
	mlx_destroy_image(game->mlx.connection, game->image.img);
	mlx_destroy_image(game->mlx.connection, game->image.exit);
	mlx_destroy_image(game->mlx.connection, game->image.background);
	mlx_destroy_window(game->mlx.connection, game->mlx.window);
	mlx_destroy_display(game->mlx.connection);
	free(game->mlx.connection);
	free_split(game->lines);
	free(game);
	return (0);
}
