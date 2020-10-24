/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:17:31 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/24 13:53:02 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H

# include "libft.h"

typedef struct	s_field{
	char		player;
	char		opponent;
	char		**field;
	int			h_map;
	int			w_map;
	char		**piece;
	int			h_piece;
	int			w_piece;
	int			**heat_map;
	int			x;
	int			y;
}				t_field;

typedef struct	s_itplace{
	int			iter;
	int			place;
}				t_itplace;

int				ft_reading_player(char **line, t_field *general);
int				ft_reading_mapsize(char **line, t_field *general);
int				ft_reading_map(char **line, t_field *general);
int				ft_reading_piece(char **line, t_field *general);
int				ft_reading_piece_s(char **line, t_field *gen);
int				ft_solver(t_field *general);

int				ft_memhmap(t_field *general);
int				ft_create_h_map(t_field *general);
int				ft_setpiece(t_field *general);
void			ft_freeser(t_field *general);

#endif
