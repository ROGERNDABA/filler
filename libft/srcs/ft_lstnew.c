/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:42:52 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/20 17:45:37 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t data_size)
{
	t_list	*r;

	if (!(r = (t_list *)malloc(sizeof(*r))))
		return (NULL);
	if (content == NULL)
	{
		r->data = NULL;
		r->data_size = 0;
	}
	else
	{
		if (!(r->data = ft_memdup(content, data_size)))
		{
			free(r);
			return (NULL);
		}
		r->data_size = data_size;
	}
	return (r);
}
