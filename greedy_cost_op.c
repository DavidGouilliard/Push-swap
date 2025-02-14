/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_cost_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:47:49 by dagouill          #+#    #+#             */
/*   Updated: 2025/02/14 03:22:50 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_list	*set_to_push(t_list **stack)
{
	t_list	*p;
	t_list	*tag;
	int		lowest;

	p = *stack;
	tag = *stack;
	lowest = p->cost;
	while (p)
	{
		if (lowest > p->cost)
		{
			lowest = p->cost;
			tag = p;
		}
		p = p->next;
	}
	tag->to_push = 1;
	return (tag);
}

void	set_target_a(t_list **stack_a, t_list **stack_b)
{
	long	closest_smaller;
	t_list	*t;
	t_list	*p;

	if (!stack_a || !stack_b || !(*stack_a) || !(*stack_b))
		return ;
	p = *stack_a;
	while (p)
	{
		t = *stack_b;
		if (p->value < get_low(stack_b))
			closest_smaller = (long) get_big(stack_b);
		else
		{
			closest_smaller = (long) INT_MIN - 1;
			while (t)
			{
				if (t->value < p->value && t->value > closest_smaller)
						closest_smaller = (long) t->value;
				t = t->next;
			}
		}
		p->target = (int) closest_smaller;
		p = p->next;
	}
}

void	set_target_b(t_list **stack_a, t_list **stack_b)
{
	long	closest_bigger;
	t_list	*t;
	t_list	*p;

	if (!stack_a || !stack_b || !(*stack_a) || !(*stack_b))
		return ;
	p = *stack_b;
	while (p)
	{
		t = *stack_a;
		if (p->value > get_big(stack_a))
			closest_bigger = (long) get_low(stack_a);
		else
		{
			closest_bigger = (long) INT_MAX + 1;
			while (t)
			{
				if (t->value > p->value && t->value < closest_bigger)
						closest_bigger = (long) t->value;
				t = t->next;
			}
		}
		p->target = (int) closest_bigger;
		p = p->next;
	}
}

int	find_cost(t_list **p, t_list **stack1, t_list **stack2)
{
	int		cost;
	int		size1;
	int		size2;
	t_list	*t;

	size1 = ft_lstsize(stack1);
	size2 = ft_lstsize(stack2);
	t = *stack2;
	while (t->value != (*p)->target)
		t = t->next;
	if ((*p)->above_m)
		cost = (*p)->index;
	else
		cost = size1 - (*p)->index;
	if (t->above_m)
		cost += t->index;
	else
		cost += size2 - t->index;
	return (cost);
}

void	set_cost(t_list **stack1, t_list **stack2)
{
	t_list	*p;
	int		cost;

	p = *stack1;
	while (p)
	{
		cost = find_cost(&p, stack1, stack2);
		p->cost = cost;
		p = p->next;
	}
}	
