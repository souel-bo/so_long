/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:56:11 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/25 04:49:36 by souel-bo         ###   ########.fr       */
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

int check_key(int button, void *data_ptr)
{
	game *data = data_ptr;

    if (button == ESC_KEY)
    {
        mlx_destroy_window(data->connection, data->window);
        exit(0);
    }
    return 0;
}
int exit_button(void *par)
{
	(void)par;
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	int	        fd;
	map	        *data;
    position    player;
	game		window;
	image		player_image;
	char *file_path = "character.xpm";

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
		{
			int image_width = /*data->width */ 64;
			int image_height = /*data->height */ 64;
			window.connection = mlx_init();
			window.window = mlx_new_window(window.connection, data->width * 64, data->height * 64, "so_long");
			mlx_key_hook(window.window, check_key, &window);
			player_image.img = mlx_xpm_file_to_image(window.connection, file_path, &image_width, &image_height);
			mlx_put_image_to_window(window.connection, window.window, player_image.img, 32, 32);
			mlx_hook(window.window, 17, 0, exit_button, NULL);
			mlx_loop(window.connection);
			// free_split(data->lines);
            // free(data);
		}
	}
}
