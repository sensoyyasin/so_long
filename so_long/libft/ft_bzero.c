/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:10:12 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/29 21:31:29 by yasinsensoy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *giren, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		((unsigned char *) giren)[a] = '\0';
		a++;
	}
	return (giren);
}
