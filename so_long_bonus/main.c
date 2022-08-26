/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:40:38 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/26 19:18:35 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mapdonder(t_img *so_long)
{
	int		fdmap;
	char	c;
	int		i;
	int		uz_y;

	i = 0;
	uz_y = -1;
	fdmap = open(so_long->map_input[1], O_RDONLY);
	so_long->map = malloc((line_length(so_long) + 1) * sizeof(char *));
	while (++uz_y < line_length(so_long))
	{
		so_long->map[uz_y] = get_next_line(fdmap);
		printf("%s", so_long->map[uz_y]);
	}
	so_long->map[uz_y] = NULL;
	close(fdmap);
}

int	hookfunc(t_img *so_long)
{
	int	i;

	i = 0;
	so_long->index++;
	while (i < 50000000)
		i++;
	move_enemy(so_long, so_long->index);
	mlx_clear_window(so_long->mlx, so_long->mlx_win);
	put_xpm(so_long);
	return (0);
}

int	main(int argc, char **map_input)
{
	t_img	*img;
	void	*mlx;
	void	*mlx_win;

	if (argc != 2)
		return (write(1, "Number of arguman is false\n", 27));
	img = (t_img *)malloc(sizeof(t_img));
	mlx = mlx_init();
	img->mlx = mlx;
	img->map_input = map_input;
	definevar(img);
	mlx_win = mlx_new_window(mlx, column_length(img) * 32,
			(line_length(img) * 32) + 10, "LUKA MAGIC");
	img->mlx_win = mlx_win;
	mapdonder(img);
	mlx_string_put(mlx, mlx_win, 0, (line_length(img) * 32) + 10, 0x00000FF00, "MOVE");
	put_xpm(img);
	mlx_hook(img->mlx_win, 17, (0L), push_button, img);
	mlx_hook(img->mlx_win, 2, 1L << 0, push_button, img);
	mlx_loop_hook(mlx, hookfunc, img);
	move_enemy(img, img->index);
	allfunc(argc, img);
	coin_counter(img);
	mlx_loop(mlx);
	free(img->map);

	free(img);
}
