/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/25 12:28:56 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/03/05 14:20:39 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_line(int a, char **str, t_map ***map)
{
	int	c;

	c = 0;
	while (str[c])
	{
		map[a][c] = malloc(sizeof(t_map));
		if (map[a][c] == NULL)
			return;
		map[a][c]->y = (float)a * SIZE_PIXEL;
		map[a][c]->x = (float)c * SIZE_PIXEL;
		map[a][c]->z = (float)ft_atoi(str[c]);
		c++;
	}
}

int		size_line(char **str)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

void		print(t_map ***map)
{
	int	a;
	int	b;

	a = 0;
	while (map[a])
	{
		b = 0;
		while (map[a][b])
		{
			printf("[%f, %f, %f]", map[a][b]->y, map[a][b]->x, map[a][b]->z);
			b++;
		}
		printf("\n");
		a++;
	}
}

void			convers(t_map ***map)
{
	int	a;
	int	b;

	a = 0;
	while (map[a])
	{
		b = 0;
		while (map[a][b])
		{
			map[a][b]->x = CTE1 * map[a][b]->x - CTE2 * map[a][b]->y + CTE3;
			map[a][b]->y = map[a][b]->z + CTE1 / 2 * map[a][b]->x + CTE2 / 2 * map[a][b]->y + CTE3;
			b++;
		}
		a++;
	}
}

static void		ft_read(int fd, t_map ***map)
{
	char	*line;
	char	**str;
	int		a;
	int		size;

	a = 0;
	while (get_next_line(fd, &line) > 0)
	{
		str = ft_strsplit(line, ' ');
		size = size_line(str);
		map[a] = (t_map **)malloc((sizeof(t_map *) * (size + 1)));
		if (map[a] == NULL)
			return;
		map[a][size] = NULL;
		ft_line(a, str, map);
		a++;
		free(line);
		free(str);
	}
	convers(map);
	print(map);
	display(map);
}

static int		ft_nbr_line(char *str)
{
	int		fd;
	int		size;
	char	buff[1];

	size = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, buff, 1) == 1)
	{
		if (buff[0] == '\n')
			size++;
	}
	close(fd);
	return (size);
}


int				main(int ac, char **av)
{
	int		fd;
	t_map	***map;
	int		size;

	if (ac == 2)
	{
		size = ft_nbr_line(av[1]);
		map = malloc((size + 1) * sizeof(t_map **));
		if (map == NULL)
			return (-1);
		map[size + 1] = NULL;
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		ft_read(fd, map);
		close(fd);
	}
	else
	{
		ft_putstr_fd("usage : ./fdf file1\n", 2);
		return (1);
	}
	return (0);
}