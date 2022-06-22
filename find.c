/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabasset <mabasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:47:40 by mabasset          #+#    #+#             */
/*   Updated: 2022/04/20 10:00:06 by mabasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_min(int *array, int size)
{
	int	min;
	int	i;

	min = array[0];
	i = 1;
	while (i < size)
	{
		if (array[i] < min)
			min = array[i];
		i++;
	}
	return (min);
}

int	ft_findind(int nb, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == nb)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_findindmin(int *array, int size)
{
	return (ft_findind(ft_min(array, size), array, size));
}
