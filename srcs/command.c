/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:03:11 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/24 16:57:12 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	a;
	int	b;

	if (stack->top == NULL || stack->top->dn == NULL)
		return ;
	a = rm_top(stack);
	b = rm_top(stack);
	add_top(stack, a);
	add_top(stack, b);
}

void	push(t_stack *dst, t_stack *src)
{
	if (src->top == NULL)
		return ;
	add_top(dst, rm_top(src));
}

void	rotate(t_stack *stack, int reverse)
{
	if (stack->top == NULL)
		return ;
	if (reverse == 0)
		add_bot(stack, rm_top(stack));
	else
		add_top(stack, rm_bot(stack));
}
