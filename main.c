/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:56:11 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/21 18:58:11 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(int argc, char **argv)
{
	int	        fd;
	map	        *data;
    position    player;

	fd = 0;
    player.x = 0;
    player.y = 0;
    if (argc != 2)
		ft_error("invalid arguments : args should be ./so_long (map path)");
	if (check_file_name(argv[1]) == 1)
		fd = open_file(argv[1]);
	else
		ft_error("map name should end up with (.ber)");
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
            // free_split(data->lines);
            // free(data);
			// printf("map valid");
			// exit(EXIT_SUCCESS);
		}
	}
		
}
