/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flod_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:43:38 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/21 20:51:20 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    find_player(char **map, int *x, int *y)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map[i][j] == 'P')
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
void flood_fill(char **arr, int x, int y, map *data)
{
    if (x < 0 || y < 0 || y >= data->height - 1 || x >=  data->width - 1)
        return;
    if (arr[y][x] == '1')
        return;
    if (arr[y][x] == 'C')
        arr[y][x] = 'V';
    else if (arr[y][x] == 'E')
        arr[y][x] = 'B';
    else if (arr[y][x] == 'x')
        return;
    else
        arr[y][x] = 'x';
    flood_fill(arr, x + 1, y, data);
    flood_fill(arr, x - 1, y, data);
    flood_fill(arr, x, y + 1, data);
    flood_fill(arr, x, y - 1, data);
}
