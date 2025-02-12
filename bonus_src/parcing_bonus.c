/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:45:01 by souel-bo          #+#    #+#             */
/*   Updated: 2025/02/12 22:45:07 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	check_file_name(const char *file_name)
{
	size_t	lenght;

	lenght = ft_strlen(file_name);
	if (lenght <= 4)
		return (0);
	if (ft_strncmp(file_name + lenght - 4, ".ber", 4) == 0)
		return (1);
	return (0);
}

void	ft_error(char *msg, t_game *data)
{
	free(data);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

int	open_file(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("file not valid");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	helper(char *first_line, char *second_line)
{
	free(first_line);
	get_next_line(-1);
	free(second_line);
	ft_putstr_fd("Erorr\nmap should be rectangle\n", 2);
	exit(1);
}

int	read_file(int fd)
{
	char	*first_line;
	char	*second_line;

	first_line = get_next_line(fd);
	if (first_line == NULL)
	{
		free(first_line);
		ft_putstr_fd("Erorr\nempty file\n", 2);
		exit(1);
	}
	while (first_line != NULL)
	{
		second_line = get_next_line(fd);
		if (!second_line)
		{
			free(first_line);
			break ;
		}
		if (ft_strlen(first_line) != ft_strlen(second_line))
			helper(first_line, second_line);
		free(first_line);
		free(second_line);
		first_line = get_next_line(fd);
	}
	return (1);
}