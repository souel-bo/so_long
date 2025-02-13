/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flod_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:43:38 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/13 18:01:32 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_player(t_game *data, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (data->lines[i])
	{
		j = 0;
		while (data->lines[i][j] != '\0')
		{
			if (data->lines[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_game *data, int x, int y)
{
	if (x < 0 || y < 0 || y >= data->height - 1 || x >= data->width - 1)
		return ;
	if (data->lines[y][x] == '1' || data->lines[y][x] == 'x'
		|| data->lines[y][x] == 'V' || data->lines[y][x] == 'B'
		|| data->lines[y][x] == '3')
		return ;
	if (data->lines[y][x] == '1')
		return ;
	else if (data->lines[y][x] == 'C')
		data->lines[y][x] = 'V';
	else if (data->lines[y][x] == 'E')
		data->lines[y][x] = 'B';
	else if (data->lines[y][x] == 'P')
		data->lines[y][x] = 'P';
	else if (data->lines[y][x] == 'x')
		return ;
	else
		data->lines[y][x] = 'x';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}

void	aplly_key(int keycode, int *new_x, int *new_y)
{
	if (keycode == 'a')
		*new_x -= 1;
	else if (keycode == 'd')
		*new_x += 1;
	else if (keycode == 'w')
		*new_y -= 1;
	else if (keycode == 's')
		*new_y += 1;
}
