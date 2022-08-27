/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:41:00 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/27 12:39:39 by ysensoy          ###   ########.fr       */
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
				so_long->d_lx = j;
				so_long->d_ly = i;
			}
			j++;
		}
		i++;
	}
}

void	move_enemytwo(t_img *so_long, int index)
{
	so_long->d_ly = 1;
	if (so_long->map[so_long->d_ly][so_long->d_lx] == 'P')
		exit(0);
	so_long->map[so_long->d_ly][so_long->d_lx] = 'D';
	so_long->map[so_long->d_ly + 3][so_long->d_lx] = '0';
	put_xpm(so_long);
}

void	move_enemy(t_img *so_long, int index)
{
	enemy_location(so_long);
	if ((so_long->map[so_long->d_ly + 1][so_long->d_lx] == '0'
		|| so_long->map[so_long->d_ly + 1][so_long->d_lx] == 'P')
		&& index % 10 == 6)
	{
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->floor, so_long->d_lx - 32, so_long->d_ly - 32);
		if (so_long->map[so_long->d_ly + 1][so_long->d_lx] == 'P')
		{
			so_long->map[so_long->d_ly + 1][so_long->d_lx] = 'D';
			exit(0);
		}
		so_long->map[so_long->d_ly][so_long->d_lx] = '0';
		so_long->map[so_long->d_ly + 1][so_long->d_lx] = 'D';
		so_long->d_ly++;
		put_xpm(so_long);
	}
	else if (so_long->map[so_long->d_ly + 1][so_long->d_lx] == '1'
		&& so_long->index % 10 == 6)
		move_enemytwo(so_long, index);
}
