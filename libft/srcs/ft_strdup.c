/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:44:19 by rmdaba            #+#    #+#             */
/*   Updated: 2018/05/22 13:48:26 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	void	*new;

	len = ft_strlen(s) + 1;
	new = malloc(len);
	if (new == NULL)
		return (NULL);
	return ((char *)ft_memcpy(new, s, len));
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*snew;

	if (!(snew = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	snew[n] = '\0';
	return (ft_strncpy(snew, s, n));
}

char	*ft_strmdup(const char *a, size_t n)
{
	return (ft_strndup(a, ft_strlen(a) + n));
}
