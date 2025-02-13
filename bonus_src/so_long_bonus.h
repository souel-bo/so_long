/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:04:34 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/13 17:27:37 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ESC_KEY 65307

typedef struct s_image
{
	void		*img[8];
	void		*wall;
	void		*coin[4];
	void		*enemy[6];
	void		*exit;
	void		*background;
}				t_image;

typedef struct s_mlx
{
	void		*connection;
	void		*window;
}				t_mlx;

typedef struct t_player
{
	int			x;
	int			y;
	int			next_x;
	int			next_y;
}				t_position;

typedef struct s_t_counts
{
	int			player;
	int			exit;
	int			collectives;
}				t_counts;

typedef struct s_path
{
	char		*file_path;
	char		*wall_path;
	char		*exit_path;
	char		*back_ground;
	int			x;
	int			y;
	int			coin_x;
	int			coin_y;
}				t_paths;

typedef struct s_file
{
	int			width;
	int			height;
	char		**lines;
	char		*coins[4];
	char		*player[8];
	char		*enemy[6];
	char		*s;
	int			frame;
	int			player_frame;
	int			enemy_frame;
	int			exit_x;
	int			keycode;
	int			exit_y;
	t_mlx		mlx;
	t_image		image;
	t_position	pos;
	t_counts	counts;
	t_paths		path;
}				t_game;

int				check_file_name(const char *file_name);
void			ft_error(char *msg, t_game *data);
int				open_file(const char *file_name);
int				read_file(int fd);
t_game			*fill_t_game(int fd, const char *file_name);
void			free_split(char **split);
void			check_walls_2(t_game *data);
void			check_walls(t_game *data);
void			check_t_count(t_counts *elements, t_game *data);
t_counts		*check_arguments(t_game *data);
int				check_t_game(t_game *data, int x, int y);
void			find_player(t_game *data, int *x, int *y);
void			flood_fill(t_game *data, int x, int y);
void			check_exit_collec(t_game *data, t_counts *elements);
void			find_player(t_game *data, int *x, int *y);
void			initialize(t_game *game);
int				close_win(t_game *game);
int				move(int keycode, void *ptr);
void			handle_movement(t_game *game, int *ii, int new_x, int new_y);
int				draw_map(t_game *game);
void			put_images(t_game *game, int i, int j);
int				cleanup_game(t_game *game);
void			check_exit_collec(t_game *data, t_counts *elements);
void			cleanup_resources(t_game *game);
int				init_window(t_game *game);
int				load_images(t_game *game);
void			start_game(t_game *game);
int				get_file_lenght(char *line, int fd);
void			function(t_game *game);
void			initialize_game(t_game *game);
char			**read_files(t_game *game, int fd, char *argv, int lenght);
int				clean_game(t_game *game);
int				ft_close(t_game *game);
void			free_textures(t_game *game);
void			ft_start_game(t_game *game);
void			free_arr(char **arr);
void			get_hight(t_game *game);
void			check_asset_path(const char *path, t_game *game);
void			get_path(t_game *game);
void			get_xpm(t_game *game);
void			display_image(t_game *game);
void			find_exit(t_game *game);
void			cover_bg(t_game *game);
int				animate_coins(t_game *game);
int				animate_player(t_game *game);
int				animate_enemy(t_game *game);
int				animate(t_game *game);
void			aplly_key(int *new_x, int *new_y, t_game *game);
void			display_moves(t_game *game, int i);
void			init_coin_paths(t_game *game);
void			init_player_paths(t_game *game);
void			init_enemy_paths(t_game *game);
void			init_basic_paths(t_game *game);

#endif
