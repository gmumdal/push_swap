/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:57:54 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/28 13:50:03 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
	int				num;
	struct s_node	*up;
	struct s_node	*dn;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
}	t_stack;

typedef struct s_data
{
	int	size;
	int	tri_n;
	int	*tri_s;
}	t_data;

void	error_print(void);
int		ps_atoi(char *str);
void	input_a(t_stack *a, int ac, char **av);
void	dupli_check(t_stack *a, int num);
void	stack_init(t_stack **stack);
void	add_top(t_stack *stack, int num);
void	add_bot(t_stack *stack, int num);
int		rm_top(t_stack *stack);
int		rm_bot(t_stack *stack);
void	swap(t_stack *stack);
void	push(t_stack *dst, t_stack *src);
void	rotate(t_stack *stack, int reverse);
int		check_command(t_stack *a, t_stack *b, char *command);
void	both_command(t_stack *a, t_stack *b, char *command);
int		check_ab(t_stack *a, t_stack *b, int flag);
int		ending_free(t_stack *a, t_stack *b);
int		sorting_al(t_stack *a, t_stack *b, t_data *data);
int		sorting_three(t_stack *a, t_stack *b);
int		sorting_four(t_stack *a, t_stack *b);
int		sorting_five(t_stack *a, t_stack *b);

int		tri_num_check(int size, int *push_flag);
int		tri_direction_check(int tri_index);
int		tri_size_check(int size, int tri_index, int tri_num, int push_flag);
int		max_check(int *n, int size);
int		min_check(int *n, int size);
void	division(t_stack *a, t_stack *b, t_data *data, int push_flag);
int		division_in_a(t_stack *a, t_stack *b, int tri_direct, int tri_size);
int		division_in_b(t_stack *a, t_stack *b, int tri_direct, int tri_size);
int		division_rotate_a(t_stack *a, t_stack *b, int tri_direct, int tri_size);
int		division_push_b(t_stack *a, t_stack *b, int tri_direct, int tri_size);
void	merge(t_stack *a, t_stack *b, t_data *data, int push_flag);
void	first_setting(t_stack *a, t_stack *b, t_data *data, int push_flag);
void	merge_in_a(t_stack *a, t_stack *b, t_data *data, int *index);
void	merge_in_b(t_stack *a, t_stack *b, t_data *data, int *index);
void	merge_a_flag0(t_stack *a, t_stack *b, t_data *data, int *index);
void	merge_a_flag1(t_stack *a, t_stack *b, t_data *data, int *index);
void	merge_b_flag0(t_stack *a, t_stack *b, t_data *data, int *index);
void	merge_b_flag1(t_stack *a, t_stack *b, t_data *data, int *index);

#endif
