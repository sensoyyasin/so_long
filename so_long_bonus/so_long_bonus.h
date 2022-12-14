/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:33:31 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/27 17:18:33 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include "minilibx/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

typedef struct s_data{
	void	*img;
	int		*width;
	int		*height;
	int		line_length;
}				t_data;

typedef struct s_img{
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*co;
	void	*exit;
	void	*player;
	void	*floor;
	void	*enemy;
	void	*gameover;
	int		g_move;
	int		g_coin;
	int		coin;
	int		*w;
	int		*h;
	int		x_kord;
	int		y_kord;
	int		index;
	int		d_lx;
	int		d_ly;
	char	**map;
	char	**map_input;
	int		lenx;
	int		leny;
}		t_img;

void	turnleft(t_img *so_long);
void	turnup(t_img *so_long);
void	turndown(t_img *so_long);
void	turnright(t_img *so_long);
void	coin_counter(t_img *so_long);

void	allfunc(t_img *so_long);
void	isrectangular(t_img *so_long);
void	ismaptrue(t_img *so_long);
void	iswalltrue(t_img *so_long);
void	isargtrue(t_img *so_long);
void	isduplicate(t_img *so_long, int i, int j);
void	iscollectible(t_img *so_long);
void	enemy_position(t_img *so_long);
void	move_enemy(t_img *so_long, int index);
void	enemy_location(t_img *so_long);
void	put_xpm(t_img *img);
void	player(t_img *so_long);
void	addimage(t_img *so_long);
void	definevar(t_img *so_long);
void	topcoin(t_img *so_long);
void	leftcoin(t_img *so_long);
void	downcoin(t_img *so_long);
void	rightcoin(t_img *so_long);
void	ex_controller(t_img *so_long);
void	string_put(t_img *so_long);

int		addanimation(t_img *so_long, int index);
int		addanimation2(t_img *so_long, int index);
int		addanimation3(t_img *so_long, int index);
int		line_length(t_img *so_long);
void	line_lengtht(t_img *so_long);
void	line_length3(t_img *so_long);
int		column_length(t_img *so_long);
int		close_window(t_img *so_long);
int		game_over(t_img *so_long);
int		push_button(int keycode, t_img *so_long);
void	mapdonder(t_img *so_long);

#endif
