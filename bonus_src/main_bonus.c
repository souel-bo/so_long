/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:53:01 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/13 04:32:34 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	err(char *msg, char *msg2)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(msg2, 2);
	exit(1);
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
