#include "so_long.h"

char	**mapdonder(t_img *so_long)
{
	int		fdmap;
	char	c;
	int		i;
	int		uz_y;

	i = 0;
	uz_y = -1;
	fdmap = open("map.ber", O_RDONLY);
	so_long->map = malloc((line_length() + 1) * sizeof(char *));
	while (++uz_y < line_length())
	{
		so_long->map[uz_y] = get_next_line(fdmap);
		printf("%s",so_long->map[uz_y]);
	}
	so_long->map[uz_y] = NULL;
	close(fdmap);
	return (so_long->map);
}

int	main(int argc, char **map_input)
{
	int		a;
	t_img	*img;
	void	*mlx;
	void	*mlx_win;

	img = (t_img *)malloc(sizeof(t_img));
	a = 32;
	mlx = mlx_init();
	img->mlx = mlx;
	img->map_input = map_input;
	img->h = &a;
	img->w = &a;
	mlx_win = mlx_new_window(mlx, column_length() * 32, (line_length() * 32) + 10, "LUKA MAGIC");
	img->mlx_win = mlx_win;
	img->coin = 0;
	img->index = 0;
	mapdonder(img);
	put_xpm(img);
	allfunc(argc, img);
	coin_counter(img);
	mlx_string_put(mlx, mlx_win, 0, (line_length() * 32) + 10, 0x00000FF00, "MOVE");
	mlx_hook(img->mlx_win, 2, 1L << 0, push_button, &img->mlx);
	mlx_loop(mlx);
	free(img->map);
	free(img);
}


