/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabasset <mabasset@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:22:42 by mabasset          #+#    #+#             */
/*   Updated: 2022/03/22 22:22:42 by mabasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_multi_init(char **matrix, int size)
{
	int	*ar;
	int	i;

	ar = (int *) malloc (sizeof(int) * size);
	ft_checkmalloc(ar);
	i = 0;
	while (i < size)
	{
		ft_check_max(matrix[i]);
		ar[i] = ft_atoi(matrix[i]);
		i++;
	}
	return (ar);
}

int	*ft_mono_init(char *args, int *size)
{
	char	**temp;
	int		*ar;
	int		i;

	temp = ft_split(args, ' ');
	i = 0;
	while (temp[i] != NULL)
		i++;
	if (ft_multi_check(temp, i) == 0)
		ft_error();
	ar = (int *) malloc (sizeof(int) * i);
	ft_checkmalloc(ar);
	*size = i;
	i = 0;
	while (temp[i] != NULL)
	{
		ft_check_max(temp[i]);
		ar[i] = ft_atoi(temp[i]);
		free(temp[i]);
		i++;
	}
	free(temp);
	return (ar);
}
