/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:57:54 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/23 19:49:31 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
void	check_command(t_stack *a, t_stack *b, char *command);
void	both_command(t_stack *a, t_stack *b, char *command);
void	ending_free(t_stack *a, t_stack *b);
void	check_ab(t_stack *a, t_stack *b);

#endif
