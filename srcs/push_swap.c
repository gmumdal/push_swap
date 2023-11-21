/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:10:21 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/21 21:06:41 by hyeongsh         ###   ########.fr       */
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

void	check_command(t_stack *a, t_stack *b, char *command)
{
	if (ft_strncmp(command, "sa\n", ft_strlen(command)) == 0)
		swap(a);
	else if (ft_strncmp(command, "sb\n", ft_strlen(command)) == 0)
		swap(b);
	else if (ft_strncmp(command, "pa\n", ft_strlen(command)) == 0)
		push(a, b);
	else if (ft_strncmp(command, "pa\n", ft_strlen(command)) == 0)
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
}


int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_node	*tmp;

	if (ac < 2)
		return (0);
	stack_init(&a);
	stack_init(&b);
	input_a(a, ac, av);
	check_command(a, b, "sa\n");
	check_command(a, b, "ra\n");
	tmp = a->top;
	while (tmp != 0)
	{
		ft_putnbr_fd(tmp->num, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->dn;
	}
}
