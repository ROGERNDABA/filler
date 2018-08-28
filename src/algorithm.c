/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 07:02:40 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/28 08:09:27 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		best_cord(t_fill *board, int len)
{
	int			x;
	int			y;
	int			i;

	i = 0;
	y = 0;
	board->x_p = (int*)malloc(sizeof(int) * len);
	board->y_p = (int*)malloc(sizeof(int) * len);
	while (board->token[y] != NULL)
	{
		x = 0;
		while (board->token[y][x] != '\0')
		{
			if (board->token[y][x] == '*')
			{
				board->x_p[i] = x;
				board->y_p[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

static void		strategy(t_fill *board)
{
	int			x;
	int			y;

	y = 0;
	board->len = 0;
	while (board->token[y] != NULL)
	{
		x = 0;
		while (board->token[y][x] != '\0')
		{
			(board->token[y][x] == '*') ? board->len++ : 0;
			x++;
		}
		y++;
	}
	best_cord(board, board->len);
}

/*
** creates the list of the best co-ordinate based on the disatnce from
** the enemy
*/

static void		best_cordinate(t_fill *board, int x, int y)
{
	t_cord		*new;

	new = (t_cord*)malloc(sizeof(t_cord));
	new->x = x;
	new->y = y;
	new->next = NULL;
	if (board->head == NULL)
	{
		board->head = new;
		board->last = new;
	}
	else
	{
		board->last->next = new;
		board->last = board->last->next;
	}
}

/*
** checks the current position if it's valid, then saves the
** co-ordinates in the co-ordinate struct else just ignores
** that position
*/

static void		check_position(t_fill *board, int x, int y, int n)
{
	int			i;
	int			xy[2];
	int			xyh[2];

	xyh[0] = x;
	xyh[1] = y;
	while (++n < board->len)
	{
		xy[0] = xyh[0] - board->x_p[n];
		xy[1] = xyh[1] - board->y_p[n];
		i = -1;
		while (++i < board->len)
		{
			if (i == n)
				continue ;
			x = xy[0] + board->x_p[i];
			y = xy[1] + board->y_p[i];
			if (x < 0 || y < 0 || y >= board->dim_y ||
				x >= board->dim_x || board->map[y][x] != '.')
				break ;
		}
		(i == board->len) ? best_cordinate(board, xy[0], xy[1]) : 0;
	}
}

/*
** checks the result from the solving algorithm if the is any more
** positions to place at else returns co-ordinates 0 0 meaning
** co-ordinates struct is empty
*/

void			init_algotithm(t_fill *board)
{
	int			i;
	int			j;

	j = 0;
	strategy(board);
	while (j < board->dim_y)
	{
		i = -1;
		while (++i < board->dim_x)
		{
			if ((board->map[j][i] == board->player) ||
				(board->map[j][i] == (board->player + 32)))
				check_position(board, i, j, -1);
		}
		j++;
	}
	if (board->head == NULL)
	{
		ft_printf("%d %d\n", 0, 0);
		exit(0);
	}
	solve_result(board);
}
