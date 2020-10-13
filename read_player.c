/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:18:02 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/13 17:18:46 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int				ft_validateplayer(char **line, t_field *general)
{
	char				*playername;
	char				*gn;

	playername = ft_strsub(*line, 14, ft_strlen(*line) - 14);
	gn = ft_strstr(playername, "aeclipso.filler]");
	ft_printf("GN%s\n", gn);
	ft_printf("PN\t%s\n", playername);
	if (ft_strnequ("$$$ exec p", *line, 10))
	{
		if (ft_strequ(gn, "aeclipso.filler]") && (*line)[10] == '1')
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
	return (1);
}

int						ft_reading_player(char **line, t_field *general)
{
	int					i;

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
	return (1);
}
