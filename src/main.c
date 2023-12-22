/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 03:08:49 by smallem           #+#    #+#             */
/*   Updated: 2023/10/27 13:43:44 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h" 

void	p(t_var *var, mlx_image_t *img, int i, int j)
{
	mlx_image_to_window(var->window, img,
		j * 42, i * 42);
}

void	events(mlx_key_data_t key, void *param)
{
	t_var	*mlx;

	mlx = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		free_split(mlx->map);
		mlx_terminate(mlx->window);
		exit(0);
	}
	if ((key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
		&& key.action == MLX_PRESS && ev_check(mlx, 1))
		movement(mlx, 1);
	else if ((key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
		&& key.action == MLX_PRESS && ev_check(mlx, 2))
		movement(mlx, 2);
	else if ((key.key == MLX_KEY_A || key.key == MLX_KEY_LEFT)
		&& key.action == MLX_PRESS && ev_check(mlx, 3))
		movement(mlx, 3);
	else if ((key.key == MLX_KEY_D || key.key == MLX_KEY_RIGHT)
		&& key.action == MLX_PRESS && ev_check(mlx, 4))
		movement(mlx, 4);
	init_map(mlx);
	print_map(mlx);
}
void	leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_var	var;
	int		i;

	atexit(leaks);
	if (argc != 2)
		return (0);
	i = 0;
	var.map = convert_input(argv[1], &i, &var);
	if (!var.map)
		return (ft_putstr_fd("Bad map format\n", 1), 0);
	var.flag = 0;
	var.w = ft_strlen(var.map[0]);
	var.h = i;
	var.food_count = 0;
	var.total_moves = 0;
	display_moves(&var);
	var.window = mlx_init(var.w * 42, var.h * 42, "So Long", false);
	init_map(&var);
	print_map(&var);
	var.food_count = 0;
	mlx_key_hook(var.window, events, &var);
	mlx_loop(var.window);
	mlx_terminate(var.window);
	return (free_split(var.map), 0);
}
