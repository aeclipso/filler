/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 17:34:19 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/13 17:37:21 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			free_map(t_field *general)
{
	int i;

	i = 0;
	while (general->field[i])
	{
		free(general->field[i]);
		i++;
	}
	free(general->field);
}

void			free_heat(t_field *general)
{
	int i;

	i = 0;
	while (i < general->h_map)
	{
		free(general->heat_map[i]);
		i++;
	}
	free(general->heat_map);
}

void			free_piece(t_field *general)
{
	int	i;

	i = 0;
	while (i < general->h_piece)
	{
		free(general->piece[i]);
		i++;
	}
	free(general->piece);
}

void			ft_freeser(t_field *general)
{
	free_map(general);
	free_heat(general);
	free_piece(general);
}
