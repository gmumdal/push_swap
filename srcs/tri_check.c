/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:12:55 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/28 13:12:16 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_check(int *n, int size)
{
	int	i;
	int	max_index;
	int	max;

	max = -2147483648;
	i = 0;
	while (i < size)
	{
		if (max < n[i])
		{
			max = n[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int	min_check(int *n, int size)
{
	int	i;
	int	min_index;
	int	min;

	min = 2147483647;
	i = 0;
	while (i < size)
	{
		if (min > n[i])
		{
			min = n[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	tri_num_check(int size, int *push_flag)
{
	int	tri_num;

	tri_num = 1;
	*push_flag = 0;
	while (4 * tri_num < size)
	{
		tri_num *= 3;
		*push_flag = 1 - *push_flag;
	}
	return (tri_num);
}

int	tri_direction_check(int tri_index)
{
	int	size;
	int	i;

	if (tri_index == 1)
		return (1);
	else if (tri_index == 0 || tri_index == 2 || tri_index == 3)
		return (0);
	size = 1;
	while (size < tri_index)
		size *= 3;
	i = size + 1 - tri_index;
	return (1 - tri_direction_check(i % (size / 3)));
}

int	tri_size_check(int size, int tri_index, int tri_num, int push_flag)
{
	int	leave_tri;
	int	tri_size;

	leave_tri = tri_num - tri_index + 1;
	if (push_flag == 1)
		tri_size = size / leave_tri + (size % leave_tri > 0);
	else
		tri_size = size / leave_tri;
	return (tri_size);
}
