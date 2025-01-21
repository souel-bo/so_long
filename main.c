/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:56:11 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/21 02:05:19 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(map *data)
{
	int	i, k;

	i = 0;
	while (data->lines[0][i] != '\n')
	{
		if (data->lines[0][i] != '1')
		{
			free_split(data->lines);
			free(data);
			ft_error("invalid map\n");
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
			free(data);
			ft_error("invalid map\n");
		}
		i++;
	}
	i = 0;
	while (data->lines[data->height - 1][i] != '\0' && data->lines[data->height -1][i] != '\n')
	{
		if (data->lines[data->height - 1][i] != '1')
		{
			free_split(data->lines);
			free(data);
			ft_error("invalid map\n");
		}
		i++;
	}
	i = 1;
	while (data->lines[i])
	{
		if (data->lines[i][data->width -1] != '1')
		{
			free_split(data->lines);
			free(data);
			ft_error("invalid map\n");
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	fd;
	map	*data;

	if (argc != 2)
		ft_error("invalid arguments : args should be ./so_long (map path)");
	if (check_file_name(argv[1]) == 1)
		fd = open_file(argv[1]);
	else
		ft_error("map name should end up with (.ber)");
	if (read_file(fd) == 1)
	{
		data = fill_map(fd, argv[1]);
		if (check_map(data) == 1)
		{
			printf("map valid");
			exit(EXIT_SUCCESS);
		}
	}
		
}
