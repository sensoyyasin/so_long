#include "so_long.h"

void	coin_counter(t_img *so_long)
{
	int i;
	int j;

	so_long->g_coin = 0;
	i = 0;
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
