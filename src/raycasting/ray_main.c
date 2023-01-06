/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:36:40 by lucas-ma          #+#    #+#             */
/*   Updated: 2023/01/06 12:33:01 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static t_vector	find_dir(char dir)
{
	t_vector	d;
	
	d.x = 0;
	d.y = 1;
	if (dir == 'N' || dir == 'S')
	{
		d.x = 0;
		if (dir == 'N')
			d.y = 1;
		else
			d.y = -1;
	}
	else
	{
		d.y = 0;
		if (dir == 'E')
			d.x = 1;
		else
			d.x = -1;
	}
	return (d);
}

static t_vector calc_plane(char dir)
{
	t_vector	plane;

	if (dir == 'N' || dir == 'S')
	{
		plane.y = 0;
		plane.x = 0.66;
	}
	else 
	{
		plane.y = 0.66;
		plane.x = 0;
	}
	return (plane);
}

void	ray_main(t_cub *map, t_mlx *mlx)
{
	t_ray	r;

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SCREENW, SCREENH, "Cub3D");
	r.p.x = (double)map->player.x;
	r.p.y = (double)map->player.y;
	r.dir = find_dir(map->player.dir);
	r.plane = calc_plane(map->player.dir);
	while (1)
	{
		ray_loop(mlx, &r, map);
		mlx_do_sync(mlx->mlx);
		mlx_loop(mlx->mlx);
	}
}