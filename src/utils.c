/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:58:14 by smallem           #+#    #+#             */
/*   Updated: 2023/08/21 15:39:16 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**dup_tab(char **mat)
{
	char	**dup;
	int		i;
	int		nb_lines;

	nb_lines = 0;
	while (mat[nb_lines])
		nb_lines++;
	dup = malloc(sizeof(char *) * (nb_lines + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (mat[i])
	{
		dup[i] = ft_strdup(mat[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

int	find_path(t_tmp *tmp, char **mat, int startRow, int startCol)
{
	if (mat[startRow][startCol] == 'C')
		tmp->c--;
	if (mat[startRow][startCol] == 'E')
		tmp->e--;
	else
	{
		mat[startRow][startCol] = '1';
		if (mat[startRow][startCol + 1] != '1'
				&& mat[startRow][startCol + 1] != 'X')
			tmp->c = find_path(tmp, mat, startRow, startCol + 1);
		if (mat[startRow][startCol - 1] != '1'
				&& mat[startRow][startCol - 1] != 'X')
			tmp->c = find_path(tmp, mat, startRow, startCol - 1);
		if (mat[startRow + 1][startCol] != '1'
				&& mat[startRow + 1][startCol] != 'X')
			tmp->c = find_path(tmp, mat, startRow + 1, startCol);
		if (mat[startRow - 1][startCol] != '1'
				&& mat[startRow - 1][startCol] != 'X')
			tmp->c = find_path(tmp, mat, startRow - 1, startCol);
	}	
	return (tmp->c);
}

t_pos	find_start(char **mat)
{
	int		i;
	int		j;
	t_pos	pos;

	i = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			if (mat[i][j] == 'P')
			{
				pos.x = i;
				pos.y = j;
			}	
			j++;
		}
		i++;
	}
	return (pos);
}

size_t	count_food(char **map)
{
	size_t	i;
	size_t	j;
	size_t	total_food;

	i = 0;
	total_food = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				total_food++;
			j++;
		}
		i++;
	}
	return (total_food);
}
