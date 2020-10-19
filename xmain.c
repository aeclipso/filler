/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:54:42 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/19 14:28:33 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			make_move(char **line, t_field *general)
{
	if (ft_reading_mapsize(line, general) != 0)
		return (0);
	else if(ft_reading_map(line, general) != 0)
		return (0);
	else if(ft_reading_piece(line, general) != 0)
		return (0);
	else if(ft_reading_piece_s(line, general) != 0)
		return (0);
	else
		return (ft_solver(general));
}

int			main(void)
{
	char	*line;
	t_field	general;

	ft_bzero(&general, sizeof(general));
	if (get_next_line(0, &line) > 0)
	{
		if (!(ft_strnequ("$$$ exec p", line, 10)))
		{
			free(line);
			return (1);
		}
		general.player = (char)(line[10] == '1' ? 'O' : 'X');
		general.opponent = (char)(general.player == 'X' ? 'O' : 'X');

	}
	while (make_move(&line, &general) == 1)
		;
	return (0);
	
}