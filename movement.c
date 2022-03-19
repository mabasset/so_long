/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabasset <mabasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:50:49 by mabasset          #+#    #+#             */
/*   Updated: 2022/03/16 21:00:45 by mabasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move_up(t_so_long *data)
{
	int		x;
	int		y;
	char	**matrix;

	x = data->p_pos.x;
	y = data->p_pos.y;
	matrix = data->matrix;
	if (matrix[y - 1][x] != '1' && (matrix[y - 1][x] != 'E' || data->c == 0))
	{
		ft_movenemy(data);
		if (matrix[y - 1][x] == 'C')
			data->c--;
		else if (matrix[y - 1][x] == 'E' || (matrix[y - 1][x] == 'M'))
			ft_destroy(data);
		matrix[y - 1][x] = 'P';
		matrix[y][x] = '0';
		data->moves++;
		ft_printf("%d\n", data->moves);
	}
}

static void	ft_move_down(t_so_long *data)
{
	int		x;
	int		y;
	char	**matrix;

	x = data->p_pos.x;
	y = data->p_pos.y;
	matrix = data->matrix;
	if (matrix[y + 1][x] != '1' && (matrix[y + 1][x] != 'E' || data->c == 0))
	{
		ft_movenemy(data);
		if (matrix[y + 1][x] == 'C')
			data->c--;
		else if (matrix[y + 1][x] == 'E' || (matrix[y + 1][x] == 'M'))
			ft_destroy(data);
		matrix[y + 1][x] = 'P';
		matrix[y][x] = '0';
		data->moves++;
		ft_printf("%d\n", data->moves);
	}
}

static void	ft_move_left(t_so_long *data)
{
	int		x;
	int		y;
	char	**matrix;

	x = data->p_pos.x;
	y = data->p_pos.y;
	matrix = data->matrix;
	if (matrix[y][x - 1] != '1' && (matrix[y][x - 1] != 'E' || data->c == 0))
	{
		ft_movenemy(data);
		if (matrix[y][x - 1] == 'C')
			data->c--;
		else if (matrix[y][x - 1] == 'E' || (matrix[y][x - 1] == 'M'))
			ft_destroy(data);
		matrix[y][x - 1] = 'P';
		matrix[y][x] = '0';
		data->moves++;
		ft_printf("%d\n", data->moves);
	}
}

static void	ft_move_right(t_so_long *data)
{
	int		x;
	int		y;
	char	**matrix;

	x = data->p_pos.x;
	y = data->p_pos.y;
	matrix = data->matrix;
	if (matrix[y][x + 1] != '1' && (matrix[y][x + 1] != 'E' || data->c == 0))
	{
		ft_movenemy(data);
		if (matrix[y][x + 1] == 'C')
			data->c--;
		if (matrix[y][x + 1] == 'E' || (matrix[y][x + 1] == 'M'))
			ft_destroy(data);
		matrix[y][x + 1] = 'P';
		matrix[y][x] = '0';
		data->moves++;
		ft_printf("%d\n", data->moves);
	}
}

int	ft_hooks(int keycode, t_so_long *data)
{
	ft_findplayer(data);
	if (keycode == 53)
		ft_destroy(data);
	if (keycode == 13)
		ft_move_up(data);
	else if (keycode == 1)
		ft_move_down(data);
	else if (keycode == 0)
		ft_move_left(data);
	else if (keycode == 2)
		ft_move_right(data);
	return (0);
}
