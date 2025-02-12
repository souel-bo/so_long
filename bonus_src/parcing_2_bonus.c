/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:45:11 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/12 22:44:57 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	get_height(int fd, t_game *data)
{
	int	height;

	height = 0;
	data->s = get_next_line(fd);
	while (data->s != NULL)
	{
		height++;
		free(data->s);
		data->s = get_next_line(fd);
	}
	close(fd);
	return (height);
}

t_game	*fill_t_game(int fd, const char *file_name)
{
	t_game	*data;
	int		i;

	close(fd);
	fd = open_file(file_name);
	data = malloc(sizeof(t_game));
	if (!data)
		return (NULL);
	data->height = get_height(fd, data);
	fd = open_file(file_name);
	data->lines = malloc(sizeof(char *) * (data->height + 1));
	if (!data->lines)
	{
		free(data);
		return (NULL);
	}
	i = 0;
	while (i < data->height)
		data->lines[i++] = get_next_line(fd);
	data->lines[i] = NULL;
	close(fd);
	return (data);
}