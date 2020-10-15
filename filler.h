/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h_map                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:17:31 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/08 14:01:40 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

#include "./libft-printf/include/libft.h"
# define REV_NAME "]rellif.ospilcea"

typedef struct	s_field{
	char		player;			//if player 0 - letter O, else X
	char		opponent;		//if opponent 1 - letter X, else O
	char		**field;		//field after reading, don't forget free memory, after game
	int			h_map;			//visota karty 
	int			w_map;			//shirina karty
	char		**piece;		//piece, after reading
	int			h_piece;		//visota kuska
	int			w_piece;		//shirina kuska
	int			**heat_map;
	int			x;				//reshenie x
	int			y;				//reshenie y
}				t_field;

typedef struct	s_itplace{
	int			iter;
	int			place;
}				t_itplace;


int			ft_reading_player(char **line, t_field *general);
int				ft_reading_mapsize(char **line, t_field *general);
int				ft_reading_map(char **line, t_field *general);
int				ft_reading_piece(char **line, t_field *general);
int				ft_solver(t_field *general);

int				ft_memhmap(t_field *general);
int				ft_create_h_map(t_field *general);
int				ft_setpiece(t_field *general);
void			ft_freeser(t_field *general);

#endif //FILLER_FILLER_H
