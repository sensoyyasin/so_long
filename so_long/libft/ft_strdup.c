/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:37:55 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/29 21:35:13 by yasinsensoy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*p;
	int		i;
	int		e;

	e = 0;
	i = ft_strlen2(src);
	p = (char *) malloc(i + 1);
	if (p == NULL)
		return (NULL);
	while (src[e] != '\0')
	{
		p[e] = src[e];
		e++;
	}
	p[i] = '\0';
	return (p);
}
