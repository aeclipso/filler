/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:05:53 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/22 17:56:40 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_setsolvecoord(t_field *general, int i, int j)
{
	general->x = i;
	general->y = j;
}

static int		ft_seton(t_field *general, int i, int j)
{
	int			x;
	int			y;
	t_itplace	it;

	ft_bzero(&it, sizeof(t_itplace));
	x = -1;
	while (++x < general->h_piece)
	{
		y = -1;
		while (++y < general->w_piece)
		{
			if (general->piece[x][y] == '*')
			{
				if ((i + x) < 0 || (i + x) >= general->h_map
					|| (y + j) < 0 || (y + j) >= general->w_map
					|| general->heat_map[x + i][y + j] == -2)
					return (-1);
				if (general->heat_map[x + i][y + j] == -1)
					it.iter++;
				it.place += general->heat_map[x + i][y + j];
			}
		}
	}
	return ((it.iter == 1) ? it.place : -1);
}

int				ft_setpiece(t_field *general)			//исправить для токенов которые больше чем карта
{
	int			i;
	int			j;
	int			place;
	int			near_place;

	near_place = 2147483647;
	i = -(general->h_map);
	while (i < general->h_map + general->h_piece)
	{
		j = -(general->w_map);
		while (j < general->w_map + general->w_piece)
		{
			place = ft_seton(general, i, j);
			if (place != -1 && place < near_place)
			{
				ft_setsolvecoord(general, i, j);
				near_place = place;
			}
			j++;
		}
		i++;
	}
	return (1);
}
