/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:48:52 by smallem           #+#    #+#             */
/*   Updated: 2023/08/21 15:44:58 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_split(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
	mat = NULL;
}

int	check_dup(char **mat)
{
	int	i;
	int	j;
	int	c_position;
	int	c_exit;
	int	c_collectibe;

	i = -1;
	c_position = 0;
	c_exit = 0;
	c_collectibe = 0;
	while (mat[++i])
	{
		j = -1;
		while (mat[i][++j])
			update_stats(mat[i][j], &c_position, &c_exit, &c_collectibe);
	}
	if (c_position != 1 || c_exit != 1 || c_collectibe < 1)
		return (0);
	else
		return (1);
}

int	check_walls(char **mat, int nb_line)
{
	int		i;
	int		j;
	size_t	len_line;

	i = 0;
	j = 0;
	len_line = ft_strlen(mat[0]);
	while (mat[0][j])
	{
		if (mat[0][j] != '1' || mat[nb_line - 1][j] != '1')
			return (0);
		j++;
	}	
	while (i < nb_line && mat[i])
	{
		if (mat[i][0] != '1' || mat[i][len_line - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_mat_valid(char **mat, int nb_line)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(mat[0]);
	while (mat[i])
	{
		if (len == ft_strlen(mat[i]))
			i++;
		else
			break ;
	}
	if (i + 1 < nb_line)
		return (0);
	if (check_dup(mat) && check_walls(mat, i))
		return (1);
	else
		return (0);
}

char	**convert_input(char *argv, int *nb_line, t_var *var)
{
	char	**map;
	t_pos	pos;
	t_tmp	tmp;

	map = build_map(argv);
	if (map == NULL)
		return (NULL);
	while (map[*nb_line])
		(*nb_line)++;
	pos = find_start(map);
	var->food_count = 0;
	if (check_mat_valid(map, *nb_line))
	{
		var->total_food = count_food(map);
		tmp.map = dup_tab(map);
		tmp.c = var->total_food;
		tmp.e = 1;
		if (!find_path(&tmp, tmp.map, pos.x, pos.y) && tmp.e <= 0)
			return (free_split(tmp.map), map);
		else
			return (free_split(tmp.map), free_split(map), NULL);
	}
	else
		return (free_split(map), NULL);
}
