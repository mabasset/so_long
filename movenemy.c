/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movenemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabasset <mabasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:24:34 by mabasset          #+#    #+#             */
/*   Updated: 2022/03/20 00:18:49 by mabasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move_up(t_so_long *data, int y, int x, int i)
{
	data->matrix[y][x] = '0';
	data->matrix[y - 1][x] = 'M';
	data->m_pos[i].y -= 1;
}

static void	ft_move_down(t_so_long *data, int y, int x, int i)
{
	data->matrix[y][x] = '0';
	data->matrix[y + 1][x] = 'M';
	data->m_pos[i].y += 1;
}

void	ft_movenemy(t_so_long *data)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	while (i < data->m_count)
	{
		y = data->m_pos[i].y;
		x = data->m_pos[i].x;
		if (data->matrix[y - 1][x] != '0' && data->m_pos[i].moves == 0)
			data->m_pos[i].moves = 1;
		else if (data->matrix[y + 1][x] != '0' && data->m_pos[i].moves == 1)
			data->m_pos[i].moves = 0;
		if (data->m_pos[i].moves == 0 && data->matrix[y - 1][x] == '0')
			ft_move_up(data, y, x, i);
		else if (data->m_pos[i].moves == 1 && data->matrix[y + 1][x] == '0')
			ft_move_down(data, y, x, i);
		i++;
	}
}
