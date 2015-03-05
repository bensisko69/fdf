/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_y.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 17:04:52 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/03/05 14:32:19 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static float	ft_abs(int i)
// {
// 	return ((float)i);
// }

void	draw_line_y(t_map *point, t_map *point2, t_env *e, int color)
{
	// float		x;
	// float		y;
	// float		x2;
	// float		y2;
	// float		coef;

	// y = ft_abs(point->y);
	// x = ft_abs(point->x);
	// x2 = ft_abs(point2->x);
	// y2 = ft_abs(point2->y);
	// coef = (y2 - y) / (x2 - x);
	// while (y < y2 && x2 < x)
	// {
	// 	printf("%f\n",coef );
	// printf("x = %f\n", x);
	// printf("y = %f\n", y);
	// printf("x2 = %f\n", x2);
	// printf("y2 = %f\n", y2);
	// 	// printf("%s\n", "lol");
	// 	mlx_pixel_put(e->mlx, e->win,x , y, color);
	// 	y += coef;
	// 	x += coef;
	(void)color;
	(void)e;
	(void)point2;
	(void)point;

	// }
}
