/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstremoveif.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 01:11:17 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/19 01:11:54 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstremoveif(t_dlist **head, int cmp())
{
	t_dlist	*ptr;

	while (*head)
	{
		if (cmp((*head)->data, (*head)->data_size))
		{
			if ((*head)->prev)
				(*head)->prev->next = (*head)->next;
			if ((*head)->next)
				(*head)->next->prev = (*head)->prev;
			ptr = *head;
			*head = (*head)->prev ? (*head)->prev : (*head)->next;
			free(ptr->data);
			free(ptr);
		}
		head = &(*head)->next;
	}
}
