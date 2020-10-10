/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:12:57 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/10 18:24:33 by aeclipso         ###   ########.fr       */
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

int             ft_core(void)
{
	char        *line;
	t_field     general;
	
	ft_printf("READ_PL\n");
	ft_reading_player(&line, &general);
	ft_printf("\nPLAYER -> %c\nOPPONENT -> %c\n", general.player, general.opponent);
	ft_printf("READ_MS\n");
	ft_reading_mapsize(&line, &general);
	ft_printf("READ_MAP\n");
	ft_reading_map(&line, &general);
	ft_printf("READ_PIECE\n");
	ft_reading_piece(&line, &general);
	ft_printf("SLV\n");
	ft_solver(&general);
	ft_freeser(&general);
	return (0);
}
/*
** TODO: 1) функция определения первой звёздочки 
** 2) тепловая карта или её аналог	+
** 3) функция подстановки
** 4) 
*/
int             main(void)
{
	ft_core();
	return (0);
}


