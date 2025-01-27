/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:13:50 by dagouill          #+#    #+#             */
/*   Updated: 2025/01/15 19:27:40 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_list **stack_a)
{
	t_list	*p;

	p = *stack_a;
	while (p->next)
	{
		if (p->value > p->next->value)
			return (0);
		p = p->next;
	}
	return (1);
}

void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a(stack_a);
}

void	sort_three(t_list **stack_a)
{
	if ((*stack_a)->next->value > (*stack_a)->next->next->value
	&& (*stack_a)->value > (*stack_a)->next->value)
	{
		swap_a(stack_a);
		rev_rotate_a(stack_a);
	}
	else if ((*stack_a)->next->value > (*stack_a)->next->next->value
	&& (*stack_a)->value < (*stack_a)->next->next->value)
	{
		rev_rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if ((*stack_a)->next->value > (*stack_a)->next->next->value
	&& (*stack_a)->value > (*stack_a)->next->next->value)
		rev_rotate_a(stack_a);
	else if ((*stack_a)->value > (*stack_a)->next->next->value)
		rotate_a(stack_a);
	else if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a(stack_a);
}

void	rev_sort_three(t_list **stack_b)
{
	if ((*stack_b)->next->value < (*stack_b)->next->next->value
	&& (*stack_b)->value < (*stack_b)->next->value)
	{
		swap_b(stack_b);
		rev_rotate_b(stack_b);
	}
	else if ((*stack_b)->next->value < (*stack_b)->next->next->value
	&& (*stack_b)->value > (*stack_b)->next->next->value)
	{
		rev_rotate_b(stack_b);
		swap_b(stack_b);
	}
	else if ((*stack_b)->next->value < (*stack_b)->next->next->value
	&& (*stack_b)->value < (*stack_b)->next->next->value)
		rev_rotate_b(stack_b);
	else if ((*stack_b)->value < (*stack_b)->next->next->value)
		rotate_b(stack_b);
	else if ((*stack_b)->value < (*stack_b)->next->value)
		swap_b(stack_b);
}
void	sort_four(t_list **stack_a, t_list **stack_b)
{
	if (check_sorted(stack_a))
		return ;
	if ((*stack_a)->value > (*stack_a)->next->next->next->value)
		rotate_a(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a(stack_a);
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
	if ((*stack_a)->value > (*stack_a)->next->next->next->value)
		rotate_a(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a(stack_a);
	if (!check_sorted(stack_a))
		sort_four(stack_a, stack_b);
}
int	get_biggest(t_list **stack_a)
{
	int		biggest;
	t_list	*p;

	p = *stack_a;
	biggest = p->value;
	while (p->next)
	{
		if (p->value < p->next->value)
			biggest = p->next->value;
		p = p->next;
	}
	return (biggest);
}

void	double_sort(t_list **stack_a, t_list **stack_b)
{
	t_list *last_a;
	t_list *last_b;

	last_a = ft_lstlast(stack_a);
	last_b = ft_lstlast(stack_b);
	if ((*stack_a)->value > last_a->value && (*stack_b)->value < last_b->value)
		rotate_ab(stack_a, stack_b);
	if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_b)->value < (*stack_b)->next->value)
		swap_ab(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if (check_sorted(stack_a))
		return ;
	push_b(stack_a, stack_b);
	quick_sort(stack_a);
	push_b(stack_a, stack_b);
	double_sort(stack_a, stack_b);
	sort_three(stack_a);
	push_b(stack_a, stack_b);
	double_sort(stack_a, stack_b);
	rev_sort_three(stack_b);
	push_a(stack_a, stack_b);
	double_sort(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
	quick_sort(stack_a);
	push_a(stack_a, stack_b);
	quick_sort(stack_a);
	if (!check_sorted(stack_a))
		sort_five(stack_a, stack_b);
}
void	choose_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(stack_a);
	if (size == 2)
		sort_two(stack_a);
	if (size == 3)
		sort_three(stack_a);
	if (size == 4)
		sort_four(stack_a, stack_b);
	if (size == 5)
		sort_five(stack_a, stack_b);
	if (size > 5)
		big_sort(stack_a, stack_b, size);
}
