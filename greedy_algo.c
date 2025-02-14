/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:19:32 by dagouill          #+#    #+#             */
/*   Updated: 2025/02/14 03:20:35 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_on_top(t_list **stack_a)
{
	int		lowest;
	t_list	*p;

	p = *stack_a;
	lowest = get_low(stack_a);
	while (p->value != lowest)
		p = p->next;
	while ((*stack_a)->value != lowest)
	{
		if (p->above_m)
			rotate_a(stack_a);
		else
			rev_rotate_a(stack_a);
	}
}	

void	to_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*p;
	t_list	*t;
	int		value;
	int		target;

	set_target_a(stack_a, stack_b);
	set_cost(stack_a, stack_b);
	p = set_to_push(stack_a);
	t = get_target(&p, stack_b);
	value = p->value;
	target = p->target;
	while ((*stack_a)->value != value && (*stack_b)->value != target)
		push_opp_a(stack_a, stack_b, p, t);
	while ((*stack_a)->value != value)
		rot_target_a(stack_a, p);
	while ((*stack_b)->value != target)
		rot_target_b(stack_b, t);
	(*stack_a)->to_push = 0;
	push_b(stack_a, stack_b);
}

void	to_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*p;
	t_list	*t;
	int		value;
	int		target;

	set_target_b(stack_a, stack_b);
	set_cost(stack_b, stack_a);
	p = set_to_push(stack_b);
	value = p->value;
	target = p->target;
	t = get_target(&p, stack_a);
	while ((*stack_b)->value != value && (*stack_a)->value != target)
		push_opp_b(stack_a, stack_b, p, t);
	while ((*stack_b)->value != value)
		rot_target_b(stack_b, p);
	while ((*stack_a)->value != target)
		rot_target_a(stack_a, t);
	(*stack_b)->to_push = 0;
	push_a(stack_a, stack_b);
}

void	greedy_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	count;

	if (check_sorted(stack_a))
		return ;
	count = 2;
	size = ft_lstsize(stack_a);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	while (count < size - 3)
	{
		to_push_a(stack_a, stack_b);
		count++;
	}
	sort_three(stack_a);
	while (*stack_b)
		to_push_b(stack_a, stack_b);
	min_on_top(stack_a);
	if (!check_sorted(stack_a))
		return (greedy_sort(stack_a, stack_b, size));
}
