/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:12:57 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/23 23:30:56 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
void	ft_debuger(t_field *general)
{
	general->player = 'O';
	general->opponent = 'X';
	general->h_map = 15;
	general->w_map = 17;
	general->field = (char **)malloc(sizeof(char*) * (general->h_map + 1));
	general->field[0] = (char *)malloc(general->w_map + 1); general->field[0] = ".O...............";
	general->field[1] = (char *)malloc(general->w_map + 1); general->field[1] = "..O..............";
	general->field[2] = (char *)malloc(general->w_map + 1); general->field[2] = "...O.............";
	general->field[3] = (char *)malloc(general->w_map + 1); general->field[3] = ".O...............";
	general->field[4] = (char *)malloc(general->w_map + 1); general->field[4] = "..O..............";
	general->field[5] = (char *)malloc(general->w_map + 1); general->field[5] = "...O.............";
	general->field[6] = (char *)malloc(general->w_map + 1); general->field[6] = ".O...............";
	general->field[7] = (char *)malloc(general->w_map + 1); general->field[7] = "..O..............";
	general->field[8] = (char *)malloc(general->w_map + 1); general->field[8] = "...O.............";
	general->field[9] = (char *)malloc(general->w_map + 1); general->field[9] = ".O...............";
	general->field[10] = (char *)malloc(general->w_map + 1); general->field[10] = "..O..............";
	general->field[11] = (char *)malloc(general->w_map + 1); general->field[11] = "...O.............";
	general->field[12] = (char *)malloc(general->w_map + 1); general->field[12] = ".O...............";
	general->field[13] = (char *)malloc(general->w_map + 1); general->field[13] = ".O............X..";
	general->field[14] = (char *)malloc(general->w_map + 1); general->field[14] = ".O...............";
	
	general->h_piece = 2;
	general->w_piece = 2;
	general->piece =(char **)malloc(sizeof(char*) * (general->h_piece + 1));
	general->piece[0] = (char *)malloc(general->w_piece + 1); general->piece[0] = ".*";
	general->piece[1] = (char *)malloc(general->w_piece + 1); general->piece[1] = ".*";
}

void ft_debugPrintMap(t_field *general)
{
	int i = 0;
	int j = 0;
	while (i < general->h_map)
	{
		j = 0;
		while (j < general->w_map)
		{
			ft_printf("%i\t", general->heat_map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int				ft_circle(char *line, t_field *general)
{
	if (ft_reading_mapsize(&line, general) != 0)
		return (0);
	else if(ft_reading_map(&line, general) != 0)
		return (0);
	else if(ft_reading_piece(&line, general) != 0)
		return (0);
	else if(ft_reading_piece_s(&line, general) != 0)
		return (0);
	else 
		return (ft_solver(general));
	
}

int				ft_core(void)
{
	char		*line;
	t_field		general;

	// ft_printf("READ_PL\n");
	if (!(ft_reading_player(&line, &general)))
		return (0);
	while (ft_circle(line, &general))
		;
	return (1);
	// ft_printf("\nPLAYER -> %c\nOPPONENT -> %c\n", general.player, general.opponent);
	// ft_printf("READ_MS\n");
	// ft_reading_mapsize(&line, &general);
	// ft_printf("READ_MAP\n");
	// ft_reading_map(&line, &general);
	// ft_printf("READ_PIECE\n");
	// ft_reading_piece(&line, &general);
	// ft_printf("SLV\n");
	// ft_debuger(&general);				//DEBUG
	// ft_solver(&general);
	// // ft_debugPrintMap(&general);
	// ft_printf("%i %i\n", general.y, general.x);
	// ft_freeser(&general);
	return (0);
}

/*
** TODO: 1) функция определения первой звёздочки
** 2) тепловая карта или её аналог	+
** 3) функция подстановки
** 4)
*/

int				main(void)
{
	if (!(ft_core()))
		return (1);
	return (0);
}
