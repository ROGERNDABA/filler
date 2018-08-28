/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 19:48:59 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/27 20:09:17 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"
#include <stdio.h>

void	welcome(void)
{
	ft_printf(BLUE"\n\n::::::::::  :::::::::::  :::");
	ft_printf("         :::         ::::::::::  ::::::::: \n");
	ft_printf(":+:             :+:      :+:");
	ft_printf("         :+:         :+:         :+:    :+:\n");
	ft_printf("+:+             +:+      +:+");
	ft_printf("         +:+         +:+         +:+    +:+\n");
	ft_printf(":#::+::#        +#+      +#+");
	ft_printf("         +#+         +#++:++#    +#++:++#: \n");
	ft_printf("+#+             +#+      +#+");
	ft_printf("         +#+         +#+         +#+    +#+\n");
	ft_printf("#+#             #+#      #+#");
	ft_printf("         #+#         #+#         #+#    #+#\n");
	ft_printf("###         ###########  ###");
	ft_printf("#######  ##########  ##########  ###    ###"DEFAULT);
	ft_printf(YELLOW"\n\n                    💛💛 BY : ROGER NDABA 💛💛\n\n");
}

void	count_score(t_stuff *e, char c)
{
	if (c == 'O' || c == 'o')
	{
		if (c == 'O')
			e->score_o++;
		ft_printf("🔷");
	}
	else if (c == 'X' || c == 'x')
	{
		ft_printf("🔶");
		if (c == 'X')
			e->score_x++;
	}
	else
		ft_printf("⬛️");
}

void	draw(t_stuff *e)
{
	int i;
	int j;

	i = -1;
	ft_printf(BLUE"\n\n    🔷 %s\n", e->pl1);
	ft_printf(BLUE"       %d\n\n"DEFAULT, e->score_o);
	ft_printf(YELLOW"    🔶 %s\n", e->pl2);
	ft_printf(YELLOW"       %d\n\n"DEFAULT, e->score_x);
	e->score_o = 0;
	e->score_x = 0;
	while (++i < e->dim_x)
	{
		ft_printf(DEFAULT"    " BLOCK"               "DEFAULT " ");
		j = -1;
		while (++j < e->dim_y)
		{
			count_score(e, e->map[i][j]);
			j++;
		}
		ft_printf("\n"DEFAULT);
	}
}

int		main(void)
{
	t_stuff *e;

	e = NULL;
	e = init_struct(e);
	get_info(e);
	ft_printf(CLEA"");
	while (1)
	{
		get_map(e);
		get_tok();
		ft_printf(CL"\e[?25l"DEFAULT);
		welcome();
		draw(e);
	}
	return (0);
}
