/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:12:57 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/13 17:36:50 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_core(void)
{
	char		*line;
	t_field		general;

	ft_reading_player(&line, &general);
	ft_reading_mapsize(&line, &general);
	ft_reading_map(&line, &general);
	ft_reading_piece(&line, &general);
	ft_solver(&general);
	ft_printf("%i %i\n", general.y, general.x);
	ft_freeser(&general);
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
	ft_core();
	return (0);
}
