/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:28:15 by smallem           #+#    #+#             */
/*   Updated: 2023/08/26 22:48:44 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*read_map(char *path)
{
	int		fd;
	char	*buffer;
	int		bytes;
	char	*str;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	bytes = 1;
	str = ft_strdup("");
	while (bytes)
	{
		buffer = malloc(11);
		bytes = read(fd, buffer, 10);
		if (bytes == -1)
			return (free(buffer), free(str), NULL);
		buffer[bytes] = 0;
		tmp = str;
		str = ft_strjoin(tmp, buffer);
		free(tmp);
		free(buffer);
	}
	close(fd);
	return (str);
}

char	**all_map(char *str)
{
	int		nb_lines;
	int		i;
	char	**map;

	i = 0;
	nb_lines = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			nb_lines++;
		i++;
	}
	map = malloc(sizeof(char *) * (nb_lines + 2));
	if (map == NULL)
		return (NULL);
	map[nb_lines + 1] = NULL;
	return (map);
}

char	**parse_map(char *str)
{
	int		nb_lines;
	int		i;
	char	*tmp;
	char	**map;

	map = all_map(str);
	if (map == NULL)
		return (NULL);
	i = 0;
	nb_lines = 0;
	tmp = str;
	while (*str)
	{
		if (*str == '\n')
		{
			map[nb_lines] = ft_substr(str - i, 0, i);
			nb_lines++;
			i = 0;
		}
		else
			i++;
		str++;
	}
	map[nb_lines] = ft_substr(str - i, 0, i);
	return (free(tmp), map);
}

char	**build_map(char *path)
{
	char	*str;
	char	**map;
	int		i;

	str = read_map(path);
	if (!str)
		return (NULL);
	if (!ft_strncmp(str, "", ft_strlen(str)))
		return (free(str), NULL);
	map = parse_map(str);
	if (map == NULL)
		return (free(str), NULL);
	i = -1;
	while (map[++i])
	{
		if (!ft_strncmp(map[i], "", ft_strlen(map[i])))
			return (free_split(map), NULL);
	}	
	return (map);
}

void	update_stats(char c, int *p, int *e, int *col)
{
	if (c == 'P')
		(*p)++;
	if (c == 'E')
		(*e)++;
	if (c == 'C')
		(*col)++;
}
