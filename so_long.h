/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:45:32 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/28 19:41:26 by souel-bo         ###   ########.fr       */
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
#define UP_ROW 65362
#define DOWN_ROW 65364
#define RIGHT_ROW 65363
#define LEFT_ROW 65361

typedef struct s_image
{
	void	*img;
	void 	*wall;
	void	*coin;
	void	*exit;
	void	*background;
}	t_image;

typedef struct s_mlx
{
	void	*connection;
	void	*window;
}	t_mlx;

typedef struct t_player
{
	int	x;
	int	y;
	int next_x;
	int next_y;
}	t_position;

typedef struct s_t_counts
{
	int	player;
	int	exit;
	int	collectives;
} t_counts;

typedef struct s_file
{
	int		width;
	int		height;
	char	**lines;
	char	*s;
	t_mlx	mlx;
	t_image	image;
	t_position	pos;
	t_counts		counts;
}	t_game;





int		check_file_name(const char *file_name);
void	ft_error(char *msg, t_game *data);
int		open_file(const char *file_name);
int     read_file(int fd);
t_game     *fill_t_game(int fd, const char *file_name);
void	free_split(char **split);
void	check_walls_2(t_game *data);
void	check_walls(t_game *data);
void	check_t_count(t_counts *elements, t_game *data);
t_counts	*check_arguments(t_game *data);
int		check_t_game(t_game *data, int x, int y);
void	find_player(t_game *data, int *x, int *y);
void	flood_fill(t_game *data, int x, int y);
void	check_exit_collec(t_game *data, t_counts *elements);
void    find_player(t_game *data, int *x, int *y);

#endif
