/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:33:50 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/19 14:26:53 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_reading_piece_s(char **line, t_field *gen)
{
	int			y;

	y = 0;
	if (!(gen->piece = (char**)malloc(sizeof(char*) * (gen->h_piece + 1))))
		return (0);
	while (y < gen->h_piece)
	{
		if (get_next_line(0, line) > 0)
		{
			if (!(gen->piece[y] = (char*)malloc(gen->w_piece + 1)))
				return (0);
			ft_strcpy(gen->piece[y], *line);
			free(*line);
		}
		y++;
	}
	gen->piece[y] = NULL;
	return (0);
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
	else
		return (1);
	return (0);
}
