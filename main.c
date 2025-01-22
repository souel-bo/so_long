/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:56:11 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/22 09:33:46 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit_collec(map *data, counts *elements)
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

int	main(int argc, char **argv)
{
	int	        fd;
	map	        *data;
    position    player;

	fd = 0;
    player.x = 0;
    player.y = 0;
    if (argc != 2)
	{
		ft_putstr_fd("invalid arguments : args should be ./so_long (map path)\n", 2);
		exit(1);
	}
	if (check_file_name(argv[1]) == 1)
		fd = open_file(argv[1]);
	else
	{
		ft_putstr_fd("map name should end up with (.ber)\n",2);
		exit(1);
	}
	if (read_file(fd) == 1)
	{
		data = fill_map(fd, argv[1]);
		if (check_map(data, player.x, player.y) == 1)
		{   int o = 0;
            while (data->lines[o])
            {
                printf("%s", data->lines[o]);
                o++;
            }
             free_split(data->lines);
             free(data);
		}
	}
		
}
