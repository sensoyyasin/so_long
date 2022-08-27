/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:40:48 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/27 17:14:10 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	column_length(t_img *so_long)
{
	int		fdmap;
	char	*line;
	int		i;

	fdmap = open(so_long->map_input[1], O_RDONLY);
	line = get_next_line(fdmap);
	close(fdmap);
	i = ft_strlen(line) - 1;
	free(line);
	return (i);
}

int	line_length(t_img *so_long)
{
	int		fdmap;
	char	c;
	int		i;

	i = 0;
	fdmap = open(so_long->map_input[1], O_RDONLY);
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
	addimage(so_long);
	addanimation(so_long, so_long->index);
	addanimation2(so_long, so_long->index);
	addanimation3(so_long, so_long->index);
	line_length3(so_long);
}
