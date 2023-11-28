/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division_in_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:29:12 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/28 13:50:41 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	division_rotate_a3(t_stack *a, t_stack *b, int tri_direct, int tri_size)
{
	int	n[3];

	n[0] = a->top->num;
	n[1] = a->top->dn->num;
	n[2] = a->top->dn->dn->num;
	if ((tri_direct == 1 && min_check(n, 3) == 0)
		|| (tri_direct == 0 && max_check(n, 3) == 0))
		check_command(a, b, "ra\n");
	else if ((tri_direct == 1 && min_check(n, 3) == 1)
		|| (tri_direct == 0 && max_check(n, 3) == 1))
	{
		check_command(a, b, "sa\n");
		check_command(a, b, "ra\n");
	}
	else if ((tri_direct == 1 && min_check(n, 3) == 2)
		|| (tri_direct == 0 && max_check(n, 3) == 2))
	{
		check_command(a, b, "pb\n");
		check_command(a, b, "sa\n");
		check_command(a, b, "ra\n");
		check_command(a, b, "pa\n");
	}
	return (division_in_a(a, b, tri_direct, tri_size - 1));
}

void	division_rotate_a4_util(t_stack *a, t_stack *b, int tri_direct, int *n)
{
	if ((tri_direct == 1 && min_check(n, 4) == 2)
		|| (tri_direct == 0 && max_check(n, 4) == 2))
	{
		check_command(a, b, "pb\n");
		check_command(a, b, "sa\n");
		check_command(a, b, "ra\n");
		check_command(a, b, "pa\n");
	}
	else if ((tri_direct == 1 && min_check(n, 4) == 3)
		|| (tri_direct == 0 && max_check(n, 4) == 3))
	{
		check_command(a, b, "pb\n");
		check_command(a, b, "pb\n");
		check_command(a, b, "sa\n");
		check_command(a, b, "ra\n");
		check_command(a, b, "pa\n");
		check_command(a, b, "pa\n");
	}
}

int	division_rotate_a4(t_stack *a, t_stack *b, int tri_direct, int tri_size)
{
	int	n[4];

	n[0] = a->top->num;
	n[1] = a->top->dn->num;
	n[2] = a->top->dn->dn->num;
	n[3] = a->top->dn->dn->dn->num;
	if ((tri_direct == 1 && min_check(n, 4) == 0)
		|| (tri_direct == 0 && max_check(n, 4) == 0))
		check_command(a, b, "ra\n");
	else if ((tri_direct == 1 && min_check(n, 4) == 1)
		|| (tri_direct == 0 && max_check(n, 4) == 1))
	{
		check_command(a, b, "sa\n");
		check_command(a, b, "ra\n");
	}
	else
		division_rotate_a4_util(a, b, tri_direct, n);
	return (division_rotate_a3(a, b, tri_direct, tri_size - 1));
}

int	division_in_a(t_stack *a, t_stack *b, int tri_direct, int tri_size)
{
	if (tri_size == 1)
		return (check_command(a, b, "ra\n"));
	else if (tri_size == 2)
	{
		if ((tri_direct == 0 && a->top->num < a->top->dn->num)
			|| (tri_direct == 1 && a->top->num > a->top->dn->num))
			check_command(a, b, "sa\n");
		check_command(a, b, "ra\n");
		check_command(a, b, "ra\n");
	}
	else if (tri_size == 3)
		return (division_rotate_a3(a, b, tri_direct, tri_size));
	else if (tri_size == 4)
		return (division_rotate_a4(a, b, tri_direct, tri_size));
	return (1);
}
