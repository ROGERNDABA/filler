/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:07:09 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/15 07:01:50 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

/*
** The structure that handles getting the map, dimensions and token.
** ->> player > checking which player you are.
** ->> dim_x > map downward dimentions, dim_y > sideward dimensions.
** ->> dim_p_x, dim_p_y, dimentions of the token_trim.
** ->> start_x, start_y, to check starting position of either X or Y.
** ->> map > The map itself
** ->> token > Hte token itself
*/

typedef struct	s_stuff
{
	int			player;
	int			dim_x;
	int			dim_y;
	int			dim_p_x;
	int			dim_p_y;
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;
	char		**map;
	char		**token;
}				t_stuff;

/*
** The structure for trimming the token_trim.
** ->> off_x, off_y > the position of the first star (*) in the token.
** ->> trim_x, trim_y > the postion of the last star (*) int the token.
*/

typedef struct	s_tok
{
	int			off_x;
	int			off_y;
	int			trim_x;
	int			trim_y;
}				t_tok;

/*
** Functions for get all the information about the vm output.
*/

void			get_info(t_stuff *e);
t_stuff 		*init_struct(t_stuff *e);
t_tok			*init_struct2(t_tok *token);
void			start_pos(t_stuff *e, char **map, char c);
void			get_map(t_stuff *e);
void			get_tok(t_stuff *e);
void			token_offset(t_tok *tok, t_stuff *e);
void			token_trim(t_tok *tok, t_stuff *e);
void 			find_pos(t_stuff *e, char c);

#endif
/*
** With love🌺
** From Roger
*/
