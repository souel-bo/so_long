/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:45:32 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/24 18:29:30 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"
#include "minilibx-linux/mlx.h"

#define ESC_KEY 65307

typedef struct file
{
	int		width;
	int		height;
	char	**lines;
	char	*s;
}	map;

typedef struct oo
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	image;

typedef struct ss
{
	void	*connection;
	void	*window;
}	game;

typedef struct counts
{
	int	player;
	int	exit;
	int	collectives;
} counts;

typedef struct player
{
	int	x;
	int	y;	
}	position;

int		check_file_name(const char *file_name);
void	ft_error(char *msg, map *data);
int		open_file(const char *file_name);
int     read_file(int fd);
map     *fill_map(int fd, const char *file_name);
void	free_split(char **split);
void	check_walls_2(map *data);
void	check_walls(map *data);
void	check_count(counts *elements, map *data);
counts	*check_arguments(map *data);
int		check_map(map *data, int x, int y);
void	find_player(map *data, int *x, int *y);
void	flood_fill(map *data, int x, int y);
void	check_exit_collec(map *data, counts *elements);

#endif
