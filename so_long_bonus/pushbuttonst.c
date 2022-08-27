/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushbuttonst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:14:37 by ysensoy           #+#    #+#             */
/*   Updated: 2022/08/27 12:15:03 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ex_controller(t_img *so_long)
{
	if (so_long->coin == so_long->g_coin)
	{
		write(1, "\033[32mSUCCESS\n", 14);
		exit(0);
	}
	else
		write(1, "Please collect all coins\n", 25);
}
