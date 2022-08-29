/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:49:14 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/29 21:36:12 by yasinsensoy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*sondonus(char *bas, char *son)
{
	char	*ol;
	int		size;
	int		i;

	i = 0;
	size = son - bas;
	ol = malloc(size + 2);
	if (!ol)
		return (NULL);
	while (i <= size)
	{
		ol[i] = *bas;
		bas++;
		i++;
	}
	ol[i] = '\0';
	return (ol);
}

int	kontrol(char c, char *g)
{
	while (*g != '\0')
	{
		if (c == *g)
			return (1);
		g++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			i;
	size_t		a;
	char const	*bas;
	char const	*son;
	char		*gelen;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	a = ft_strlen2(s1) - 1 ;
	while (kontrol(s1[i], (char *)set))
		i++;
	bas = &s1[i];
	while (kontrol(s1[a], (char *)set))
		a--;
	son = &s1[a];
	if (son - bas < 0)
		return (ft_strdup(""));
	gelen = sondonus((char *)bas, (char *)son);
	return (gelen);
}
