/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabasset <mabasset@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:21:00 by mabasset          #+#    #+#             */
/*   Updated: 2022/03/24 19:52:34 by mabasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(int *ar, int size)
{
	int	temp;
	int	i;

	if (size <= 1)
		ft_error();
	size -= 1;
	i = 0;
	temp = ar[0];
	while (i < size)
	{
		ar[i] = ar[i + 1];
		i++;
	}
	ar[size] = temp;
}

void	ft_rotate_a(t_struct *data)
{
	write(1, "ra\n", 3);
	ft_rotate(data->ar_a, data->size_a);
}

void	ft_rotate_b(t_struct *data)
{
	write(1, "rb\n", 3);
	ft_rotate(data->ar_b, data->size_b);
}

void	ft_rotate_r(t_struct *data)
{
	write(1, "rr\n", 3);
	ft_rotate(data->ar_a, data->size_a);
	ft_rotate(data->ar_b, data->size_b);
}
