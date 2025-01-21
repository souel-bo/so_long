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

int check_map(map *data)
{
    counts *elements;

    check_walls(data);
    check_walls_2(data);
    elements = check_arguments(data);
    check_count(elements);
    free(elements);
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
