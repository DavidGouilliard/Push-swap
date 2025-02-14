/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:13:50 by dagouill          #+#    #+#             */
/*   Updated: 2025/02/14 03:19:07 by dagouill         ###   ########.fr       */
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
	if (size > 4)
		greedy_sort(stack_a, stack_b, size);
}
