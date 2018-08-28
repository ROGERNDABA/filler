/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 07:04:15 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/28 08:09:27 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** gets co-ordinates of the first star in the token_offset
*/

static void		token_offset(char *line, t_fill *board)
{
	while (!(ft_isdigit(*line)))
		line++;
	board->piece_y = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line++;
	board->piece_x = ft_atoi(line);
}

static char		*ft_line_purs(char *line, t_fill *board)
{
	char *gen;

	gen = ft_strnew(board->dim_x);
	gen = ft_strcpy(gen, line);
	return (gen);
}

/*
** gets the token line by line
*/

char			**get_token(int fd, t_fill *board)
{
	char		**piece;
	char		*line;
	int			ret;
	int			i;

	ret = get_next_line(fd, &line);
	token_offset(line, board);
	i = 0;
	piece = (char **)malloc(sizeof(char *) * (board->piece_y + 1));
	(ret > 0) ? free(line) : 0;
	while ((i < (board->piece_y)) && (ret > 0))
	{
		ret = get_next_line(fd, &line);
		piece[i] = ft_line_purs(line, board);
		(ret > 0) ? free(line) : 0;
		i++;
	}
	piece[i] = NULL;
	return (piece);
}
