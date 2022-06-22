/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabasset <mabasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:37:42 by mabasset          #+#    #+#             */
/*   Updated: 2022/03/17 12:02:11 by mabasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *str)
{
	if (str != NULL)
		ft_printf("%s Error\n", str);
	exit(1);
	return (1);
}

void	ft_destroy(t_so_long *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_freematrix(data->matrix, data->height);
	exit(0);
}

void	ft_findplayer(t_so_long *data)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->height)
	{
		col = 0;
		while (col < data->width)
		{
			if (data->matrix[row][col] == 'P')
			{
				data->p_pos.x = col;
				data->p_pos.y = row;
			}
			col++;
		}
		row++;
	}
}

int	ft_open(char *file_name, int mode)
{
	int	fd;

	fd = open(file_name, mode);
	if (fd < 0)
		ft_error("Open");
	return (fd);
}

void	ft_freematrix(char **matrix, int size)
{
	int	row;

	row = 0;
	while (row < size)
	{
		free(matrix[row]);
		row++;
	}
	free(matrix);
}
