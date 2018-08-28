/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 07:04:21 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/28 08:05:01 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# define ABS(x) x < 0 ? -x : x

typedef struct		s_cord
{
	int				x;
	int				y;
	float			d;
	struct s_cord	*next;
}					t_cord;

typedef struct		s_fill
{
	char			player;
	int				dim_x;
	int				dim_y;
	int				piece_x;
	int				piece_y;
	int				len;
	int				*x_p;
	int				*y_p;
	int				enemy_x;
	int				enemy_y;
	char			**map;
	char			**token;
	t_cord			*head;
	t_cord			*last;
}					t_fill;

char				**get_map(int fd, t_fill *board);
char				**get_token(int fd, t_fill *board);
void				ft_plateu(int fd, t_fill *board);
void				init_algotithm(t_fill *board);
void				solve_result(t_fill *board);
#endif
