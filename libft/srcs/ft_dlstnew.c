/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 00:55:02 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/19 01:04:49 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(void const *content, size_t data_size)
{
	t_dlist	*new_node;

	new_node = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new_node)
		return (NULL);
	ft_bzero(new_node, sizeof(t_dlist));
	if (!content)
	{
		new_node->data = NULL;
		new_node->data_size = 0;
	}
	else
	{
		new_node->data = (void *)malloc(data_size);
		if (!new_node->data)
			return (NULL);
		ft_memcpy(new_node->data, content, data_size);
		new_node->data_size = data_size;
	}
	return (new_node);
}
