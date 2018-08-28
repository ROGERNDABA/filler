/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:44:29 by rmdaba            #+#    #+#             */
/*   Updated: 2018/07/19 00:59:15 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcleanjoin(char *s1, const char *s2)
{
	char	*tmp;

	if (!(tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(tmp, s1);
	free(s1);
	ft_strcat(tmp, s2);
	return (tmp);
}

char	*ft_strjoinc_clr(char *a, char b)
{
	char	*s;

	if ((s = ft_strmdup(a, 1)) == NULL)
		return (NULL);
	s[ft_strlen(a)] = b;
	free(a);
	return (s);
}

char	*ft_strjoin_clr(char *a, char *b, int d)
{
	char	*s;

	if (!(s = ft_strnew(ft_strlen(a) + ft_strlen(b))))
		return (NULL);
	if (a)
		ft_strcat(s, a);
	if (b)
		ft_strcat(s, b);
	if (d == 2 || d == 0)
		free(a);
	if (d == 2 || d == 1)
		free(b);
	return (s);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if ((tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		tmp[i] = s1[j];
		i += 1;
		j += 1;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		tmp[i] = s2[j];
		i += 1;
		j += 1;
	}
	return (tmp);
}
