/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:30:57 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/25 16:14:30 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			ft_searchmind(t_field *general, int i, int j)
{
	int				x;
	int				y;
	int				step;
	int				min_step;

	x = 0;
	y = 0;
	min_step = 2147483647;
	while (y < general->h_map)
	{
		while (x < general->w_map)
		{
			if (general->heat_map[y][x] == -2)
			{
				step = ft_abs(y - i) + ft_abs(x - j);
				if (step < min_step)
					min_step = step;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (min_step);
}

static int			ft_searchdist(t_field *general)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < general->h_map)
	{
		while (j < general->w_map)
		{
			if (general->heat_map[i][j] == 0)
				general->heat_map[i][j] = ft_searchmind(general, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int					ft_print(t_field *general)
{
	if (general->x == -1 && general->y == -1)
	{
		ft_putstr("0 0\n");
		return (0);
	}
	ft_putnbr(general->x);
	write(1, " ", 1);
	ft_putnbr(general->y);
	write(1, "\n", 1);
	ft_freeser(general);
	return (1);
}

int					ft_solver(t_field *general)
{
	if (ft_memhmap(general))
	{
		ft_create_h_map(general);
		ft_searchdist(general);
		ft_setpiece(general);
	}
	return (ft_print(general));
}
