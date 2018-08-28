/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 07:02:43 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/27 07:47:12 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** getting the board dimensions
*/

void			dimmensions(int fd, t_fill *board)
{
	int			ret;
	char		*line;
	char		*line_2;

	ret = get_next_line(fd, &line);
	line_2 = line;
	while (!(ft_isdigit(*line)))
		line++;
	board->dim_y = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line++;
	board->dim_x = ft_atoi(line);
	(ret > 0) ? free(line_2) : 0;
}

/*
** line number with either player I am
*/

static char		*make_line(char *line, t_fill *board)
{
	char		*gen;

	gen = ft_strnew(board->dim_x);
	while (*line && *line != '.' && *line != 'X' &&
		*line != 'x' && *line != 'O' && *line != 'o')
		line++;
	gen = ft_strcpy(gen, line);
	return (gen);
}

/*
** get the map line by line_2
*/

char			**get_map(int fd, t_fill *board)
{
	char		**map;
	char		*line;
	int			ret;
	int			i;

	i = 0;
	dimmensions(fd, board);
	map = (char **)malloc(sizeof(char *) * (board->dim_y + 1));
	ret = get_next_line(fd, &line);
	(ret > 0) ? free(line) : 0;
	while ((i < (board->dim_y)) && (ret > 0))
	{
		ret = get_next_line(fd, &line);
		map[i] = make_line(line, board);
		(ret > 0) ? free(line) : 0;
		i++;
	}
	map[i] = NULL;
	return (map);
}
