/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:12:57 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/07 23:22:11 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int             ft_core(void)
{
	char        *line;
	t_field     general;
	
	ft_reading_player(&line, &general);
	ft_reading_mapsize();
	
}

int             main(void)
{
	ft_core();
}


