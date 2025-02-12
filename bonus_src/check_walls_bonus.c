/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:47:23 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/12 22:44:42 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_walls(t_game *data)
{
	int	i;

	i = 0;
	while (data->lines[0][i] != '\n')
	{
		if (data->lines[0][i] != '1')
		{
			free_split(data->lines);
			ft_error("invalid map\n", data);
		}
		i++;
	}
	data->width = i;
	i = 1;
	while (data->lines[i])
	{
		if (data->lines[i][0] != '1')
		{
			free_split(data->lines);
			ft_error("invalid map\n", data);
		}
		i++;
	}
}

void	check_walls_2(t_game *data)
{
	int	i;

	i = 0;
	while (data->lines[data->height - 1][i] != '\0' && data->lines[data->height
		- 1][i] != '\n')
	{
		if (data->lines[data->height - 1][i] != '1')
		{
			free_split(data->lines);
			ft_error("invalid map\n", data);
		}
		i++;
	}
	i = 1;
	while (data->lines[i])
	{
		if (data->lines[i][data->width - 1] != '1')
		{
			free_split(data->lines);
			ft_error("invalid map\n", data);
		}
		i++;
	}
}
