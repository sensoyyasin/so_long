/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:49:38 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/29 21:35:28 by yasinsensoy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsizi)
{
	size_t	a;
	size_t	de;
	size_t	sr;

	de = ft_strlen2(dest);
	sr = ft_strlen2((char *)src);
	a = 0;
	if (dstsizi <= de)
		return (dstsizi + sr);
	while (src[a] != '\0' && de + a + 1 < dstsizi)
	{
		dest[de + a] = src[a];
		a++;
	}
	dest[de + a] = '\0';
	return (de + sr);
}
