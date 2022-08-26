/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:41:00 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/26 17:58:06 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_location(t_img *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'D')
			{
				so_long->d_locationx = j;
				so_long->d_locationy = i;
			}
			j++;
		}
		i++;
	}
}

void	move_enemy(t_img *so_long, int index)
{
	enemy_location(so_long);
	if ((so_long->map[so_long->d_locationy + 1][so_long->d_locationx] == '0'
		|| so_long->map[so_long->d_locationy + 1][so_long->d_locationx] == 'P') && index % 10 == 6)
	{
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->floor, so_long->d_locationx - 32,
				so_long->d_locationy - 32);
		if (so_long->map[so_long->d_locationy + 1][so_long->d_locationx] == 'P')
		{
			so_long->map[so_long->d_locationy + 1][so_long->d_locationx] = 'D';
			exit(0);
		}
		so_long->map[so_long->d_locationy][so_long->d_locationx] = '0';
		so_long->map[so_long->d_locationy + 1][so_long->d_locationx] = 'D';
		so_long->d_locationy++;
		put_xpm(so_long);
	}
	else if (so_long->map[so_long->d_locationy + 1][so_long->d_locationx] == '1'
		&& so_long->index % 10 == 6)
	{
		so_long->d_locationy = 1;
		if (so_long->map[so_long->d_locationy][so_long->d_locationx] == 'P')
			exit(0);
		so_long->map[so_long->d_locationy][so_long->d_locationx] = 'D';
		so_long->map[so_long->d_locationy + 3][so_long->d_locationx] = '0';
		put_xpm(so_long);
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
