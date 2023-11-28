/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:07:29 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/28 13:32:49 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	division_push_b3(t_stack *a, t_stack *b, int tri_direct, int tri_size)
{
	int	n[3];

	n[0] = a->top->num;
	n[1] = a->top->dn->num;
	n[2] = a->bot->num;
	if ((tri_direct == 1 && max_check(n, 3) == 0)
		|| (tri_direct == 0 && min_check(n, 3) == 0))
	{
		check_command(a, b, "pb\n");
		check_command(a, b, "rra\n");
	}
	else if ((tri_direct == 1 && max_check(n, 3) == 1)
		|| (tri_direct == 0 && min_check(n, 3) == 1))
	{
		check_command(a, b, "sa\n");
		check_command(a, b, "pb\n");
		check_command(a, b, "rra\n");
	}
	else if ((tri_direct == 1 && max_check(n, 3) == 2)
		|| (tri_direct == 0 && min_check(n, 3) == 2))
	{
		check_command(a, b, "rra\n");
		check_command(a, b, "pb\n");
	}
	return (division_in_b(a, b, tri_direct, tri_size - 1));
}

void	division_push_b4_util(t_stack *a, t_stack *b, int tri_direct, int *n)
{
	if ((tri_direct == 1 && max_check(n, 4) == 2)
		|| (tri_direct == 0 && min_check(n, 4) == 2))
	{
		check_command(a, b, "ra\n");
		check_command(a, b, "sa\n");
		check_command(a, b, "pb\n");
		check_command(a, b, "rra\n");
	}
	else if ((tri_direct == 1 && max_check(n, 4) == 3)
		|| (tri_direct == 0 && min_check(n, 4) == 3))
	{
		check_command(a, b, "rra\n");
		check_command(a, b, "pb\n");
		check_command(a, b, "ra\n");
	}
}

int	division_push_b4(t_stack *a, t_stack *b, int tri_direct, int tri_size)
{
	int	n[4];

	n[0] = a->top->num;
	n[1] = a->top->dn->num;
	n[2] = a->top->dn->dn->num;
	n[3] = a->bot->num;
	if ((tri_direct == 1 && max_check(n, 4) == 0)
		|| (tri_direct == 0 && min_check(n, 4) == 0))
		check_command(a, b, "pb\n");
	else if ((tri_direct == 1 && max_check(n, 4) == 1)
		|| (tri_direct == 0 && min_check(n, 4) == 1))
	{
		check_command(a, b, "sa\n");
		check_command(a, b, "pb\n");
	}
	else
		division_push_b4_util(a, b, tri_direct, n);
	return (division_push_b3(a, b, tri_direct, tri_size - 1));
}

int	division_in_b(t_stack *a, t_stack *b, int tri_direct, int tri_size)
{
	if (tri_size == 1)
		return (check_command(a, b, "pb\n"));
	else if (tri_size == 2)
	{
		if ((tri_direct == 0 && a->top->num > a->top->dn->num)
			|| (tri_direct == 1 && a->top->num < a->top->dn->num))
			check_command(a, b, "sa\n");
		check_command(a, b, "pb\n");
		check_command(a, b, "pb\n");
	}
	else if (tri_size == 3)
		return (division_push_b3(a, b, tri_direct, tri_size));
	else if (tri_size == 4)
		return (division_push_b4(a, b, tri_direct, tri_size));
	return (1);
}

void	division(t_stack *a, t_stack *b, t_data *data, int push_flag)
{
	int	tri_i;
	int	tri_di;
	int	a_size;

	tri_i = 1;
	a_size = a->size;
	while (tri_i <= data->tri_n)
	{
		if (push_flag == 0)
		{
			tri_di = tri_direction_check(data->tri_n - tri_i + 1);
			data->tri_s[data->tri_n - tri_i + 1]
				= tri_size_check(a_size, tri_i, data->tri_n, push_flag);
			division_in_a(a, b, tri_di, data->tri_s[data->tri_n - tri_i + 1]);
			a_size = a_size - data->tri_s[data->tri_n - tri_i + 1];
		}
		else if (push_flag == 1)
		{
			tri_di = tri_direction_check(tri_i);
			data->tri_s[tri_i]
				= tri_size_check(a->size, tri_i, data->tri_n, push_flag);
			division_in_b(a, b, tri_di, data->tri_s[tri_i]);
		}
		tri_i++;
	}
}
