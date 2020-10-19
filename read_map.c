/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:22:04 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/19 14:14:23 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_reading_mapsize(char **line, t_field *general)
{
	char		*size;
	size_t		i;

	i = 0;
	if (get_next_line(0, line) > 0)
	{
		if (ft_strnequ("Plateau", *line, 7))
		{
			size = ft_strsub(*line, 8, ft_strlen(*line) - 8);
			general->h_map = ft_atoi(size);
			while (size[i] != ' ')
				i++;
			general->w_map = ft_atoi(&size[i]);
			free(size);
		}
		free(*line);
		get_next_line(0, line);
		free(*line);
	}
	else
		return (1);
	return (0);
}

int				ft_reading_map(char **line, t_field *gen)
{
	int			y;

	y = 0;
	if (!(gen->field = (char**)malloc(sizeof(char*) * (gen->h_map + 1))))
		return (0);
	while (y < gen->h_map)
	{
		if (get_next_line(0, line) > 0)
		{
			if (!(gen->field[y] = (char *)malloc(gen->w_map + 1)))
				return (0);
			ft_strcpy(gen->field[y], &(*line)[4]);
			free(*line);
		}
		y++;
	}
	gen->field[y] = NULL;
	return (0);
}
