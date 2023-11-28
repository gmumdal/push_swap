/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:10:21 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/27 20:25:05 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_command(t_stack *a, t_stack *b, char *command)
{
	if (ft_strncmp(command, "ss\n", ft_strlen(command)) == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strncmp(command, "rr\n", ft_strlen(command)) == 0)
	{
		rotate(a, 0);
		rotate(b, 0);
	}
	else if (ft_strncmp(command, "rrr\n", ft_strlen(command)) == 0)
	{
		rotate(a, 1);
		rotate(b, 1);
	}
	else
		error_print();
}

int	check_command(t_stack *a, t_stack *b, char *command)
{
	if (ft_strncmp(command, "sa\n", ft_strlen(command)) == 0)
		swap(a);
	else if (ft_strncmp(command, "sb\n", ft_strlen(command)) == 0)
		swap(b);
	else if (ft_strncmp(command, "pa\n", ft_strlen(command)) == 0)
		push(a, b);
	else if (ft_strncmp(command, "pb\n", ft_strlen(command)) == 0)
		push(b, a);
	else if (ft_strncmp(command, "ra\n", ft_strlen(command)) == 0)
		rotate(a, 0);
	else if (ft_strncmp(command, "rb\n", ft_strlen(command)) == 0)
		rotate(b, 0);
	else if (ft_strncmp(command, "rra\n", ft_strlen(command)) == 0)
		rotate(a, 1);
	else if (ft_strncmp(command, "rrb\n", ft_strlen(command)) == 0)
		rotate(b, 1);
	else
		both_command(a, b, command);
	ft_putstr_fd(command, 1);
	return (0);
}

int	ending_free(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	tmp = a->top;
	while (a->top != 0)
	{
		a->top = a->top->dn;
		free(tmp);
		tmp = a->top;
	}
	free(a);
	tmp = b->top;
	while (b->top != 0)
	{
		b->top = b->top->dn;
		free(tmp);
		tmp = b->top;
	}
	free(b);
	return (0);
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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_data	data;

	if (ac < 2)
		return (0);
	stack_init(&a);
	stack_init(&b);
	input_a(a, ac, av);
	data.size = a->size;
	if (check_ab(a, b, 1))
		return (ending_free(a, b));
	sorting_al(a, b, &data);
	return (ending_free(a, b));
}
