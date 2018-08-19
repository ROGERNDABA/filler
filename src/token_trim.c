/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_trim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:10:01 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/14 15:10:59 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	token_offset(t_tok *tok, t_stuff *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->dim_p_x)
	{
		j = 0;
		while (j < e->dim_p_y)
		{
			if (e->token[i][j] == '*')
			{
				tok->off_x = i;
				tok->off_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	token_trim(t_tok *tok, t_stuff *e)
{
	int		i;
	int		j;

	i = 0;
	token_offset(tok, e);
	while (i < e->dim_p_x)
	{
		j = 0;
		while (j < e->dim_p_y)
		{
			if (e->token[i][j] == '*')
			{
				tok->trim_x = i;
				tok->trim_y = j;
			}
			j++;
		}
		i++;
	}
}
