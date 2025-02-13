/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:45:11 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/13 13:14:47 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int get_file_lenght(char *line, int fd)
{
    int i = 0;
    line = get_next_line(fd);
    while (line)
    {
        i++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return i;
}
char **read_files(t_game *game, int fd, char *argv, int lenght)
{
    fd = open(argv, O_RDONLY);
    if (fd == -1)
    {
        perror("failed to open");
        exit(1);
    }
    char **str;
    str = malloc(sizeof(char *) * (lenght + 1));
    int i = 0;
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

void free_arr(char **arr)
{
    int i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}
void get_hight(t_game *game)
{
    int i = 0;
    int j;
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

void check_asset_path(const char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        ft_putstr_fd("Error\nAsset file not found or not readable", 2);
        exit(EXIT_FAILURE);
    }
    close(fd);
}
void get_path(t_game *game)
{
    game->coins[0] = "./bonus_assets/collectives/red_crystal_1.xpm";
    game->coins[1] = "./bonus_assets/collectives/red_crystal_2.xpm";
    game->coins[2] = "./bonus_assets/collectives/red_crystal_3.xpm";
    game->coins[3] = "./bonus_assets/collectives/red_crystal_4.xpm";

    game->path.wall_path = "./bonus_assets/wall/wall.xpm";
    game->path.back_ground = "./bonus_assets/collectives/background.xpm";
    game->path.exit_path = "./bonus_assets/exit/exit.xpm";

    game->player[0] = "./bonus_assets/player/walk.xpm";
    game->player[1] = "./bonus_assets/player/walk_1.xpm";
    game->player[2] = "./bonus_assets/player/walk_2.xpm";
    game->player[3] = "./bonus_assets/player/walk_3.xpm";
    game->player[4] = "./bonus_assets/player/walk_4.xpm";
    game->player[5] = "./bonus_assets/player/walk_5.xpm";
    game->player[6] = "./bonus_assets/player/walk_6.xpm";
    game->player[7] = "./bonus_assets/player/walk_7.xpm";

    game->enemy[0] = "./bonus_assets/enemy/enemy.xpm";
    game->enemy[1] = "./bonus_assets/enemy/enemy_1.xpm";
    game->enemy[2] = "./bonus_assets/enemy/enemy_2.xpm";
    game->enemy[3] = "./bonus_assets/enemy/enemy_3.xpm";
    game->enemy[4] = "./bonus_assets/enemy/enemy_4.xpm";
    game->enemy[5] = "./bonus_assets/enemy/enemy_5.xpm";

    for (int i = 0; i < 4; i++)
        check_asset_path(game->coins[i]);

    check_asset_path(game->path.wall_path);
    check_asset_path(game->path.back_ground);
    check_asset_path(game->path.exit_path);

    for (int i = 0; i < 8; i++)
        check_asset_path(game->player[i]);

    for (int i = 0; i < 6; i++)
        check_asset_path(game->enemy[i]);
}


void get_xpm(t_game *game)
{
    game->image.wall = mlx_xpm_file_to_image(game->mlx.connection,
            game->path.wall_path, &game->path.x, &game->path.y);
    game->image.background = mlx_xpm_file_to_image(game->mlx.connection,
            game->path.back_ground, &game->path.x, &game->path.y);
    game->image.exit = mlx_xpm_file_to_image(game->mlx.connection,
            game->path.exit_path, &game->path.x, &game->path.y);

    for (int i = 0; i < 4; i++) {
        game->image.coin[i] = mlx_xpm_file_to_image(game->mlx.connection,
            game->coins[i], &game->path.x, &game->path.y);
    }
    for (int j = 0; j < 8; j++) {
        game->image.img[j] = mlx_xpm_file_to_image(game->mlx.connection,
            game->player[j], &game->path.x, &game->path.y);
    }
    for (int k = 0; k < 6; k++) {
        game->image.enemy[k] = mlx_xpm_file_to_image(game->mlx.connection,
            game->enemy[k], &game->path.x, &game->path.y);
    }
}


void display_image(t_game *game)
{
    int i = 0;
    int j;
    while (game->lines[i])
    {
        j = 0;
        while (game->lines[i][j])
        {
            if (game->lines[i][j] == '1')
                mlx_put_image_to_window(game->mlx.connection, game->mlx.window,
			    game->image.wall, j * 64, i * 64);
            else if (game->lines[i][j] == 'P')
                mlx_put_image_to_window(game->mlx.connection, game->mlx.window,
			    game->image.img[game->player_frame], game->pos.x * 64, game->pos.y * 64);
            else if (game->lines[i][j] == 'c')
                mlx_put_image_to_window(game->mlx.connection, game->mlx.window,
			    game->image.coin[game->frame], j * 64, i * 64);
            else if (game->lines[i][j] == 'N')
                mlx_put_image_to_window(game->mlx.connection, game->mlx.window,
			    game->image.enemy[game->enemy_frame], j * 64, i * 64);
            if (game->counts.collectives == 0 && game->lines[i][j] == 'e')
                mlx_put_image_to_window(game->mlx.connection, game->mlx.window,
                    game->image.exit, j * 64, i * 64);
            j++;
        }
        i++;
    }
}


void find_exit(t_game *game)
{
    int i = 0;
    int j;
    while (game->lines[i])
    {
        j = 0;
        while (game->lines[i][j])
        {
            if (game->lines[i][j] == 'e')
            {
                game->exit_x = i;
                game->exit_y = j;
            }
            else if (game->lines[i][j] == 'c')
                game->counts.collectives++;
            j++;
        }
        i++;
    }
}

void cover_bg (t_game *game)
{
    int i = 0;
    int j;
    while (i < game->height * 64)
    {
        j = game->width * 64;
        while (j < (game->width * 64) + 64 )
        {
            mlx_pixel_put(game->mlx.connection, game->mlx.window, i  , j, 0x000000);
            j++;
        }
        i++;
    }
}

void display_moves(t_game *game, int i)
{
    char *moves;
    char *str = "moves : ";

    moves = ft_itoa(i);
    str = ft_strjoin_up(str, moves);
    cover_bg(game);
    mlx_string_put(game->mlx.connection, game->mlx.window,
                   (game->height * 64) / 2,
                   (game->width * 64) + 10,
                   0xFFFFFF,
                   str);
    free(moves);
    free(str);
}

void	handle_movement(t_game *game, int *ii, int new_x, int new_y)
{
	int	i;

	i = *ii;
	if (game->lines[new_y][new_x] != '1')
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
    if ((game->lines[new_y][new_x] == 'e' && game->counts.collectives == 0) || game->lines[new_y][new_x] == 'N')
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
    *ii = i;
}


void	aplly_key(int keycode, int *new_x, int *new_y, t_game *game)
{
    if (keycode == ESC_KEY)
    {
        clean_game(game);
        exit(0);
    }
    else if (keycode == LEFT_ROW || keycode == 'a' || keycode == 'A')
		*new_x -= 1;
    else if (keycode == RIGHT_ROW || keycode == 'd' || keycode == 'D')
		*new_x += 1;
	else if (keycode == UP_ROW || keycode == 'w' || keycode == 'W')
		*new_y -= 1;
	else if (keycode == DOWN_ROW || keycode == 's' || keycode == 'S')
		*new_y += 1;
}

int	move(int keycode, void *ptr)
{
	t_game		*game;
	int			new_x;
	int			new_y;
    static int  ii = 1;

	game = (t_game *)ptr;
	new_x = game->pos.x;
	new_y = game->pos.y;
	aplly_key(keycode, &new_x, &new_y, game);
	handle_movement(game, &ii, new_x, new_y);
	display_image(game);
	return (0);
}

int animate_coins(t_game *game)
{
    static int count = 0;

    if (count % 9000 == 0)
    {
        count = 0;
        if (game->frame == 3)
            game->frame = 0;
        else
            game->frame++;

        display_image(game);
    }
    count++;
    return (0);
}

int animate_player(t_game *game)
{
    static int count = 0;

    if (count % 6000 == 0)
    {
        count = 0;
        if (game->player_frame == 7)
            game->player_frame = 0;
        else
            game->player_frame++;

        display_image(game);
    }
    count++;
    return (0);
}

int animate_enemy(t_game *game)
{
    static int count = 0;

    if (count % 6000 == 0)
    {
        count = 0;
        if (game->enemy_frame == 5)
            game->enemy_frame = 0;
        else
            game->enemy_frame++;

        display_image(game);
    }
    count++;
    return (0);
}

int animate(t_game *game)
{
    animate_coins(game);
    animate_player(game);
    animate_enemy(game);
    return (0);
}

void free_textures(t_game *game)
{
    int i = 0;
    while (game->image.coin[i] && i < 4)
    {
        if (game->image.coin[i])
            mlx_destroy_image(game->mlx.connection, game->image.coin[i]);
        i++;
    }
    i = 0;
    while (game->image.img[i] && i < 8)
    {
        if (game->image.img[i])
            mlx_destroy_image(game->mlx.connection, game->image.img[i]);
        i++;
    }
    i = 0;
    while (game->image.enemy[i] && i < 6)
    {
        if (game->image.enemy[i])
            mlx_destroy_image(game->mlx.connection, game->image.enemy[i]);
        i++;
    }
}

int	clean_game(t_game *game)
{
	mlx_destroy_image(game->mlx.connection, game->image.wall);
	// mlx_destroy_image(game->mlx.connection, game->image.coin);
	// mlx_destroy_image(game->mlx.connection, game->image.img);
    free_textures(game);
	mlx_destroy_image(game->mlx.connection, game->image.exit);
	mlx_destroy_image(game->mlx.connection, game->image.background);
	mlx_destroy_window(game->mlx.connection, game->mlx.window);
	mlx_destroy_display(game->mlx.connection);
	free(game->mlx.connection);
	free_split(game->lines);
	free(game);
	return (0);
}
int	ft_close(t_game *game)
{
    clean_game(game);
	exit(0);
	return (0);
}

void ft_start_game(t_game *game)
{
    game->mlx.connection = mlx_init();
    get_hight(game);
    get_path(game);
    game->mlx.window = mlx_new_window(game->mlx.connection, game->height * 64,
			game->width * 70, "so_long_bonus");
    get_xpm(game);
    game->frame = 0;
    game->player_frame = 0;
    game->enemy_frame = 0;
    display_image(game);
    mlx_loop_hook(game->mlx.connection, animate, game);
    mlx_hook(game->mlx.window, 02, 1, move, game);
    mlx_hook(game->mlx.window, 17, 0, ft_close, game);
    mlx_loop(game->mlx.connection);
}


void function(t_game *game)
{
    game->pos.x = 0;
    game->pos.y = 0;
    find_player(game, &game->pos.x, &game->pos.y);
    find_exit(game);
    ft_start_game(game);
}
