/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabasset <mabasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:51:17 by mabasset          #+#    #+#             */
/*   Updated: 2022/03/17 11:56:34 by mabasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_openimg(t_so_long *data)
{
	int	w;
	int	h;

	data->img.player1 = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER1, &w, &h);
	data->img.player2 = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER2, &w, &h);
	data->img.exit1 = mlx_xpm_file_to_image(data->mlx_ptr, EXIT1, &w, &h);
	data->img.exit2 = mlx_xpm_file_to_image(data->mlx_ptr, EXIT2, &w, &h);
	data->img.dog1 = mlx_xpm_file_to_image(data->mlx_ptr, DOG1, &w, &h);
	data->img.dog2 = mlx_xpm_file_to_image(data->mlx_ptr, DOG2, &w, &h);
	data->img.grass1 = mlx_xpm_file_to_image(data->mlx_ptr, GRASS1, &w, &h);
	data->img.grass2 = mlx_xpm_file_to_image(data->mlx_ptr, GRASS2, &w, &h);
}

void	ft_putimg(char type, int row, int col, t_so_long *data)
{
	void	*mlx;
	void	*win;

	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_put_image_to_window(mlx, win, data->grass, col, row);
	if (type == '1')
		mlx_put_image_to_window(mlx, win, data->wall, col, row);
	if (type == 'C')
		mlx_put_image_to_window(mlx, win, data->collec, col, row);
	if (type == 'E')
		mlx_put_image_to_window(mlx, win, data->exit, col, row);
	if (type == 'P')
		mlx_put_image_to_window(mlx, win, data->player, col, row);
	if (type == 'M')
		mlx_put_image_to_window(mlx, win, data->enemy, col, row);
}

void	ft_draw(t_so_long	*data)
{
	int		row;
	int		col;
	void	*mlx;
	void	*win;
	char	*str;

	row = 0;
	while (row < data->height)
	{
		col = 0;
		while (col < data->width)
		{
			ft_putimg(data->matrix[row][col], row * 64, col * 64, data);
			col++;
		}
		row++;
	}
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	str = "MOVES";
	mlx_string_put(mlx, win, data->width, data->height, BLUE, str);
	str = ft_itoa(data->moves);
	mlx_string_put(mlx, win, data->width + 70, data->height, BLUE, str);
	free(str);
}

int	ft_updates(t_so_long *data)
{
	data->frames++;
	if (data->frames % 20 < 10)
		data->enemy = data->img.dog1;
	else
		data->enemy = data->img.dog2;
	if (data->frames < 50 || data->frames > 150)
	{
		data->exit = data->img.exit1;
		data->player = data->img.player1;
	}
	else
	{
		data->exit = data->img.exit2;
		data->player = data->img.player2;
	}
	if (data->frames < 120)
		data->grass = data->img.grass1;
	else
		data->grass = data->img.grass2;
	if (data->frames == 200)
		data->frames = 0;
	ft_draw(data);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_so_long	data;
	int			w;
	int			h;

	if (argc == 2)
	{
		read_file(argv[1], &data);
		if (ft_checkmap(&data) == 0)
			ft_error("Map");
		data.mlx_ptr = mlx_init();
		w = data.width * 64;
		h = data.height * 64;
		data.win_ptr = mlx_new_window(data.mlx_ptr, w, h, "so_long");
		data.frames = 0;
		ft_openimg(&data);
		ft_enemyinit(&data);
		data.wall = mlx_xpm_file_to_image(data.mlx_ptr, WALL, &w, &h);
		data.collec = mlx_xpm_file_to_image(data.mlx_ptr, APPLE, &w, &h);
		data.moves = 0;
		mlx_key_hook(data.win_ptr, ft_hooks, &data);
		mlx_loop_hook(data.mlx_ptr, ft_updates, &data);
		mlx_hook(data.win_ptr, 17, 0, ft_error, 0);
		mlx_loop(data.mlx_ptr);
	}
}
