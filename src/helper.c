/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:37:44 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/10 12:52:55 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	check_t_count(t_counts *elements, t_game *data)
{
	if (elements->player != 1)
	{
		free(elements);
		free_split(data->lines);
		ft_error("map not valid: there must be exactly one player (P)\n", data);
	}
	if (elements->exit != 1)
	{
		free(elements);
		free_split(data->lines);
		ft_error("map not valid: there must be exactly one exit (E)\n", data);
	}
	if (elements->collectives < 1)
	{
		free(elements);
		free_split(data->lines);
		ft_error("map not valid: there must be at least one collectible (C)\n",
			data);
	}
}

static void	count_elements(t_counts *elements, char c, t_game *data)
{
	if (!(c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'))
	{
		free(elements);
		ft_error("map not valid: invalid character in map\n", data);
	}
	if (c == 'P')
		elements->player += 1;
	else if (c == 'C')
		elements->collectives += 1;
	else if (c == 'E')
		elements->exit += 1;
}

t_counts	*check_arguments(t_game *data)
{
	t_counts	*elements;
	int			i;
	int			j;

	elements = malloc(sizeof(t_counts));
	if (!elements)
		ft_error("Memory allocation failed\n", data);
	elements->player = 0;
	elements->exit = 0;
	elements->collectives = 0;
	i = 1;
	while (data->lines[i])
	{
		j = 1;
		while (data->lines[i][j] != '\n' && data->lines[i][j] != '\0')
		{
			count_elements(elements, data->lines[i][j], data);
			j++;
		}
		i++;
	}
	return (elements);
}

int	check_t_game(t_game *data, int x, int y)
{
	t_counts	*elements;

	check_walls(data);
	check_walls_2(data);
	elements = check_arguments(data);
	check_t_count(elements, data);
	find_player(data, &x, &y);
	flood_fill(data, x, y);
	check_exit_collec(data, elements);
	free(elements);
	return (1);
}
