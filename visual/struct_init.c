/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:11:37 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/27 20:09:17 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	norm(t_stuff *e, char *line)
{
	char	**s;

	s = ft_strsplit(line, ' ');
	e->dim_x = ft_atoi(s[1]);
	e->dim_y = ft_atoi(s[2]);
	free(s[0]);
	free(s[1]);
	free(s[2]);
}

t_stuff	*init_struct(t_stuff *e)
{
	e = (t_stuff *)malloc(sizeof(t_stuff));
	e->player = 0;
	e->dim_x = 0;
	e->dim_y = 0;
	e->dim_p_x = 0;
	e->dim_p_y = 0;
	e->score_o = 0;
	e->score_x = 0;
	e->pl1 = NULL;
	e->pl2 = NULL;
	e->map = NULL;
	return (e);
}
