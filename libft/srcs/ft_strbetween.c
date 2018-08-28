/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbetween.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 02:20:54 by rmdaba            #+#    #+#             */
/*   Updated: 2018/07/19 02:20:56 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strbetween(const char *s, char a, char b)
{
	char	*res;
	size_t	r;

	if (!s)
		return (NULL);
	res = ft_strnew(0);
	r = 0;
	while (*s)
	{
		if (*s == b && r > 0)
			if (--r == 0)
				return (res);
		if (r > 0)
		{
			if (*s == '\\')
				++s;
			if (!(res = ft_strjoinc_clr(res, *s)))
				return (NULL);
		}
		if (*s == a)
			++r;
		++s;
	}
	return (res);
}
