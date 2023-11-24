/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:40:11 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/24 21:34:38 by hyeongsh         ###   ########.fr       */
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

void	flag_change_large(t_stack *push, t_stack *dst, int *flag, int *tri_num)
{
	if (push->size >= 3 && dst->top->num < push->top->num
		&& dst->top->num < push->top->dn->num && dst->top->num < push->bot->num)
		*flag = 0;
	else if (push->size == 2 && dst->top->num < push->top->num
		&& dst->top->num < push->bot->num)
		*flag = 0;
	else if (push->size == 1 && dst->top->num < push->top->num)
		*flag = 0;
	else
		return ;
	(*tri_num)++;
}

int	check_large(t_stack *push, t_stack *dst)
{
	int	std;
	int	num[3];

	std = 2147483647;
	num[0] = -2147483648;
	num[1] = -2147483648;
	num[2] = -2147483648;
	if (dst->size != 0)
		std = dst->top->num;
	if (push->top->num < std)
		num[0] = push->top->num;
	if (push->size > 1 && push->top->dn->num < std)
		num[1] = push->top->dn->num;
	if (push->size > 2 && push->bot->num < std)
		num[2] = push->bot->num;
	if (num[0] > num[1] && num[0] > num[2])
		return (0);
	else if (num[1] > num[0] && num[1] > num[2])
		return (1);
	else if (num[2] > num[0] && num[2] > num[1])
		return (2);
	else
		return (3);
}

void	flag_change_small(t_stack *push, t_stack *dst, int *flag, int *tri_num)
{
	if (push->size >= 3 && dst->top->num > push->top->num
		&& dst->top->num > push->top->dn->num && dst->top->num > push->bot->num)
		*flag = 1;
	else if (push->size == 2 && dst->top->num > push->top->num
		&& dst->top->num > push->bot->num)
		*flag = 1;
	else if (push->size == 1 && dst->top->num > push->top->num)
		*flag = 1;
	else
		return ;
	(*tri_num)++;
}

int	check_small(t_stack *push, t_stack *dst)
{
	int	std;
	int	num[3];

	std = -2147483648;
	num[0] = 2147483647;
	num[1] = 2147483647;
	num[2] = 2147483647;
	if (dst->size != 0)
		std = dst->top->num;
	if (push->top->num > std)
		num[0] = push->top->num;
	if (push->size > 1 && push->top->dn->num > std)
		num[1] = push->top->dn->num;
	if (push->size > 2 && push->bot->num > std)
		num[2] = push->bot->num;
	if (num[0] < num[1] && num[0] < num[2])
		return (0);
	else if (num[1] < num[0] && num[1] < num[2])
		return (1);
	else if (num[2] < num[0] && num[2] < num[1])
		return (2);
	else
		return (3);
}
