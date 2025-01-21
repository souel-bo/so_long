/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:37:44 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/21 20:20:09 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
void check_count(counts *elements)
{
    if (elements->player != 1)
        ft_error("map not valid: there must be exactly one player (P)\n");
    if (elements->exit != 1)
        ft_error("map not valid: there must be exactly one exit (E)\n");
    if (elements->collectives < 1)
        ft_error("map not valid: there must be at least one collectible (C)\n");
}

counts *check_arguments(map *data)
{
    int i, j;
    counts *elements;

    elements = malloc(sizeof(counts));
    if (!elements)
        ft_error("Memory allocation failed\n");
    elements->player = 0;
    elements->exit = 0;
    elements->collectives = 0;
    i = 1;
    while (data->lines[i])
    {
        j = 1;
        while (data->lines[i][j] != '\n' && data->lines[i][j] != '\0')
        {
            char c = data->lines[i][j];
            if (!(c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'))
                ft_error("map not valid: invalid character in map\n");
            if (c == 'P')
                elements->player += 1;
            else if (c == 'C')
                elements->collectives += 1;
            else if (c == 'E')
                elements->exit += 1;
            j++;
        }
        i++;
    }
    return elements;
}
int check_map(map *data, int x, int y)
{
    counts *elements;

    check_walls(data);
    check_walls_2(data);
    elements = check_arguments(data);
    check_count(elements);
	find_player(data->lines, &x, &y);
	flood_fill(data->lines, x, y, data);
    //free(elements);
    return (1);
}
