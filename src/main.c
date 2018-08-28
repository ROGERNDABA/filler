/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 07:04:11 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/28 08:05:37 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			ft_get_player(int fd, t_fill *board)
{
	char			*line;
	int				ret;

	ret = get_next_line(fd, &line);
	if (ret == 0)
		exit(0);
	if (ft_strstr(line, "$$$"))
	{
		if (ft_strstr(line, "p1"))
			board->player = 'O';
		else if (ft_strstr(line, "p2"))
			board->player = 'X';
	}
	(ret > 0) ? free(line) : 0;
}

static void			free_cord_struct(t_fill *board)
{
	t_cord			*dell;

	while (board->head != NULL)
	{
		dell = board->head;
		board->head = board->head->next;
		free(dell);
	}
	board->head = NULL;
	board->last = NULL;
}

static void			free_fill_struct(t_fill *board)
{
	int				i;

	i = 0;
	free(board->x_p);
	free(board->y_p);
	board->x_p = NULL;
	board->y_p = NULL;
	while (board->map[i] != NULL)
	{
		ft_strdel(&board->map[i]);
		i++;
	}
	free(board->map);
	board->map = NULL;
	i = 0;
	while (board->token[i] != NULL)
	{
		ft_strdel(&board->token[i]);
		i++;
	}
	free(board->token);
	board->token = NULL;
	free_cord_struct(board);
}

int					main(void)
{
	t_fill			board;
	int				fd;

	fd = 0;
	ft_get_player(fd, &board);
	while (1)
	{
		board.map = get_map(fd, &board);
		board.token = get_token(fd, &board);
		board.head = NULL;
		board.last = NULL;
		init_algotithm(&board);
		free_fill_struct(&board);
	}
	return (0);
}
