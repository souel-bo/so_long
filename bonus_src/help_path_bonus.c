/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_path_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:25:16 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/13 16:32:31 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_coin_paths(t_game *game)
{
	game->coins[0] = "./bonus_assets/collectives/red_crystal_1.xpm";
	game->coins[1] = "./bonus_assets/collectives/red_crystal_2.xpm";
	game->coins[2] = "./bonus_assets/collectives/red_crystal_3.xpm";
	game->coins[3] = "./bonus_assets/collectives/red_crystal_4.xpm";
}

void	init_player_paths(t_game *game)
{
	game->player[0] = "./bonus_assets/player/walk.xpm";
	game->player[1] = "./bonus_assets/player/walk_1.xpm";
	game->player[2] = "./bonus_assets/player/walk_2.xpm";
	game->player[3] = "./bonus_assets/player/walk_3.xpm";
	game->player[4] = "./bonus_assets/player/walk_4.xpm";
	game->player[5] = "./bonus_assets/player/walk_5.xpm";
	game->player[6] = "./bonus_assets/player/walk_6.xpm";
	game->player[7] = "./bonus_assets/player/walk_7.xpm";
}

void	init_enemy_paths(t_game *game)
{
	game->enemy[0] = "./bonus_assets/enemy/enemy.xpm";
	game->enemy[1] = "./bonus_assets/enemy/enemy_1.xpm";
	game->enemy[2] = "./bonus_assets/enemy/enemy_2.xpm";
	game->enemy[3] = "./bonus_assets/enemy/enemy_3.xpm";
	game->enemy[4] = "./bonus_assets/enemy/enemy_4.xpm";
	game->enemy[5] = "./bonus_assets/enemy/enemy_5.xpm";
}

void	init_basic_paths(t_game *game)
{
	game->path.wall_path = "./bonus_assets/wall/wall.xpm";
	game->path.back_ground = "./bonus_assets/collectives/background.xpm";
	game->path.exit_path = "./bonus_assets/exit/exit.xpm";
}
