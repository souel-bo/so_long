/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:56:11 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/28 22:02:41 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	check_exit_collec(t_game *data, t_counts *elements)
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
int draw_map (t_game *game)
{	
	int i = 0;
	int j;
	game->counts.collectives = 0;
	while (game->lines[i])
		{
			j = 0;
			while (game->lines[i][j])
			{
				if (game->lines[i][j] == '1')
					mlx_put_image_to_window(game->mlx.connection, game->mlx.window, game->image.wall, j * 32, i * 32);
				else if (game->lines[i][j] == 'B' && !(i == game->pos.y && j == game->pos.x))
					mlx_put_image_to_window(game->mlx.connection, game->mlx.window, game->image.exit, j * 32, i * 32);
				else if (game->lines[i][j] == 'P')
					mlx_put_image_to_window(game->mlx.connection, game->mlx.window, game->image.img, game->pos.x * 32, game->pos.y * 32);
				else if (game->lines[i][j] == 'V')
				{
					game->counts.collectives++;
					mlx_put_image_to_window(game->mlx.connection, game->mlx.window, game->image.coin, j * 32, i * 32);
				}
				j++;
			}
			i++;
		}
		return 0;
}

int move(int keycode, void *ptr)
{
    t_game *game = (t_game *)ptr;
	static int i = 0;
	printf("moves==>%d\n", i++);
    if (keycode == ESC_KEY)
	{
		free_split(game->lines);
        return (mlx_destroy_window(game->mlx.connection, game->mlx.window),exit(0), 0);
	}
    int new_x = game->pos.x;
    int new_y = game->pos.y;

    if (keycode == LEFT_ROW)
        new_x -= 1;
    else if (keycode == RIGHT_ROW)
        new_x += 1;
    else if (keycode == UP_ROW)
        new_y -= 1;
    else if (keycode == DOWN_ROW)
        new_y += 1;

    if (game->lines[new_y][new_x] != '1')
    {
        if (game->lines[new_y][new_x] == 'V')
		{
			game->counts.collectives--;
            game->lines[new_y][new_x] = 'x';
		}
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window, game->image.background, (game->pos.x) * 32, (game->pos.y) * 32);
        game->pos.x = new_x;
        game->pos.y = new_y;
    }
	if (game->counts.collectives == 0 && game->lines[new_y][new_x] == 'B')
	{
		printf("you win\n");
		mlx_destroy_image(game->mlx.connection, game->image.coin);
		mlx_destroy_image(game->mlx.connection, game->image.img);
		mlx_destroy_image(game->mlx.connection, game->image.exit);
		mlx_destroy_image(game->mlx.connection, game->image.wall);
		mlx_loop_end(game->mlx.connection);
		mlx_destroy_display(game->mlx.connection);
		// free(game->image.wall);
		// free(game->image.coin);
		// free(game->image.img);
		// free(game->image.exit);
		free_split(game->lines);
		free(game);
		return (exit(0), 0);
	}
    draw_map(game);

    return 0;
}

int close_win(t_game *game)
{
    mlx_destroy_window(game->mlx.connection, game->mlx.window); // Destroy the window
    exit(0); // Exit the program
    return (0);
}

int	main(int argc, char **argv)
{
	int	        fd;
	t_game	        *game;
	char *file_path = "player1.xpm";
	char *wall_path = "wall.xpm";
	char *coin_path = "coin2.xpm";
	char *exit_path = "exit.xpm";
	char *back_ground = "background.xpm";
	
	
	fd = 0;
    if (argc != 2)
	{
		ft_putstr_fd("invalid arguments : args should be ./so_long (t_game path)\n", 2);
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
		game = fill_t_game(fd, argv[1]);
		if (check_t_game(game, 0, 0) == 1)
		{
			find_player(game, &game->pos.x, &game->pos.y);
			int x = game->width * 32;
			int y = game->height * 32;
			game->mlx.connection = mlx_init();
			game->mlx.window = mlx_new_window(game->mlx.connection, game->width * 32, game->height *32, "so_long");
			game->image.wall = mlx_xpm_file_to_image(game->mlx.connection, wall_path, &x, &y);
			game->image.img = mlx_xpm_file_to_image(game->mlx.connection, file_path, &x, &y);
			game->image.coin = mlx_xpm_file_to_image(game->mlx.connection, coin_path, &x, &y);
			game->image.exit = mlx_xpm_file_to_image(game->mlx.connection, exit_path, &x, &y);
			game->image.background = mlx_xpm_file_to_image(game->mlx.connection, back_ground, &x, &y);
			draw_map(game);
			//mlx_key_hook(game->mlx.window, move, game);
			mlx_hook(game->mlx.window, 02, 1, move , game);
			mlx_hook(game->mlx.window, 17, 0, close_win , game);
			mlx_loop(game->mlx.connection);
		}
	}
}
