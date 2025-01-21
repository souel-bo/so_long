/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:45:32 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/20 18:02:12 by souel-bo         ###   ########.fr       */
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

typedef struct file
{
	int		width;
	int		height;
	char	**lines;
	char	*s;
}	map;

typedef struct counts
{
	int	player;
	int	exit;
	int	collectives;
} counts;

int		check_file_name(const char *file_name);
void	ft_error(char *msg);
int		open_file(const char *file_name);
int     read_file(int fd);
map     *fill_map(int fd, const char *file_name);
void	  free_split(char **split);
void	  check_walls_2(map *data);
void	  check_walls(map *data);

#endif
