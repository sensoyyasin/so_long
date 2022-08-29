/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:56:55 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/29 21:34:17 by yasinsensoy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *gelen, const void *in, size_t b)
{
	if (!gelen && !in)
		return (NULL);
	if (gelen < in)
		ft_memcpy (gelen, in, b);
	else if (gelen > in)
	{
		while (b--)
			*((unsigned char *)(gelen + b)) = *((unsigned char *)(in + b));
	}
	return (gelen);
}
