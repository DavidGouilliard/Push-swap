/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:19:32 by dagouill          #+#    #+#             */
/*   Updated: 2025/02/08 21:53:18 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*set_to_push(t_list **stack_a)
{
	t_list	*p;
	int		lowest;

	p = *stack_a;
	lowest = p->cost;
	while (p->next)
	{
		if (lowest > p->next->cost)
			lowest = p->next->cost;
		p = p->next;
	}
	p->to_push = 1;
	return (p);
}
	
void	set_target_a(t_list **stack_a, t_list **stack_b)
{
	int		closest_smaller;
	t_list	*t;
	t_list	*p;

	p = *stack_a;
	t = *stack_b;
	while (p)
	{
		closest_smaller = t->value;
		t = *stack_b;
		if (p->value < get_low(stack_b))
			closest_smaller = get_big(stack_b);
		while (t->next && t->next->value < p->value)
		{
			if (closest_smaller < t->next->value)
				closest_smaller = t->next->value;
			t = t->next;
		}
		p->target = closest_smaller;
		p = p->next;
	}
}

t_list *get_target(t_list **p, t_list **stack)
{
	t_list	*t;

	t = *stack;
	while (t && t->value != (*p)->target)
		t = t->next;
	return (t);
}
	
	
int	find_cost_a(t_list **p, t_list **stack_a, t_list **stack_b)
{
	int		cost;
	int		size_a;
	int		size_b;
	t_list	*pb;

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	pb = get_target(p, stack_b);
	if ((*p)->above_m)
		cost = (*p)->index;
	else
		cost = size_a - (*p)->index;
	if (pb->index <= size_b / 2)
		cost += pb->index;
	else
		cost += size_b - pb->index;
	return (cost);
}
		

void	set_cost_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*p;
	int		cost;

	if (!*stack_a || !*stack_b)
		return ;
	p = *stack_a;
	while (p)
	{
		cost = find_cost_a(&p, stack_a, stack_b);
		p->cost = cost;
		p = p->next;
	}
}	

void	push_opp_double(t_list **stack_a, t_list **stack_b, t_list *p)
{
	t_list	*target;
	
	target = get_target(&p, stack_b);
	if (p->above_m && target->above_m && (*stack_a)->value != p->value && (*stack_b)->value != target->value)
		rotate_ab(stack_a, stack_b);
	else if (!(p->above_m) && !(target->above_m) && (*stack_a)->value != p->value && (*stack_b)->value != target->value)
		rev_rotate_ab(stack_a, stack_b);
}	
	
void rot_a(t_list **stack_a, t_list *p)
{
	if ((*stack_a)->value != p->value)
	{
		if (p->above_m)
			rotate_a(stack_a);
		else
			rev_rotate_a(stack_a);
	}
}

void rot_b(t_list **stack_b, t_list *p)
{
	t_list	*target;

	target = get_target(&p, stack_b);
	if ((*stack_b)->value != target->value)
	{
		if (target->above_m)
			rotate_b(stack_b);
		else
			rev_rotate_b(stack_b);
	}
}

void	to_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*p;
	int		value;
	int		target;

	set_target_a(stack_a, stack_b);
	set_cost_a(stack_a, stack_b);
	p = set_to_push(stack_a);
	value = p->value;
	target = p->target;
	while ((*stack_a)->value != value && (*stack_b)->value != target)
	{
		push_opp_double(stack_a, stack_b, p);
		rot_a(stack_a, p);
		rot_b(stack_b, p);
	}
	(*stack_a)->to_push = 0;
	push_b(stack_a, stack_b);
}

void	set_target_b(t_list **stack_a, t_list **stack_b)
{
	int		closest_bigger;
	t_list	*t;
	t_list	*p;

	p = *stack_b;
	t = *stack_a;
	while (p)
	{
		closest_bigger = t->value;
		t = *stack_a;
		if (p->value > get_big(stack_a))
			closest_bigger = get_low(stack_a);
		while (t->next && t->next->value > p->value)
		{
			if (closest_bigger > t->next->value)
				closest_bigger = t->next->value;
			t = t->next;
		}
		p->target = closest_bigger;
		p = p->next;
	}
}
int	find_cost_b(t_list **p, t_list **stack_a, t_list **stack_b)
{
	int		cost;
	int		size_a;
	int		size_b;
	t_list	*pb;

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	pb = get_target(p, stack_a);
	if ((*p)->above_m)
		cost = (*p)->index;
	else
		cost = size_b - (*p)->index;
	if (pb->index <= size_a / 2)
		cost += pb->index;
	else
		cost += size_a - pb->index;
	return (cost);
}
void	set_cost_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*p;
	int		cost;

	if (!*stack_a || !*stack_b)
		return ;
	p = *stack_b;
	while (p)
	{
		cost = find_cost_b(&p, stack_a, stack_b);
		p->cost = cost;
		p = p->next;
	}
}	

void tworot_b(t_list **stack_b, t_list *p)
{
	if ((*stack_b)->value != p->value)
	{
		if (p->above_m)
			rotate_b(stack_b);
		else
			rev_rotate_a(stack_b);
	}
}

void tworot_a(t_list **stack_a, t_list *p)
{
	t_list	*target;

	target = get_target(&p, stack_a);
	if ((*stack_a)->value != target->value)
	{
		if (target->above_m)
			rotate_a(stack_a);
		else
			rev_rotate_a(stack_a);
	}
}
void	to_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*p;
	int		value;
	int		target;

	set_target_b(stack_a, stack_b);
	set_cost_b(stack_a, stack_b);
	p = set_to_push(stack_b);
	value = p->value;
	target = p->target;
	while ((*stack_b)->value != value && (*stack_a)->value != target)
	{
		/*push_opp_double(stack_b, stack_a, p);*/
		tworot_a(stack_a, p);
		tworot_b(stack_b, p);
	}
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
	while (count > 0)
	{
		to_push_b(stack_a, stack_b);
		count--;
	}
	if (!check_sorted(stack_a))
		return (greedy_sort(stack_a, stack_b, size)) ;
	/*sort_b(stack_a, stack_b);*/
}
