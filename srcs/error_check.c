/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:28:50 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/23 20:47:34 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_print(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	ps_atoi(char *str)
{
	long long	num;
	int			plma;

	num = 0;
	plma = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		plma = -1;
	}
	while (*str >= '0' && *str <= '9' && *str != 0)
	{
		num = 10 * num + (*str - '0');
		str++;
	}
	num *= plma;
	if (*str != 0 || num < -2147483648 || num > 2147483647)
		error_print();
	return (num);
}

void	dupli_check(t_stack *a, int num)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp != 0)
	{
		if (tmp->num == num)
			error_print();
		tmp = tmp->dn;
	}
}

void	input_a(t_stack *a, int ac, char **av)
{
	char	**tmp;	
	int		num;
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		if (ft_strchr(av[i], '\n'))
			tmp = ft_split(av[i], '\n');
		else
			tmp = ft_split(av[i], ' ');
		j = 0;
		while (tmp[j] != 0)
		{
			num = ps_atoi(tmp[j]);
			dupli_check(a, num);
			add_bot(a, num);
			free(tmp[j++]);
		}
		free(tmp);
	}
}
