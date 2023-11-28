/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:40:11 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/27 22:47:16 by hyeongsh         ###   ########.fr       */
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

int	sorting_four(t_stack *a, t_stack *b)
{
	int	min[4];

	min[0] = a->top->num;
	min[1] = a->top->dn->num;
	min[2] = a->bot->up->num;
	min[3] = a->bot->num;
	if (min[1] < min[0] && min[1] < min[2] && min[1] < min[3])
		check_command(a, b, "ra\n");
	else if (min[2] < min[0] && min[2] < min[1] && min[2] < min[3])
	{
		check_command(a, b, "ra\n");
		check_command(a, b, "ra\n");
	}
	else if (min[3] < min[0] && min[3] < min[1] && min[3] < min[2])
		check_command(a, b, "rra\n");
	check_command(a, b, "pb\n");
	sorting_three(a, b);
	check_command(a, b, "pa\n");
	return (1);
}

int	sorting_five(t_stack *a, t_stack *b)
{
	int	min[5];

	min[0] = a->top->num;
	min[1] = a->top->dn->num;
	min[2] = a->top->dn->dn->num;
	min[3] = a->bot->up->num;
	min[4] = a->bot->num;
	if ((min[1] < min[0] && min[1] < min[2] && min[1] < min[3]
			&& min[1] < min[4]) || (min[2] < min[0] && min[2] < min[1]
			&& min[2] < min[3] && min[2] < min[4]))
		check_command(a, b, "ra\n");
	else if (min[2] < min[0] && min[2] < min[1]
		&& min[2] < min[3] && min[2] < min[4])
		check_command(a, b, "ra\n");
	else if ((min[3] < min[0] && min[3] < min[1] && min[3] < min[2]
			&& min[3] < min[4]) || (min[4] < min[0] && min[4] < min[1]
			&& min[4] < min[2] && min[4] < min[3]))
		check_command(a, b, "rra\n");
	else if (min[3] < min[0] && min[3] < min[1]
		&& min[3] < min[2] && min[3] < min[4])
		check_command(a, b, "rra\n");
	check_command(a, b, "pb\n");
	sorting_four(a, b);
	check_command(a, b, "pa\n");
	return (1);
}
