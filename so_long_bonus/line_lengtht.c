/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_lengtht.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:16:46 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/27 12:17:09 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	addanimation(t_img *so_long, int index)
{
	if (index % 5 == 1)
		so_long->co = mlx_xpm_file_to_image(so_long->mlx,
				"./img/yasin_2.xpm", so_long->w, so_long->h);
	if (index % 5 == 2)
		so_long->co = mlx_xpm_file_to_image(so_long->mlx,
				"./img/yasin_3.xpm", so_long->w, so_long->h);
	if (index % 5 == 3)
		so_long->co = mlx_xpm_file_to_image(so_long->mlx,
				"./img/yasin_4.xpm", so_long->w, so_long->h);
	if (index % 5 == 4)
		so_long->co = mlx_xpm_file_to_image(so_long->mlx,
				"./img/yasin_5.xpm", so_long->w, so_long->h);
	if (index % 5 == 0)
		so_long->co = mlx_xpm_file_to_image(so_long->mlx,
				"./img/yasin_1.xpm", so_long->w, so_long->h);
	return (0);
}

int	addanimation2(t_img *so_long, int index)
{
	if (index % 3 == 1)
		so_long->wall = mlx_xpm_file_to_image(so_long->mlx,
				"./img/wall_2.xpm", so_long->w, so_long->h);
	if (index % 3 == 2)
		so_long->wall = mlx_xpm_file_to_image(so_long->mlx,
				"./img/wall_3.xpm", so_long->w, so_long->h);
	if (index % 3 == 0)
		so_long->wall = mlx_xpm_file_to_image(so_long->mlx,
				"./img/wall_1.xpm", so_long->w, so_long->h);
	return (0);
}

int	addanimation3(t_img *so_long, int index)
{
	if (index % 6 == 3)
		so_long->player = mlx_xpm_file_to_image(so_long->mlx,
				"./img/player_left2.xpm", so_long->w, so_long->h);
	if (index % 6 == 0)
		so_long->player = mlx_xpm_file_to_image(so_long->mlx,
				"./img/player_left1.xpm", so_long->w, so_long->h);
	return (0);
}
