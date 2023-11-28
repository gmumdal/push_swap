/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:34:45 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/28 13:49:52 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_in_a(t_stack *a, t_stack *b, t_data *data, int *index)
{
	int	i;

	i = 0;
	while (42)
	{
		if (tri_direction_check(index[0]) == 1)
			merge_a_flag1(a, b, data, index);
		if (tri_direction_check(index[0]) == 0)
			merge_a_flag0(a, b, data, index);
		i++;
		if (data->tri_s[index[0]] == 0 && data->tri_s[index[1]] == 0
			&& data->tri_s[index[2]] == 0)
			break ;
	}
	data->tri_s[index[0]] = i;
}

void	merge_in_b(t_stack *a, t_stack *b, t_data *data, int *index)
{
	int	i;

	i = 0;
	while (42)
	{
		if (tri_direction_check(index[0]) == 1)
			merge_b_flag1(a, b, data, index);
		if (tri_direction_check(index[0]) == 0)
			merge_b_flag0(a, b, data, index);
		i++;
		if (data->tri_s[index[0]] == 0 && data->tri_s[index[1]] == 0
			&& data->tri_s[index[2]] == 0)
			break ;
	}
	data->tri_s[index[0]] = i;
}

void	first_setting(t_stack *a, t_stack *b, t_data *data, int push_flag)
{
	int	pbsize;
	int	i;

	pbsize = 0;
	i = 0;
	while (i < data->tri_n / 3)
		pbsize += data->tri_s[data->tri_n - i++];
	while (pbsize-- != 0)
	{
		if (push_flag == 0)
			check_command(a, b, "pb\n");
		if (push_flag == 1)
			check_command(a, b, "pa\n");
	}
}

void	merge(t_stack *a, t_stack *b, t_data *data, int push_flag)
{
	int	index[3];
	int	i;

	if (data->tri_n == 1)
		return ;
	first_setting(a, b, data, push_flag);
	i = 0;
	while (i < data->tri_n / 3)
	{
		index[0] = 1 + i;
		index[1] = data->tri_n / 3 * 2 - i;
		index[2] = data->tri_n - i;
		if (push_flag == 0)
			merge_in_b(a, b, data, index);
		else
			merge_in_a(a, b, data, index);
		i++;
	}
	data->tri_n /= 3;
	merge(a, b, data, 1 - push_flag);
}
