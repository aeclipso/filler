/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:33:50 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/09 16:11:32 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_reading_piece_s(char **line, t_field *general)
{
	int			y;

	y = 0;
	if (!(general->piece = (char**)malloc(sizeof(char*) * (general->h_piece + 1))))
		return(0);
	while (y < general->h_piece)
	{
		if (get_next_line(0, line) > 0)
		{
			if (!(general->piece[y] = (char*)malloc(sizeof(char) * (general->w_piece + 1))))
				return (0);
			ft_strcpy(general->piece[y], *line);
			free(*line);
		}
		y++;
	}
	general->piece[y] = NULL;
}

int				ft_reading_piece(char **line, t_field *general)
{
	char		*size;
	size_t		i;

	i = 0;
	if (get_next_line(0, line) > 0)
	{
		if (ft_strnequ("Piece", *line, 5))
		{
			size = ft_strsub(*line, 6, ft_strlen(*line) - 6);
			general->h_piece = ft_atoi(size);
			while (size[i] != ' ')
				i++;
			general->w_piece = ft_atoi(&size[i]);
			free(size);
		}
		free(*line);
	}
	ft_reading_piece_s(line, general);
}