/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   results.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 06:58:32 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/27 08:03:33 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** checks the current position of the enemy_y
*/

static void		enemy_where(t_fill *board)
{
	int			x;
	int			y;
	char		opnt;

	opnt = (board->player == 'O') ? 'X' : 'O';
	y = 0;
	board->enemy_x = (board->dim_x / 2);
	board->enemy_y = (board->dim_y / 2);
	while (board->map[y] != NULL)
	{
		x = -1;
		while (board->map[y][++x] != '\0')
		{
			if (board->map[y][x] == (opnt + 32))
			{
				board->enemy_x = x;
				board->enemy_y = y;
				break ;
			}
		}
		y++;
	}
}

/*
** checks the closest disatce to the enemy and updates the placing
** co-ordinates to those closest
*/

static void		get_dist_enemy(t_fill *board, int u, t_cord *list)
{
	float		d_min;
	int			i;

	i = 0;
	list = board->head;
	d_min = list->d;
	while (list != NULL)
	{
		if (d_min > list->d)
		{
			d_min = list->d;
			u = i;
		}
		list = list->next;
		i++;
	}
	i = 0;
	list = board->head;
	while (i < u && list != NULL)
	{
		list = list->next;
		i++;
	}
	ft_printf("%d %d\n", list->y, list->x);
}

static void		best_dist(t_fill *board)
{
	int			tmp1;
	int			tmp2;
	t_cord		*list;

	if (board->head == NULL)
		return ;
	list = board->head;
	while (list != NULL)
	{
		tmp1 = (board->enemy_x) * (board->enemy_x) - 2 *
			(board->enemy_x) * (list->x) + (list->x) * (list->x);
		tmp2 = (board->enemy_y) * (board->enemy_y) - 2 *
			(board->enemy_y) * (list->y) + (list->y) * (list->y);
		list->d = ft_rsqrt(tmp1 + tmp2);
		list = list->next;
	}
	get_dist_enemy(board, 0, NULL);
}

void			solve_result(t_fill *board)
{
	enemy_where(board);
	best_dist(board);
}
