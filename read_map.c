/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:22:04 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/10 15:19:46 by aeclipso         ###   ########.fr       */
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
	}
	get_next_line(0, line);
	free(*line);
	return (1);
}

int				ft_reading_map(char **line, t_field *general)
{
	int			y;

	y = 0;
	if (!(general->field = (char**)malloc(sizeof(char*) * (general->h_map + 1))))
		return (0);
	while (y < general->h_map)
	{
		if (get_next_line(0, line) > 0)
		{
			if (!(general->field[y] = (char *)malloc(sizeof(char) * (general->w_map + 1))))
				return (0);
			ft_strcpy(general->field[y], &(*line)[4]);
			free(*line);
		}
		y++;
	}
	general->field[y] = NULL;
	return (1);
}