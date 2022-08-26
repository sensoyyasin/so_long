#ifndef SO_LONG
# define SO_LONG
//yasinnnnn
#include <stdio.h>
#include <unistd.h>
#include "minilibx/mlx.h"
#include "./libft/libft.h"
#include <fcntl.h>
#include "get_next_line/get_next_line.h"


typedef struct	s_data{
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
	int		g_move;
	int		g_coin;
	int		coin;
	int		*w;
	int		*h;
	int		x_kord;
	int		y_kord;
	int		index;
	char	**map;
	char	**map_input;
}		t_img;

int		close_window(t_img *so_long);
void	turnleft(t_img *so_long);
void	turnup(t_img *so_long);
void	turndown(t_img *so_long);
void	turnright(t_img *so_long);
void	coin_counter(t_img *so_long);

void	allfunc(int argc, t_img *so_long);
void	isRectangular(t_img *so_long);
void	isMapTrue(t_img *so_long);
void	isWallTrue(t_img *so_long);
void	isArgTrue(int argc, t_img *so_long);
void	isDuplicate(t_img *so_long);
void	isCollectible(t_img *so_long);


int		line_length();
int		column_length();
void	put_xpm(t_img *img);
int		push_button(int keycode, t_img *so_long);
void	player(t_img *so_long);
void	addimage(t_img *so_long);
char	**mapdonder(t_img *so_long);


#endif
