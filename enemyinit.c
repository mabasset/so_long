/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemyinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabasset <mabasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:33:07 by mabasset          #+#    #+#             */
/*   Updated: 2022/03/17 11:34:16 by mabasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_mcount(t_so_long *data)
{
	int	row;
	int	col;
	int	m_count;

	m_count = 0;
	row = 0;
	while (row < data->height)
	{
		col = 0;
		while (col < data->width)
		{
			if (data->matrix[row][col] == 'M')
				m_count++;
			col++;
		}
		row++;
	}
	data->m_count = m_count;
}

static void	ft_savempos(t_so_long *data)
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = 0;
	while (row < data->height)
	{
		col = 0;
		while (col < data->width)
		{
			if (data->matrix[row][col] == 'M')
			{
				data->m_pos[i].y = row;
				data->m_pos[i].x = col;
				data->m_pos[i].moves = 0;
				i++;
			}
			col++;
		}
		row++;
	}
}

void	ft_enemyinit(t_so_long *data)
{
	ft_mcount(data);
	data->m_pos = (t_vec *) malloc (sizeof(t_vec) * data->m_count);
	if (data->m_pos == NULL)
		ft_error("Malloc");
	ft_savempos(data);
}
