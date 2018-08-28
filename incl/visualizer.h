/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:07:09 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/28 08:08:04 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "libft.h"

/*
** The structure that handles getting the map, dimensions and token.
*/

typedef struct	s_stuff
{
	int			player;
	int			dim_x;
	int			dim_y;
	int			dim_p_x;
	int			dim_p_y;
	int			score_o;
	int			score_x;
	char		*pl1;
	char		*pl2;
	char		**map;
	char		**token;
}				t_stuff;

/*
** Functions for get all the information about the vm output
** then cabam!!!, it draws
*/

void			get_info(t_stuff *e);
t_stuff			*init_struct(t_stuff *e);
void			start_pos(t_stuff *e, char **map, char c);
void			get_map(t_stuff *e);
void			find_pos(t_stuff *e, char c);
void			get_tok(void);
void			norm(t_stuff *e, char *line);

#endif

/*
** With love🌺
** From Roger
*/
