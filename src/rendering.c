/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:52:07 by smallem           #+#    #+#             */
/*   Updated: 2023/09/02 16:10:08 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

mlx_image_t	*print_image(mlx_t *mlx, mlx_image_t *img, char *path)
{
	xpm_t		*xpm;
	mlx_image_t	*image;
	int			fd;

	if (img)
		mlx_delete_image(mlx, img);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	xpm = mlx_load_xpm42(path);
	if (!xpm)
		return (0);
	image = mlx_texture_to_image(mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	if (!image)
		return (0);
	return (image);
}

void	init_map(t_var *var)
{
	int	i;
	int	j;

	var->background = print_image(var->window, var->background,
			"textures/bg.xpm42");
	var->wall = print_image(var->window, var->wall,
			"textures/rock.xpm42");
	var->player = print_image(var->window, var->player,
			"textures/player.xpm42");
	var->food = print_image(var->window, var->food,
			"textures/food.xpm42");
	var->enemy = print_image(var->window, var->enemy,
			"textures/enemy.xpm42");
	var->exit = print_image(var->window, var->exit,
			"textures/door.xpm42");
	i = -1;
	while (var->map[++i])
	{
		j = -1;
		while (++j <= (int)ft_strlen(var->map[i]))
			mlx_image_to_window(var->window, var->background,
				j * 42, i * 42);
	}
}

void	print_map(t_var *var)
{
	int		i;
	int		j;

	i = -1;
	while (++i < (int)var->h)
	{
		j = -1;
		while (++j < (int)ft_strlen(var->map[i]))
		{
			if (var->map[i][j] == '1')
				p(var, var->wall, i, j);
			else if (var->map[i][j] == 'P')
				p(var, var->player, i, j);
			else if (var->map[i][j] == 'C')
				p(var, var->food, i, j);
			else if (var->map[i][j] == 'X')
				p(var, var->enemy, i, j);
			else if (var->map[i][j] == 'E')
				p(var, var->exit, i, j);
		}
	}
}

void	display_moves(t_var	*var)
{
	if (var->flag)
	{
		if (var->flag != 2)
			write(1, "You won!\n", 10);
	}
	else
	{
		write(1, "Number of moves: ", 18);
		ft_putnbr_fd((int)var->total_moves, 1);
		write(1, "\n", 1);
		var->total_moves++;
	}
}
