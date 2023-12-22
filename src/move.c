/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:54:34 by smallem           #+#    #+#             */
/*   Updated: 2023/08/19 17:20:00 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	valid_movement(int x, int y, char **map, t_var *var)
{
	if (var->food_count == var->total_food && map[y / 42][x / 42] == 'E')
		return (1);
	if (map[y / 42][x / 42] == '0' || map[y / 42][x / 42] == 'C'
		|| map[y / 42][x / 42] == 'P' || map[y / 42][x / 42] == 'X')
		return (1);
	else
		return (0);
}

int	ev_check(t_var	*mlx, int direction)
{
	if (direction == 1 && valid_movement(mlx->player->instances[0].x,
			mlx->player->instances[0].y - 42, mlx->map, mlx))
		return (1);
	if (direction == 2 && valid_movement(mlx->player->instances[0].x,
			mlx->player->instances[0].y + 42, mlx->map, mlx))
		return (1);
	if (direction == 3 && valid_movement(mlx->player->instances[0].x - 42,
			mlx->player->instances[0].y, mlx->map, mlx))
		return (1);
	if (direction == 4 && valid_movement(mlx->player->instances[0].x + 42,
			mlx->player->instances[0].y, mlx->map, mlx))
		return (1);
	return (0);
}

int	check_e(char **map, int x, int y, t_var	*var)
{
	if (map[y / 42][x / 42] == 'C')
		var->food_count++;
	if (map[y / 42][x / 42] == 'X' || (var->food_count == var->total_food
		&& map[y / 42][x / 42] == 'E'))
	{
		if (map[y / 42][x / 42] == 'X')
		{
			var->flag = 2;
			write(1, "You lost!\n", 11);
		}
		else
			var->flag = 1;
		return (0);
	}
	else
		return (1);
}

void	movement(t_var *var, int direction)
{
	if (direction == 1 && !check_e(var->map, var->player->instances[0].x,
			var->player->instances[0].y - 42, var))
		mlx_close_window(var->window);
	else if (direction == 2 && !check_e(var->map, var->player->instances[0].x,
			var->player->instances[0].y + 42, var))
		mlx_close_window(var->window);
	else if (direction == 3 && !check_e(var->map, var->player->instances[0].x
			- 42, var->player->instances[0].y, var))
		mlx_close_window(var->window);
	else if (direction == 4 && !check_e(var->map, var->player->instances[0].x
			+ 42, var->player->instances[0].y, var))
		mlx_close_window(var->window);
	display_moves(var);
	var->map[var->player->instances[0].y / 42][(
			var->player->instances[0].x - 0) / 42] = '0';
	if (direction == 1)
		var->player->instances[0].y -= 42;
	else if (direction == 2)
		var->player->instances[0].y += 42;
	else if (direction == 3)
		var->player->instances[0].x -= 42;
	else if (direction == 4)
		var->player->instances[0].x += 42;
	var->map[var->player->instances[0].y / 42][(
			var->player->instances[0].x - 0) / 42] = 'P';
}
