/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/25 12:28:50 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/03/05 14:19:17 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SIZE_PIXEL 20
# define RED 0xFF0000
# define PINK 0xFF358B
# define WHITE 0xFCFAE1
# define GREEN 0xAEEE00
# define CTE1 0.7
# define CTE2 0.8
# define CTE3 300
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
#include <stdio.h>

typedef struct	s_map
{
	float			x;
	float			y;
	float			z;
}				t_map;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_map		***map;
}				t_env;


/*
**fdf.c
*/
int				size_line(char **str);

/*
**display
*/
void			display(t_map ***map);

/*
**draw_line
*/
void	draw_line_x(t_map *point, t_map *point2, t_env *e, int color);
void	draw_line_y(t_map *point, t_map *point2, t_env *e, int color);

void		print(t_map ***map);

#endif