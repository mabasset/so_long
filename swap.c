/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabasset <mabasset@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:20:53 by mabasset          #+#    #+#             */
/*   Updated: 2022/03/24 19:02:40 by mabasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int	*a, int *b, int size)
{
	int	temp;

	if (size <= 1)
		ft_error();
	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_swap_a(int *ar, int size)
{
	write(1, "sa\n", 3);
	ft_swap(ar, ar + 1, size);
}

void	ft_swap_b(int *ar, int size)
{
	write(1, "sb\n", 3);
	ft_swap(ar, ar + 1, size);
}

void	ft_swap_s(int *ar_a, int *ar_b, int size)
{
	write(1, "ss\n", 3);
	ft_swap(ar_a, ar_a + 1, size);
	ft_swap(ar_b, ar_b + 1, size);
}
