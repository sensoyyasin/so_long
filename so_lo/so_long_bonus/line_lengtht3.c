/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_lengtht3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:30:34 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/27 12:30:42 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_draw(t_img *so_long, void *image, int x, int y)
{
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, image, x * 32, y * 32);
}

void	addimage(t_img *so_long)
{
	so_long->wall = mlx_xpm_file_to_image(so_long->mlx,
			"./img/torch.xpm", so_long->w, so_long->h);
	so_long->exit = mlx_xpm_file_to_image(so_long->mlx,
			"./img/door.xpm", so_long->w, so_long->h);
	so_long->player = mlx_xpm_file_to_image(so_long->mlx,
			"./img/wizard.xpm", so_long->w, so_long->h);
	so_long->co = mlx_xpm_file_to_image(so_long->mlx,
			"./img/coin.xpm", so_long->w, so_long->h);
	so_long->floor = mlx_xpm_file_to_image(so_long->mlx,
			"./img/background.xpm", so_long->w, so_long->h);
	so_long->enemy = mlx_xpm_file_to_image(so_long->mlx,
			"./img/knight.xpm", so_long->w, so_long->h);
}

void	line_length3(t_img *so_long)
{
	int	x;
	int	y;

	y = 0;
	while (so_long->map[y])
	{
		x = 0;
		while (so_long->map[y][x])
		{
			if (so_long->map[y][x] == '1')
				img_draw(so_long, so_long->wall, x, y);
			else if (so_long->map[y][x] == '0')
				img_draw(so_long, so_long->floor, x, y);
			else if (so_long->map[y][x] == 'P')
				img_draw(so_long, so_long->player, x, y);
			else if (so_long->map[y][x] == 'E')
				img_draw(so_long, so_long->exit, x, y);
			else if (so_long->map[y][x] == 'C')
				img_draw(so_long, so_long->co, x, y);
			else if (so_long->map[y][x] == 'D')
				img_draw(so_long, so_long->enemy, x, y);
			x++;
		}
		y++;
	}
}
