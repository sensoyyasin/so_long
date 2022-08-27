/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrollertwo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:50:00 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/27 11:32:56 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	iswalltrue(t_img *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (j < so_long->leny - 1)
		{
			if (so_long->map[0][j] != '1' || so_long->map[i][0] != '1')
			{
				write (1, "Error\n", 6);
				exit(1);
			}
			if (so_long->map[so_long->lenx - 1][j] != '1'
				|| so_long->map[i][so_long->leny - 1] != '1')
			{
				write (1, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	isduplicate(t_img *so_long, int i, int j)
{
	int	p_counter;

	p_counter = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'P')
				p_counter++;
			j++;
		}
		i++;
	}
	if (p_counter <= 0 || p_counter >= 2)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	definevar(t_img *so_long)
{
	int	a;

	a = 32;
	so_long->h = &a;
	so_long->w = &a;
	so_long->coin = 0;
	so_long->index = 0;
	so_long->lenx = line_length(so_long);
	so_long->leny = column_length(so_long);
}
