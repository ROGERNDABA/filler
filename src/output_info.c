/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:04:21 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/14 19:58:48 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_info(t_stuff *e)
{
	char	*line;
	char	**s;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "$$$ exec p") &&
			ft_strstr(line, "[./Roger.filler]"))
		{
			e->player = ft_atoi(ft_strchr(line, 'p') + 1);
			continue;
		}
		else if (ft_strstr(line, "Plateau"))
		{
			s = ft_strsplit(line, ' ');
			e->dim_x = ft_atoi(s[1]);
			e->dim_y = ft_atoi(s[2]);
			continue ;
		}
		else if (ft_strstr(line, "    0123"))
			break ;
		free(line);
	}
}

void	get_map(t_stuff *e)
{
	int		i;
	char	**s;
	char	*line;

	i = 0;
	e->map = (char **)malloc(sizeof(char *) * e->dim_y);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Piece ") == NULL)
			e->map[i] = strdup(line + 4);
		else
			break ;
		i++;
	}
	s = ft_strsplit(line, ' ');
	e->dim_p_x = ft_atoi(s[1]);
	e->dim_p_y = ft_atoi(s[2]);
}

void	start_pos(t_stuff *e, char **map, char c)
{
	int		i;
	int		j;

	i = 1;
	while (i < e->dim_x - 1)
	{
		j = 1;
		while (j < e->dim_y - 1)
		{
			if (map[i][j] == c && map[i][j - 1] == '.' &&
			map[i][j + 1] == '.' && map[i - 1][j] == '.' &&
			map[i + 1][j] == '.')
			{
				e->start_x = i;
				e->start_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	get_tok(t_stuff *e)
{
	int		i;
	char	*line;

	i = 0;
	e->token = (char **)malloc(sizeof(char *) * e->dim_p_x);
	while (i < e->dim_p_x)
	{
		get_next_line(0, &line);
		e->token[i] = ft_strdup(line);
		free(line);
		i++;
	}
}
