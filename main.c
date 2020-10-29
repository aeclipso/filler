/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:12:57 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/25 16:14:16 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_circle(char *line, t_field *general)
{
	if (ft_reading_mapsize(&line, general) != 0)
		return (0);
	else if (ft_reading_map(&line, general) != 0)
		return (0);
	else if (ft_reading_piece(&line, general) != 0)
		return (0);
	else if (ft_reading_piece_s(&line, general) != 0)
		return (0);
	else
		return (ft_solver(general));
}

int				ft_core(void)
{
	char		*line;
	t_field		general;

	if (!(ft_reading_player(&line, &general)))
		return (0);
	while (ft_circle(line, &general))
		;
	return (1);
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
