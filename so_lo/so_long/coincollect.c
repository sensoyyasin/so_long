/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coincollect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:26:30 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/27 11:25:46 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	topcoin(t_img *so_long)
{
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
		so_long->floor, so_long->x_kord - 32, so_long->y_kord - 32);
	so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
	so_long->map[so_long->y_kord - 2][so_long->x_kord - 1] = 'P';
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
		so_long->player, so_long->x_kord - 32, so_long->y_kord - 64);
	so_long->g_move++;
	printf("%d\n", so_long->g_move);
	put_xpm(so_long);
	so_long->coin += 1;
}

void	leftcoin(t_img *so_long)
{
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
		so_long->floor, so_long->x_kord - 32, so_long->y_kord - 32);
	so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
	so_long->map[so_long->y_kord - 1][so_long->x_kord - 2] = 'P';
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
		so_long->player, so_long->x_kord - 32, so_long->y_kord - 64);
	so_long->g_move++;
	printf("%d\n", so_long->g_move);
	put_xpm(so_long);
	so_long->coin += 1;
}

void	downcoin(t_img *so_long)
{
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
		so_long->floor, so_long->x_kord - 32, so_long->y_kord - 32);
	so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
	so_long->map[so_long->y_kord][so_long->x_kord - 1] = 'P';
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
		so_long->player, so_long->x_kord - 32, so_long->y_kord - 64);
	so_long->g_move++;
	printf("%d\n", so_long->g_move);
	put_xpm(so_long);
	so_long->coin += 1;
}

void	rightcoin(t_img *so_long)
{
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
		so_long->floor, so_long->x_kord - 32, so_long->y_kord - 32);
	so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
	so_long->map[so_long->y_kord - 1][so_long->x_kord] = 'P';
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
		so_long->player, so_long->x_kord - 32, so_long->y_kord - 64);
	so_long->g_move++;
	printf("%d\n", so_long->g_move);
	put_xpm(so_long);
	so_long->coin += 1;
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
		while (so_long -> map[so_long->y_kord][so_long->x_kord] != '\n' &&
			key == 1)
		{
			if (so_long -> map[so_long->y_kord][so_long->x_kord] == 'P')
			key = 0;
			so_long->x_kord++;
		}
		so_long->y_kord++;
	}
}
