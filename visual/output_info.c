/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:04:21 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/27 20:09:17 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

char	*capitals(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - ('a' - 'A');
	}
	return (str);
}

char	*terate(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '/')
		{
			line = line + i;
			i = 0;
		}
		i++;
	}
	line[i - 8] = '\0';
	return (capitals(line + 1));
}

void	get_info(t_stuff *e)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "p1 : [./"))
		{
			e->pl1 = terate(line);
			continue ;
		}
		else if (ft_strstr(line, "p2 : [./"))
		{
			e->pl2 = terate(line);
			continue ;
		}
		else if (ft_strstr(line, "Plateau"))
		{
			norm(e, line);
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

void	get_tok(void)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "    0123"))
			break ;
		else if (ft_strstr(line, "== O fin:"))
		{
			ft_printf(BLUE"\n    🔷 Actual score  =");
			ft_printf("%s\n\n", ft_strchr(line, ':') + 1);
			if (get_next_line(0, &line) > 0)
			{
				ft_printf(YELLOW"    🔶 Actual score  =");
				ft_printf("%s\n\n"DEFAULT, ft_strchr(line, ':') + 1);
			}
			exit(1);
		}
	}
}
