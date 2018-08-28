/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 01:10:23 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/19 01:36:24 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstaddback(t_dlist **head, t_dlist *new)
{
	t_dlist	*ptr;

	if (!new || !head)
		return ;
	while (*head && (*head)->next)
		head = &(*head)->next;
	ptr = *head;
	if (*head)
		(*head)->next = new;
	else
		*head = new;
	new->prev = ptr;
}
