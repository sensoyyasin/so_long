/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:57:41 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/29 21:34:24 by yasinsensoy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *gelen, int a, size_t b)
{
	size_t	i;

	i = 0;
	while (i < b)
	{
		((unsigned char *)gelen)[i] = a;
		i++;
	}
	return (gelen);
}
