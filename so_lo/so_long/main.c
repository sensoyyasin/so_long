/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:45:54 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/27 14:18:17 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapdonder(t_img *so_long)
{
	int		fdmap;
	char	c;
	int		i;
	int		uz_y;

	i = 0;
	uz_y = -1;
	fdmap = open(so_long->map_input[1], O_RDONLY);
	so_long->y_kord = 0;
	so_long->map = malloc((line_length(so_long) + 1) * sizeof(char *));
	while (++uz_y < line_length(so_long))
	{
		so_long->map[uz_y] = get_next_line(fdmap);
		printf("%s", so_long->map[uz_y]);
	}
	so_long->map[uz_y] = NULL;
	close(fdmap);
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
	isargtrue(img);
	mlx_win = mlx_new_window(mlx,
			column_length(img) * 32,
			(line_length(img) * 32) + 10, "LUKA MAGIC");
	img->mlx_win = mlx_win;
	mapdonder(img);
	put_xpm(img);
	allfunc(argc, img);
	coin_counter(img);
	mlx_hook(img->mlx_win, 2, 1L << 0, push_button, &img->mlx);
	mlx_hook(img->mlx_win, 17, (0L), push_button, img);
	mlx_loop(mlx);
	free(img->map);
	free(img);
}
