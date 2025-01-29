/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:42:37 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/28 23:04:28 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen_up(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c)
		i++;
	return (i);
}

char	*ft_strdup_up(char *s1, char c)
{
	size_t	len;
	size_t	i;
	int		character;
	char	*s2;

	if (!s1 || *s1 == '\0')
		return (NULL);
	character = 0;
	if (c == '\0')
		character = 1;
	else if (c == '\n')
		character = 2;
	len = ft_strlen_up(s1, c) + character;
	s2 = (char *)malloc(sizeof(char) * len);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < len - 1 && s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin_up(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*s;

	len1 = ft_strlen_up(s1, '\0');
	len2 = ft_strlen_up(s2, '\0');
	if (!s1 || !s2)
		return (NULL);
	s = (char *)malloc(len1 + len2 + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (i < len1 && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2 && s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}
