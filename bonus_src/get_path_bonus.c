/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:20:25 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/13 16:32:25 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_coin_paths(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		check_asset_path(game->coins[i], game);
		i++;
	}
}

void	check_player_paths(t_game *game)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		check_asset_path(game->player[i], game);
		i++;
	}
}

void	check_enemy_paths(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		check_asset_path(game->enemy[i], game);
		i++;
	}
}

void	get_path(t_game *game)
{
	init_coin_paths(game);
	init_player_paths(game);
	init_enemy_paths(game);
	init_basic_paths(game);
	check_coin_paths(game);
	check_asset_path(game->path.wall_path, game);
	check_asset_path(game->path.back_ground, game);
	check_asset_path(game->path.exit_path, game);
	check_player_paths(game);
	check_enemy_paths(game);
}
