/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontroller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:32:09 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/27 17:19:10 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	isrectangular(t_img *so_long)
{
	int		temp;
	int		i;
	int		j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
			j++;
		if (i != 0 && j != temp)
		{
			write (1, "Error\n", 6);
			free(so_long->map);
			free(so_long);
			exit(1);
		}
		temp = j;
		i++;
	}
}

void	ismaptrue(t_img *so_long)
{
	int		i;
	int		j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'E' || so_long->map[i][j] == 'C'
				|| so_long->map[i][j] == 'P' || so_long->map[i][j] == '1'
				|| so_long->map[i][j] == '0' || so_long->map[i][j] == '\n'
				|| so_long->map[i][j] == 'D')
				j++;
			else
			{
				write(1, "Haritada farkli harf var\n", 25);
				free(so_long->map);
				free(so_long);
				exit(1);
			}
		}
		i++;
	}
}

void	isargtrue(t_img *so_long)
{
	int	len;

	len = ft_strlen(so_long->map_input[1]);
	if (so_long->map_input[1][len - 1] != 'r' ||
		so_long->map_input[1][len - 2] != 'e')
	{
		write (1, "Error\n", 6);
		exit(1);
	}
	else if (so_long->map_input[1][len - 3] != 'b' ||
		so_long->map_input[1][len - 4] != '.')
	{
		write (1, "Error\n", 6);
		exit(0);
	}
}

void	iscollectible(t_img *so_long)
{
	int		i;
	int		j;
	int		c_counter;

	i = 0;
	c_counter = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'C')
				c_counter++;
			j++;
		}
		i++;
	}
	if (c_counter <= 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	allfunc(t_img *so_long)
{
	isrectangular(so_long);
	ismaptrue(so_long);
	iswalltrue(so_long);
	isduplicate(so_long, 0, 0);
	iscollectible(so_long);
}
