/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:44:09 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/28 14:47:54 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_a_flag0(t_stack *a, t_stack *b, t_data *data, int *index)
{
	int	num[3];
	int	i;

	i = 0;
	while (i < 3)
		num[i++] = 2147483647;
	if (data->tri_s[index[0]] != 0)
		num[0] = b->bot->num;
	if (data->tri_s[index[1]] != 0)
		num[1] = b->top->num;
	if (data->tri_s[index[2]] != 0)
		num[2] = a->bot->num;
	if (min_check(num, 3) == 0 && !check_command(a, b, "rrb\n")
		&& !check_command(a, b, "pa\n"))
		data->tri_s[index[0]]--;
	else if (min_check(num, 3) == 1 && !check_command(a, b, "pa\n"))
		data->tri_s[index[1]]--;
	else if (min_check(num, 3) == 2 && !check_command(a, b, "rra\n"))
		data->tri_s[index[2]]--;
}

void	merge_a_flag1(t_stack *a, t_stack *b, t_data *data, int *index)
{
	int	num[3];
	int	i;

	i = 0;
	while (i < 3)
		num[i++] = -2147483648;
	if (data->tri_s[index[0]] != 0)
		num[0] = b->bot->num;
	if (data->tri_s[index[1]] != 0)
		num[1] = b->top->num;
	if (data->tri_s[index[2]] != 0)
		num[2] = a->bot->num;
	if (max_check(num, 3) == 0 && !check_command(a, b, "rrb\n")
		&& !check_command(a, b, "pa\n"))
		data->tri_s[index[0]]--;
	else if (max_check(num, 3) == 1 && !check_command(a, b, "pa\n"))
		data->tri_s[index[1]]--;
	else if (max_check(num, 3) == 2 && !check_command(a, b, "rra\n"))
		data->tri_s[index[2]]--;
}

void	merge_b_flag0(t_stack *a, t_stack *b, t_data *data, int *index)
{
	int	num[3];
	int	i;

	i = 0;
	while (i < 3)
		num[i++] = 2147483647;
	if (data->tri_s[index[0]] != 0)
		num[0] = a->bot->num;
	if (data->tri_s[index[1]] != 0)
		num[1] = a->top->num;
	if (data->tri_s[index[2]] != 0)
		num[2] = b->bot->num;
	if (min_check(num, 3) == 0 && !check_command(a, b, "rra\n")
		&& !check_command(a, b, "pb\n"))
		data->tri_s[index[0]]--;
	else if (min_check(num, 3) == 1 && !check_command(a, b, "pb\n"))
		data->tri_s[index[1]]--;
	else if (min_check(num, 3) == 2 && !check_command(a, b, "rrb\n"))
		data->tri_s[index[2]]--;
}

void	merge_b_flag1(t_stack *a, t_stack *b, t_data *data, int *index)
{
	int	num[3];
	int	i;

	i = 0;
	while (i < 3)
		num[i++] = -2147483648;
	if (data->tri_s[index[0]] != 0)
		num[0] = a->bot->num;
	if (data->tri_s[index[1]] != 0)
		num[1] = a->top->num;
	if (data->tri_s[index[2]] != 0)
		num[2] = b->bot->num;
	if (max_check(num, 3) == 0 && !check_command(a, b, "rra\n")
		&& !check_command(a, b, "pb\n"))
		data->tri_s[index[0]]--;
	else if (max_check(num, 3) == 1 && !check_command(a, b, "pb\n"))
		data->tri_s[index[1]]--;
	else if (max_check(num, 3) == 2 && !check_command(a, b, "rrb\n"))
		data->tri_s[index[2]]--;
}
