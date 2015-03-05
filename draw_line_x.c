/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 17:04:52 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/03/05 14:33:41 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	ft_abs(int i)
{
	if (i >= 0)
		return (i);
	else
		return (+i);
}

static float	sign(float y)
{
	if (y < 0)
		return ((float)-1);
	if (y > 0)
		return ((float)1);
	return ((float)0);
}

void	draw_line_x(t_map *point, t_map *point2, t_env *e, int color)
{
	float	deltax;
	float	deltay;
	float	error;
	float	deltaerr;
	float	y;
	float	x;
	float	x2;

	deltax = point2->x - point->x;
	deltay = point2->y - point->y;
	error = 0;
	deltaerr = ft_abs(deltay / deltax);
	y = point->y;
	x = point->x;
	x2 = point2->x;
	if (point->x > point2->x)
	{
		x = point2->x;
		x2 = point->x;
	}
	while (x < x2)
	{
		mlx_pixel_put(e->mlx, e->win,x , y, color);
		error = error + deltaerr;
		while (error > 0.5)
		{
			mlx_pixel_put(e->mlx, e->win,x , y, color);
			y += sign(point2->y - point->y);
			error--;
		}
		x++;
	}
}
