/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:56:11 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/01 00:17:27 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize(t_game *game)
{
	char	*ptr;

	ptr = "/home/souel-bo/Desktop/so_long/assets/background.xpm";
	game->path.file_path = "/home/souel-bo/Desktop/so_long/assets/player1.xpm";
	game->path.wall_path = "/home/souel-bo/Desktop/so_long/assets/wall.xpm";
	game->path.coin_path = "/home/souel-bo/Desktop/so_long/assets/coin2.xpm";
	game->path.exit_path = "/home/souel-bo/Desktop/so_long/assets/exit.xpm";
	game->path.back_ground = ptr;
}

int	check_assets_paths(t_game *game)
{
	int	fd;

	fd = open(game->path.wall_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open(game->path.file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open(game->path.coin_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open(game->path.exit_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open(game->path.back_ground, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

void	open_game(t_game *game)
{
	initialize(game);
	if (!check_assets_paths(game))
	{
		free_split(game->lines);
		free(game);
		ft_printf("Error\nInvalid assets path\n");
		exit(0);
	}
	if (check_t_game(game, 0, 0) == 1)
	{
		find_player(game, &game->pos.x, &game->pos.y);
		if (!init_window(game))
			return ;
		if (!load_images(game))
		{
			cleanup_resources(game);
			return ;
		}
		start_game(game);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;
	char	*msg;

	fd = 0;
	msg = "invalid arguments : args should be ./so_long (map path)\n";
	if (argc != 2)
	{
		ft_putstr_fd(msg, 2);
		exit(1);
	}
	if (check_file_name(argv[1]) == 1)
		fd = open_file(argv[1]);
	else
	{
		ft_putstr_fd("map name should end up with (.ber)\n", 2);
		exit(1);
	}
	if (read_file(fd) == 1)
	{
		game = fill_t_game(fd, argv[1]);
		open_game(game);
	}
}
