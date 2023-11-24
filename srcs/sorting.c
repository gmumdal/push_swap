/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:44:43 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/24 11:19:40 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_three(t_stack *a, t_stack *b)
{
	if (a->top->dn->num > a->bot->num && a->bot->num > a->top->num)
	{
		check_command(a, b, "sa\n");
		check_command(a, b, "ra\n");
	}
	else if (a->bot->num > a->top->num && a->top->num > a->top->dn->num)
		check_command(a, b, "sa\n");
	else if (a->top->dn->num > a->top->num && a->top->num > a->bot->num)
		check_command(a, b, "rra\n");
	else if (a->top->num > a->bot->num && a->bot->num > a->top->dn->num)
		check_command(a, b, "ra\n");
	else if (a->top->num > a->top->dn->num && a->top->dn->num > a->bot->num)
	{
		check_command(a, b, "sa\n");
		check_command(a, b, "rra\n");
	}
	return (1);
}

int	pb_rule(t_stack *a, t_stack *b)
{
	if (a->size <= 1 || check_ab(a, b, 1))
		return (1);
	else if (a->size == 2)
	{
		if (a->top->num > a->bot->num)
			check_command(a, b, "ra\n");
	}
}

int	pa_rule(t_stack *a, t_stack *b)
{
	if (b->size <= 1 || check_ab(a, b, 2))
		return (1);
	else if (b->size == 2)
	{
		if (b->top->num > b->bot->num)
			check_command(a, b, "rb\n");
	}
}

int	check_ab(t_stack *a, t_stack *b, int flag)
{
	t_node	*tmp;

	tmp = a->top;
	if (flag == 1)
	{
		while (tmp->dn != 0)
		{
			if (tmp->num > tmp->dn->num)
				return (0);
			tmp = tmp->dn;
		}
		return (1);
	}
	tmp = b->top;
	while (tmp->dn != 0)
	{
		if (tmp->num < tmp->dn->num)
			return (0);
		tmp = tmp->dn;
	}
	return (1);
}

int	sorting_al(t_stack *a, t_stack *b)
{
	while (42)
	{
		while (42)
		{
			if (pb_rule(a, b))
				break ;
		}
		while (42)
		{
			if (pa_rule(a, b))
				break ;
		}
		if (check_ab(a, b, 1) && check_ab(a, b, 2))
		{
			while (b->size != 0)
				check_command(a, b, "pa\n");
			return (1);
		}
	}
	return (0);
}
