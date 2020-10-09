/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:30:57 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/09 19:19:52 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				debug_print_heat_map(t_field *general)
{ //debug
	int i = 0;
	int j = 0;

	while (i < general->h_map)
	{
		while (j < general->w_map)
		{
			ft_printf("%i\t", general->heat_map[i][j]);
			j++;
		}
			ft_printf("\n");
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

	}
}