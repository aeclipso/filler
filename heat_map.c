/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:06:33 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/09 19:08:35 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_memhmap(t_field *general)
{
	int				i;

	i = 0;
	if(!(general->heat_map = (int**)malloc(sizeof(int*) * general->h_map)))
		return (0);
	while (i < general->h_map)
	{
		if(!(general->heat_map[i] = (int*)malloc(sizeof(int) * general->w_map)))
		{
			while (--i >= 0)
				free(general->heat_map[i]);
			free(general->heat_map);
			return (0);
		}
		i++;
	}
	return (1);
}

int			ft_create_h_map(t_field *general)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	while (general->field[y])
	{
		while (general->field[y][x])
		{
			if(general->field[y][x] == '.')
				general->heat_map[y][x] = 0;
			else if(ft_toupper(general->field[y][x] == general->player))
				general->heat_map[y][x] = -1;
			else if (ft_toupper(general->field[y][x] == general->opponent))
				general->heat_map[y][x] = -2;
			else
				return (0);
			x++;
		}
		y++;
		x = 0;
	}
}
