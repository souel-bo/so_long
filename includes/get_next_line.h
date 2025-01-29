/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:42:40 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/20 13:41:17 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  23
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen_up(char *s, char c);
char	*ft_strdup_up(char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_up(char *s1, char *s2);
char	*ft_fill_line(char *line, char *buffer, char **container, int new_line);
#endif