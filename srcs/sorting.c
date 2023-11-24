/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:44:43 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/24 22:51:16 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tmp_print(t_stack *a, t_stack *b)
{
	t_node	*t;

	t = a->top;
	ft_printf("a : ");
	while (t != 0)
	{
		ft_printf("%d ", t->num);
		t = t->dn;
	}
	t = b->top;
	ft_printf("\nb : ");
	while (t != 0)
	{
		ft_printf("%d ", t->num);
		t = t->dn;
	}
	ft_printf("\n");
}

int	pb_rule(t_stack *a, t_stack *b, int *flag, int *tri_num)
{
	int	push_index;

	if (*flag == 0)
		push_index = check_small(a, b);
	else
		push_index = check_large(a, b);
	if (push_index == 1)
		check_command(a, b, "sa\n");
	else if (push_index == 2)
		check_command(a, b, "rra\n");
	check_command(a, b, "pb\n");
	if (*flag == 0)
		flag_change_small(a, b, flag, tri_num);
	else
		flag_change_large(a, b, flag, tri_num);
	return (1);
}

int	pa_rule(t_stack *a, t_stack *b, int *flag, int *tri_num)
{
	int	push_index;

	if (*flag == 0)
		push_index = check_small(b, a);
	else
		push_index = check_large(b, a);
	if (push_index == 1)
		check_command(a, b, "sb\n");
	else if (push_index == 2)
		check_command(a, b, "rrb\n");
	check_command(a, b, "pa\n");
	if (*flag == 0)
		flag_change_small(b, a, flag, tri_num);
	else
		flag_change_large(b, a, flag, tri_num);
	return (1);
}

void	final_sort(t_stack *a, t_stack *b, int tri_num)
{
	if (tri_num != 3)
		return ;
	while (b->size != 2)
	{
		if (b->top->dn->num > b->top->num && b->top->dn->num > b->bot->num)
			check_command(a, b, "sb\n");
		else if (b->bot->num > b->top->dn->num && b->bot->num > b->top->num)
			check_command(a, b, "rrb\n");
		if (a->size > 1 && a->top->num < b->top->num)
			check_command(a, b, "ra\n");
		else if (a->size > 1)
		{
			while (a->top->num > a->bot->num)
				check_command(a, b, "rra\n");
		}
		check_command(a, b, "pa\n");
	}
	if (b->bot->num > b->top->num)
		check_command(a, b, "sb\n");
	check_command(a, b, "pa\n");
	check_command(a, b, "pa\n");
}

int	sorting_al(t_stack *a, t_stack *b)
{
	int	flag;
	int	tri_num;

	flag = 0;
	tri_num = 0;
	while (check_ab(a, b, 1) == 0 || b->size != 0)
	{
		tri_num = 1;
		while (a->size != 0)
			pb_rule(a, b, &flag, &tri_num);
		if (tri_num == 3)
			break ;
		flag = 1 - flag;
		tri_num = 1;
		while (b->size != 0)
			pa_rule(a, b, &flag, &tri_num);
		if (tri_num == 3)
			flag = 1;
	}
	final_sort(a, b, tri_num);
	return (1);
}
