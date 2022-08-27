/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:40:38 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/27 17:18:40 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mapdonder(t_img *so_long)
{
	int		fdmap;
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
	string_put(so_long);
	return (0);
}

char	*ft_strjoin3(char const *s1, const char *s2)
{
	char	*str;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, len + 1);
	return (str);
}

void	string_put(t_img *so_long)
{
	char	*str;
	char	*s;

	str = ft_itoa(so_long->g_move);
	s = ft_strjoin3("Move : ", str);
	mlx_string_put(so_long->mlx, so_long->mlx_win, 10,
		(10), 0x00ff00, s);
	free(str);
	free(s);
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
	isargtrue(img);
	definevar(img);
	mlx_win = mlx_new_window(mlx, column_length(img) * 32,
			(line_length(img) * 32), "LUKA MAGIC");
	img->mlx_win = mlx_win;
	mapdonder(img);
	put_xpm(img);
	mlx_hook(img->mlx_win, 2, 1L << 0, push_button, img);
	mlx_loop_hook(mlx, hookfunc, img);
	move_enemy(img, img->index);
	allfunc(img);
	coin_counter(img);
	mlx_loop(mlx);
	free(img->map);
	free(img);
}
