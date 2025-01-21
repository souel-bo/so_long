/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:56:14 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/20 22:43:17 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_file_name(const char *file_name)
{
	size_t	lenght = ft_strlen(file_name);
	if (lenght <= 4)
		return (0);
	if (ft_strncmp(file_name + lenght - 4, ".ber", 4) == 0)
		return (1);
	return (0);
}

void	ft_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

int	open_file(const char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("file not valid");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	read_file(int fd)
{
	char	*first_line;
	char	*second_line;

	first_line = get_next_line(fd);
	if (!first_line)
		ft_error("empty file");
	while (first_line != NULL)
	{
		second_line = get_next_line(fd);
		if (!second_line)
		{
			free(first_line);
			break;
		}
		if (ft_strlen(first_line) != ft_strlen(second_line))
		{
			free(first_line);
			get_next_line(-1);
			free(second_line);
			ft_error("invalid map\n");
		}
		free(first_line);
		free(second_line);
		first_line = get_next_line(fd);
	}
	return (1);
}
