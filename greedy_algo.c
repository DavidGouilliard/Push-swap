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
	t_list	*tag;
	int		lowest;

	p = *stack_a;
	tag = *stack_a;
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
			closest_smaller = get_big(stack_b);
		else
		{
			closest_smaller = INT_MIN;
			while (t) 
			{
				if (t->value < p->value && t->value > closest_smaller)
						closest_smaller = t->value;
				t = t->next;
			}
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

void	push_opp_double(t_list **stack_a, t_list **stack_b, t_list *p)
{
	t_list	*target;
	
	target = get_target(&p, stack_b);
	if (p->above_m && target->above_m && (*stack_a)->value != p->value && (*stack_b)->value != target->value)
		rotate_ab(stack_a, stack_b);
	else if (!(p->above_m) && !(target->above_m) && (*stack_a)->value != p->value && (*stack_b)->value != target->value)
		rev_rotate_ab(stack_a, stack_b);
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

void rot_topush_b(t_list **stack_b, t_list *p)
{
	if ((*stack_b)->value == p->value)
		return ;
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
		rot_topush_a(stack_a, p);
	while ((*stack_b)->value != target)
		rot_target_b(stack_b, target);
		/*push_opp_double(stack_a, stack_b, p);*/
	(*stack_a)->to_push = 0;
	push_b(stack_a, stack_b);
	if (target == get_big(stack_b))
		rotate_b(stack_b);
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
			closest_bigger = get_low(stack_a);
		else
		{
			closest_bigger = INT_MAX;
			while (t) 
			{
				if (t->value > p->value && t->value < closest_bigger)
						closest_bigger = t->value;
				t = t->next;
			}
		}
		p->target = closest_bigger;
		p = p->next;
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
		rot_topush_a(stack_b, p);
	while ((*stack_a)->value != target)
		rot_target_b(stack_a, target);
	/*push_opp_double(stack_b, stack_a, p);*/
	(*stack_b)->to_push = 0;
	push_a(stack_a, stack_b);
	if (target == get_low(stack_a))
		rotate_a(stack_a);
	/*if ((*stack_a)->value < ft_lstlast(stack_a)->value)*/
	/*	rev_rotate_b(stack_a);*/
	/*if(p->target == get_big(stack_a))*/
	/*	rotate_b(stack_a);*/
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
	/*if (!check_sorted(stack_a))*/
	/*	return (greedy_sort(stack_a, stack_b, size)) ;*/
	/*sort_b(stack_a, stack_b);*/
}
