/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:06:33 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/16 08:00:19 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_memhmap(t_field *gen)
{
	int				i;

	i = 0;
	if (!(gen->heat_map = (int**)malloc(sizeof(int*) * gen->h_map)))
		return (0);
	while (i < gen->h_map)
	{
		if (!(gen->heat_map[i] = (int*)malloc(sizeof(int) * gen->w_map)))
		{
			while (--i >= 0)
				free(gen->heat_map[i]);
			free(gen->heat_map);
			return (0);
		}
		i++;
	}
	return (1);
}

int			ft_create_h_map(t_field *gen)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	while (gen->field[y])
	{
		while (gen->field[y][x])
		{
			if (gen->field[y][x] == '.')
				gen->heat_map[y][x] = 0;
			else if (ft_toupper(gen->field[y][x]) == ft_toupper(gen->player))
				gen->heat_map[y][x] = -1;
			else if (ft_toupper(gen->field[y][x]) == ft_toupper(gen->opponent))
				gen->heat_map[y][x] = -2;
			// ft_printf("%i ", gen->heat_map[y][x]);
			x++;
		}
		// ft_printf("\n");
		y++;
		x = 0;
	}
	return (1);
}
