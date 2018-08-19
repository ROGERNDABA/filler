#include "filler.h"
#include <stdio.h>

void solve(t_stuff *e, t_tok *token)
{

	int i = e->start_x;
	int j;
	(e->player == 1) ? start_pos(e, e->map, 'O') : start_pos(e, e->map, 'X');
	(e->player == 1) ? find_pos(e, 'O') : find_pos(e, 'X');
	e->start_x = e->end_x;
	e->start_y = e->end_y;
	while (i < e->dim_x)
	{
		j = e->start_y;
		while (j < e->dim_y)
		{
			ft_putnbr(e->start_x - token->off_x);
			write(1, " ", 1);
			ft_putnbr(e->start_y - token->off_y);
			write(1, "\n", 1);
			j++;
		}
		i++;
	}
	//e->start_x = token->trim_x;
	//e->start_y = token->trim_y;
}

/*
void algorithm(int x0, int y0, int x1, int y1)
{

}*/



void find_pos(t_stuff *e, char c)
{
	int i;
	int j;

	i = 0;
	while (i < e->dim_x)
	{
		j = 0;
		while (j < e->dim_y)
		{

			if (e->map[i][j] == c)
			{
				e->end_x = i;
				e->end_y = j;
			}
			j++;
		}
		i++;
	}
}

int main()
{
	t_stuff *e = NULL;
	t_tok *token = NULL;

	e = init_struct(e);
	token = init_struct2(token);
	get_info(e);
	while (1)
	{
		get_map(e);
		get_tok(e);
		token_trim(token, e);
		solve(e, token);
		free(e->map);
	}
	return (0);
}
