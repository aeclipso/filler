/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:12:57 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/08 19:24:13 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			free_map(t_field *general)
{
	int i = 0;

	while (general->field[i])
	{
		free(general->field[i]);
		i++;
	}
	free(general->field);
}

int             ft_core(void)
{
	char        *line;
	t_field     general;
	
	// ft_reading_player(&line, &general);
	// ft_reading_mapsize(&line, &general);
	// ft_reading_map(&line, &general);
	ft_reading_piece(&line, &general);
	ft_solver(general);
	// free_map(&general);
}

int             main(void)
{
	ft_core();
}


