#include "so_long.h"

void	img_draw(t_img *so_long, void *image, int x, int y)
{
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, image, x * 32, y * 32);
}

void	addimage(t_img *so_long)
{
	so_long->wall = mlx_xpm_file_to_image(so_long->mlx, "/Users/ysensoy/Desktop/so_long/img/torch.xpm", so_long->w, so_long->h);
	so_long->exit = mlx_xpm_file_to_image(so_long->mlx, "/Users/ysensoy/Desktop/so_long/img/door.xpm", so_long->w, so_long->h);
	so_long->player = mlx_xpm_file_to_image(so_long->mlx, "/Users/ysensoy/Desktop/so_long/img/wizard.xpm", so_long->w, so_long->h);
	so_long->co = mlx_xpm_file_to_image(so_long->mlx, "/Users/ysensoy/Desktop/so_long/img/coin.xpm", so_long->w, so_long->h);
	so_long->floor = mlx_xpm_file_to_image(so_long->mlx, "/Users/ysensoy/Desktop/so_long/img/background.xpm", so_long->w, so_long->h);
}

int	column_length(void)
{
	int		fdmap;
	char	*line;
	int		i;

	fdmap = open("map.ber", O_RDONLY);
	line = get_next_line(fdmap);
	close(fdmap);
	i = ft_strlen(line) - 1;
	free(line);
	return (i);
}

int	line_length(void)
{
	int		fdmap;
	char	c;
	int		i;

	i = 0;
	fdmap = open("map.ber", O_RDONLY);
	while (read(fdmap, &c, 1) >= 1)
	{
		if (ft_strchr(&c, '\n'))
			i++;
	}
	close(fdmap);
	return (i);
}

void	put_xpm(t_img *so_long)
{
	int x;
	int y;

	addimage(so_long);
	y = 0;
	while (so_long->map[y])
	{
		x = 0;
		while (so_long->map[y][x])
		{
			if (so_long->map[y][x]== '1')
				img_draw(so_long, so_long->wall, x, y);
			else if (so_long->map[y][x]== '0')
			 	img_draw(so_long, so_long->floor, x, y);
			else if (so_long->map[y][x]== 'P')
				img_draw(so_long, so_long->player, x, y);
			else if (so_long->map[y][x]== 'E')
				img_draw(so_long, so_long->exit, x, y);
			else if (so_long->map[y][x]== 'C')
				img_draw(so_long, so_long->co, x, y);
			x++;
		}
		y++;
	}
}


