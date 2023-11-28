/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:10:21 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/28 13:51:10 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	check_command(t_stack *a, t_stack *b, char *command)
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
}

void	ending_free(t_stack *a, t_stack *b)
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
}

void	check_ab(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (b->top != 0)
	{
		ft_putstr_fd("KO\n", 1);
		ending_free(a, b);
		exit(0);
	}
	tmp = a->top;
	while (tmp->dn != 0)
	{
		if (tmp->num > tmp->dn->num)
		{
			ft_putstr_fd("KO\n", 1);
			ending_free(a, b);
			exit(0);
		}
		tmp = tmp->dn;
	}
	ft_putstr_fd("OK\n", 1);
	ending_free(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*tmp;

	if (ac < 2)
		return (0);
	stack_init(&a);
	stack_init(&b);
	input_a(a, ac, av);
	while (1)
	{
		tmp = get_next_line(0);
		if (tmp == 0)
			break ;
		check_command(a, b, tmp);
		free(tmp);
	}
	check_ab(a, b);
}
