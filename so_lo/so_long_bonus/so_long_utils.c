/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:24:10 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/26 18:24:49 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	coin_counter(t_img *so_long)
{
	int	i;
	int	j;

	i = 0;
	so_long->g_coin = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'C')
				so_long->g_coin++;
			j++;
		}
		i++;
	}
}

void	player(t_img *so_long)
{
	int	key;

	so_long->x_kord = 0;
	so_long->y_kord = 0;
	key = 1;
	while (so_long -> map[so_long->y_kord][so_long->x_kord] && key == 1)
	{
		so_long->x_kord = 0;
		while (so_long -> map[so_long->y_kord][so_long->x_kord] != '\n'
			&& key == 1)
		{
			if (so_long -> map[so_long->y_kord][so_long->x_kord] == 'P')
			key = 0;
			so_long->x_kord++;
		}
		so_long->y_kord++;
	}
}
