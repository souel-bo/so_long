/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_bonus_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:16:51 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/13 16:31:56 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	get_file_lenght(char *line, int fd)
{
	int	i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char	**read_files(t_game *game, int fd, char *argv, int lenght)
{
	char	**str;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("failed to open");
		exit(1);
	}
	str = malloc(sizeof(char *) * (lenght + 1));
	i = 0;
	game->s = get_next_line(fd);
	while (game->s && i < lenght)
	{
		str[i] = game->s;
		i++;
		game->s = get_next_line(fd);
	}
	free(game->s);
	str[i] = NULL;
	return (str);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	get_hight(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->lines[i])
	{
		j = 0;
		while (game->lines[i][j] != '\n' && game->lines[i][j] != '\0')
			j++;
		i++;
	}
	game->height = j;
	game->width = i;
}

void	check_asset_path(const char *path, t_game *game)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free_arr(game->lines);
		mlx_destroy_display(game->mlx.connection);
		free(game->mlx.connection);
		free(game);
		ft_putstr_fd("Error\nAsset file not found or not readable", 2);
		exit(EXIT_FAILURE);
	}
	close(fd);
}
