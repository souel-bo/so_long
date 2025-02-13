/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:53:01 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/13 17:24:54 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	err(char *msg, char *msg2)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(msg2, 2);
	exit(1);
}

void	handle_game_end(t_game *game, int new_x, int new_y)
{
	if (game->lines[new_y][new_x] == 'N')
	{
		printf("Game Over\n");
		clean_game(game);
		exit(1);
	}
	else
	{
		printf("You Won\n");
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window,
			game->image.exit, game->exit_y * 64, game->exit_x * 64);
	}
	clean_game(game);
	exit(0);
}

void	handle_movement(t_game *game, int *ii, int new_x, int new_y)
{
	int	i;

	i = *ii;
	if (game->lines[new_y][new_x] != '1' && (game->keycode == 'a'
			|| game->keycode == 's' || game->keycode == 'd'
			|| game->keycode == 'w'))
	{
		if (game->lines[new_y][new_x] == 'c')
		{
			game->counts.collectives--;
			game->lines[new_y][new_x] = 'x';
		}
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window,
			game->image.background, (game->pos.x) * 64, (game->pos.y) * 64);
		game->pos.x = new_x;
		game->pos.y = new_y;
		display_moves(game, i++);
	}
	if ((game->lines[new_y][new_x] == 'e' && game->counts.collectives == 0)
		|| game->lines[new_y][new_x] == 'N')
		handle_game_end(game, new_x, new_y);
	*ii = i;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;
	char	*msg;
	char	*msg2;

	fd = 0;
	msg = "Error\n";
	msg2 = "invalid arguments : args should be ./so_long_bonus (map path)\n";
	if (argc != 2)
		err(msg, msg2);
	if (check_file_name(argv[1]) == 1)
		fd = open_file(argv[1]);
	else
	{
		ft_putstr_fd("Error\nmap name should end up with (.ber)\n", 2);
		exit(1);
	}
	if (read_file(fd) == 1)
	{
		game = fill_t_game(fd, argv[1]);
		game->counts.collectives = 0;
		if (check_t_game(game, 0, 0) == 1)
			function(game);
	}
}
