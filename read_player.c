/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:18:02 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/09 23:57:11 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int				ft_validateplayer(char **line, t_field *general)
{
	char		*playername;

	playername = ft_strsub(*line, 14, ft_strlen(*line) - 14);
	if (ft_strnequ("$$$ exec p", *line, 10))
	{
		if (ft_strequ(playername, "[aeclipso.filler]") && (*line)[10] == '1') //TODO: NEED DEBUG
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
	free(playername);
}

int				ft_reading_player(char **line, t_field *general)
{
	int			i;

	i = 0;
	while (i < 1)
	{
		get_next_line(0, line);
		ft_validateplayer(line, general);
		free(*line);
		i++;
	}
	get_next_line(0, line);
	free(*line);
}