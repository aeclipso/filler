/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:30:57 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/09 23:06:20 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#include <stdio.h>
void				debug_print_heat_map(t_field *general)
{ //debug
	int i = 0;
	int j = 0;

	while (i < general->h_map)
	{
		while (j < general->w_map)
		{
			printf("%i\t", general->heat_map[i][j]);
			j++;
		}
			printf("\n");
		j = 0;
		i++;
	}
}

static int			ft_searchmind(t_field *general, int i, int j)
{
	int				x;
	int				y;
	int				step;
	int				min_step;

	x = 0;
	y = 0;
	// min_step = 2147483647;
	min_step = 100;
	while (y < general->h_map)
	{
		while (x < general->w_map)
		{
			if(general->heat_map[y][x] == -2)
			{
				step = ft_abs(x - i) + ft_abs(y - j);
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
}

int					ft_solver(t_field *general)
{
	if(ft_memhmap(general))
	{
		ft_create_h_map(general);
		debug_print_heat_map(general); //debug
		ft_searchdist(general);
	}
}