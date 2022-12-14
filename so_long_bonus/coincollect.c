/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coincollect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:42:09 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/27 15:56:35 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	topcoin(t_img *so_long)
{
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
		so_long->floor, so_long->x_kord - 32, so_long->y_kord - 32);
	so_long->map[so_long->y_kord - 1][so_long->x_kord - 1] = '0';
	so_long->map[so_long->y_kord - 2][so_long->x_kord - 1] = 'P';
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
		so_long->player, so_long->x_kord - 32, so_long->y_kord - 64);
	so_long->g_move++;
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
	put_xpm(so_long);
	so_long->coin += 1;
}
