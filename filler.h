/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:17:31 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/07 23:25:34 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

#include "./libft-printf/include/libft.h"

typedef struct s_field{
	int			player;         //if player 0 - letter O, else X
	int			opponent;       //if opponent 1 - letter X, else O
	char		**field;         //field after reading
	char		**token;         //token, after reading
	int			h;
	int			w;
}t_field;

int				ft_reading_player(char **line, t_field *general);
#endif //FILLER_FILLER_H
