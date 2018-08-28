/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstgettail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 01:08:01 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/19 01:09:45 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstgettail(t_dlist *dlst)
{
	while (dlst)
	{
		if (dlst->next)
			dlst = dlst->next;
		else
			break ;
	}
	return (dlst);
}
