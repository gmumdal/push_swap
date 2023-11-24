/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:19:01 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/23 13:21:17 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	stack_init(t_stack **stack)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (*stack == 0)
		error_print();
	(*stack)->top = NULL;
	(*stack)->bot = NULL;
	(*stack)->size = 0;
}

void	add_top(t_stack *stack, int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == 0)
		error_print();
	new->num = num;
	new->dn = stack->top;
	if (stack->top == 0)
		stack->bot = new;
	else
		stack->top->up = new;
	new->up = NULL;
	stack->top = new;
	stack->size++;
}

void	add_bot(t_stack *stack, int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == 0)
		error_print();
	new->num = num;
	new->up = stack->bot;
	if (stack->top == NULL)
		stack->top = new;
	else
		stack->bot->dn = new;
	new->dn = NULL;
	stack->bot = new;
	stack->size++;
}

int	rm_top(t_stack *stack)
{
	t_node	*del;
	int		num;

	del = stack->top;
	num = del->num;
	stack->top = stack->top->dn;
	free(del);
	if (stack->top == NULL)
		stack->bot = NULL;
	else
		stack->top->up = NULL;
	stack->size--;
	return (num);
}

int	rm_bot(t_stack *stack)
{
	t_node	*del;
	int		num;

	del = stack->bot;
	num = del->num;
	stack->bot = stack->bot->up;
	free(del);
	if (stack->bot == NULL)
		stack->top = NULL;
	else
		stack->bot->dn = NULL;
	stack->size--;
	return (num);
}
