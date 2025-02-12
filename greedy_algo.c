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

t_list *get_target(t_list **p, t_list **stack)
{
	t_list	*t;

	t = *stack;
	while (t && t->value != (*p)->target)
		t = t->next;
	return (t);
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

void rot_topush_a(t_list **stack_a, t_list *p)
{
	if ((*stack_a)->value == p->value)
		return ;
	if (p->above_m)
		rotate_a(stack_a);
	else
		rev_rotate_a(stack_a);
}

void	push_opp_a(t_list **stack_a, t_list **stack_b, t_list *p)
{
	t_list	*target;
	int		value;
	int		target_v;
	
	value = p->value;
	target = get_target(&p, stack_b);
	target_v = target->value;
	if (p->above_m && target->above_m && (*stack_a)->value != value && (*stack_b)->value != target_v)
		rotate_ab(stack_a, stack_b);
	else if (!(p->above_m) && !(target->above_m) && (*stack_a)->value != value && (*stack_b)->value != target_v)
		rev_rotate_ab(stack_a, stack_b);
	else
		rot_topush_a(stack_a, p);
}	

void rot_topush_b(t_list **stack_b, t_list *p)
{
	if ((*stack_b)->value == p->value)
		return ;
	if (p->above_m)
		rotate_b(stack_b);
	else
		rev_rotate_b(stack_b);
}

void	push_opp_b(t_list **stack_a, t_list **stack_b, t_list *p)
{
	t_list	*target;
	int		value;
	int		target_v;
	
	value = p->value;
	target = get_target(&p, stack_a);
	target_v = target->value;
	if (p->above_m && target->above_m && (*stack_b)->value != value && (*stack_a)->value != target_v)
		rotate_ab(stack_a, stack_b);
	else if (!(p->above_m) && !(target->above_m) && (*stack_b)->value != value && (*stack_a)->value != target_v)
		rev_rotate_ab(stack_a, stack_b);
	else
		rot_topush_b(stack_b, p);
}	

void rot_target_b(t_list **stack_b, int target)
{
	t_list	*p;

	if ((*stack_b)->value == target)
		return ;
	p = *stack_b;
	while (p->value != target)
		p = p->next;
	if (p->above_m)
		rotate_b(stack_b);
	else
		rev_rotate_b(stack_b);
}


void rot_target_a(t_list **stack_a, int target)
{
	t_list	*p;

	if ((*stack_a)->value == target)
		return ;
	p = *stack_a;
	while (p->value != target)
		p = p->next;
	if (p->above_m)
		rotate_a(stack_a);
	else
		rev_rotate_a(stack_a);
}
void	to_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*p;
	int		value;
	int		target;

	set_target_a(stack_a, stack_b);
	set_cost(stack_a, stack_b);
	p = set_to_push(stack_a);
	value = p->value;
	target = p->target;
	while ((*stack_a)->value != value)
		push_opp_a(stack_a, stack_b, p);
	while ((*stack_b)->value != target)
		rot_target_b(stack_b, target);
	(*stack_a)->to_push = 0;
	push_b(stack_a, stack_b);
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

void	min_on_top(t_list **stack_a)
{
	int		lowest;
	t_list	*p;
	
	p = *stack_a;
	lowest	= get_low(stack_a);
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

void	to_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*p;
	int		value;
	int		target;

	set_target_b(stack_a, stack_b);
	set_cost(stack_b, stack_a);
	p = set_to_push(stack_b);
	value = p->value;
	target = p->target;
	while ((*stack_b)->value != value)
		push_opp_b(stack_a, stack_b, p);
	while ((*stack_a)->value != target)
		rot_target_a(stack_a, target);
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
	/*sort_b(stack_a, stack_b);*/
	while (count > 0)
	{
		to_push_b(stack_a, stack_b);
		count--;
	}
	min_on_top(stack_a);
	if (!check_sorted(stack_a))
		return (greedy_sort(stack_a, stack_b, size)) ;
}
