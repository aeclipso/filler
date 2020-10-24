/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:18:02 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/24 13:41:46 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void				ft_validateplayer(char **line, t_field *general)
{
	if (ft_strnequ("$$$ exec p", *line, 10))
	{
		if ((*line)[10] == '1')
		{
			general->player = 'O';
			general->opponent = 'X';
		}
		else
		{
			general->player = 'X';
			general->opponent = 'O';
		}
	}
}

int						ft_reading_player(char **line, t_field *general)
{
	if (get_next_line(0, line) > 0)
	{
		ft_validateplayer(line, general);
		free(*line);
		return (1);
	}
	else
		return (0);
}
