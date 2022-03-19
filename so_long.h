/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabasset <mabasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:16:29 by mabasset          #+#    #+#             */
/*   Updated: 2022/03/17 12:01:10 by mabasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define APPLE "sprites/apple.xpm"
# define WALL "sprites/tree.xpm"
# define PLAYER1 "sprites/char_idle_1.xpm"
# define PLAYER2 "sprites/char_idle_2.xpm"
# define DOG1 "sprites/dog_idle_1.xpm"
# define DOG2 "sprites/dog_idle_2.xpm"
# define EXIT1 "sprites/granny_idle_1.xpm"
# define EXIT2 "sprites/granny_idle_2.xpm"
# define GRASS1 "sprites/grass_idle_1.xpm"
# define GRASS2 "sprites/grass_idle_2.xpm"
# define RED 16711680
# define GREEN 65280
# define BLUE 255
# define BLACK 0
# define WHITE 16777215

typedef struct s_img
{
	void	*player1;
	void	*player2;
	void	*exit1;
	void	*exit2;
	void	*dog1;
	void	*dog2;
	void	*grass1;
	void	*grass2;
}				t_img;

typedef struct s_vec
{
	int		x;
	int		y;
	int		moves;
}				t_vec;

typedef struct s_t_so_long
{
	char	**matrix;
	int		height;
	int		width;
	int		frames;
	int		moves;
	int		p;
	int		e;
	int		c;
	void	*wall;
	void	*collec;
	void	*grass;
	void	*exit;
	void	*player;
	void	*enemy;
	void	*mlx_ptr;
	void	*win_ptr;
	int		m_count;
	t_img	img;
	t_vec	p_pos;
	t_vec	*m_pos;
}				t_so_long;

void	read_file(char *file_name, t_so_long *data);
void	ft_freematrix(char **matrix, int size);
int		ft_error(char *str);
int		ft_open(char *file_name, int mode);
int		ft_checkmap(t_so_long *data);
void	ft_draw(t_so_long	*data);
int		ft_hooks(int keycode, t_so_long *data);
void	ft_findplayer(t_so_long *data);
void	ft_destroy(t_so_long *data);
void	ft_movenemy(t_so_long *data);
void	ft_enemyinit(t_so_long *data);

#endif
