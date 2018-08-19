/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:11:37 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/14 19:38:20 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_stuff	*init_struct(t_stuff *e)
{
	e = (t_stuff *)malloc(sizeof(t_stuff));
	e->player = 0;
	e->dim_x = 0;
	e->dim_y = 0;
	e->dim_p_x = 0;
	e->dim_p_y = 0;
	e->start_x = 0;
	e->start_y = 0;
	e->end_x = 0;
	e->end_y = 0;
	e->map = NULL;
	return (e);
}

t_tok	*init_struct2(t_tok *token)
{
	token = (t_tok *)malloc(sizeof(t_tok));
	token->off_x = 0;
	token->off_y = 0;
	token->trim_x = 0;
	token->trim_y = 0;
	return (token);
}
