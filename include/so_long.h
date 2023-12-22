/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:07:02 by musenov           #+#    #+#             */
/*   Updated: 2023/08/21 14:53:21 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef WIDTH
#  define WIDTH 1700
# endif

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

typedef struct s_var
{
	char			**map;
	int				flag;
	size_t			h;
	size_t			w;
	size_t			food_count;
	size_t			total_food;
	size_t			total_moves;
	mlx_t			*window;
	mlx_image_t		*player;
	mlx_image_t		*enemy;
	mlx_image_t		*exit;
	mlx_image_t		*food;
	mlx_image_t		*background;
	mlx_image_t		*moves;
	mlx_image_t		*wall;
}	t_var;

typedef struct s_tmp
{
	char			**map;
	int				c;
	int				e;
}	t_tmp;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

void		display_moves(t_var	*var);
char		**convert_input(char *argv, int *nb_line, t_var *var);
int			create_mat(char **mat, int nb_line, char *argv);
int			check_mat_valid(char **mat, int nb_line);
int			check_walls(char **mat, int nb_line);
int			check_dup(char **mat);
mlx_image_t	*print_image(mlx_t *mlx, mlx_image_t *img, char *path);
void		init_map(t_var *var);
void		print_map(t_var *var);
int			valid_movement(int x, int y, char **map, t_var *var);
int			check_e(char **map, int x, int y, t_var *var);
void		movement(t_var *var, int direction);
size_t		count_food(char **map);
int			ev_check(t_var	*mlx, int direction);
t_pos		find_start(char **mat);
char		**dup_tab(char **mat);
void		p(t_var *var, mlx_image_t *img, int i, int j);
void		free_split(char **mat);
char		**build_map(char *path);
char		**parse_map(char *str);
char		**all_map(char *str);
char		*read_map(char *path);
void		update_stats(char c, int *p, int *e, int *col);
int			find_path(t_tmp *tmp, char **mat, int startRow, int startCol);

#endif