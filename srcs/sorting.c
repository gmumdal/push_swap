/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:44:43 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/28 11:29:27 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_al(t_stack *a, t_stack *b, t_data *data)
{
	int	push_flag;

	if (a->size == 3)
		return (sorting_three(a, b));
	if (a->size == 4)
		return (sorting_four(a, b));
	if (a->size == 5)
		return (sorting_five(a, b));
	data->tri_n = tri_num_check(a->size, &push_flag);
	data->tri_s = malloc(sizeof(int) * (data->tri_n + 1));
	if (data->tri_s == 0)
		error_print();
	division(a, b, data, push_flag);
	merge(a, b, data, push_flag);
	return (1);
}
