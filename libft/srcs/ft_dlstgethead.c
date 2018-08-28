/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstgethead.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 01:06:54 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/19 01:07:13 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstgethead(t_dlist *dlst)
{
	while (dlst)
	{
		if (dlst->prev)
			dlst = dlst->prev;
		else
			break ;
	}
	return (dlst);
}
