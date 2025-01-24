/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:34:32 by dagouill          #+#    #+#             */
/*   Updated: 2025/01/17 16:40:28 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_list **stack)
{
	t_list *last;

	last = ft_lstlast(stack);
	/*if ((*stack)->value > last->value && last->value < (*stack)->next->value)*/
	/*	rev_rotate_a(stack);*/
	if ((*stack)->value > last->value)
		rotate_a(stack);
	if ((*stack)->value > (*stack)->next->value)
		swap_a(stack);
}

void	quick_sort_b(t_list **stack)
{
	t_list *last;

	last = ft_lstlast(stack);
	/*if ((*stack)->value > last->value && last->value > (*stack)->next->value)*/
	/*	rev_rotate_b(stack);*/
	if ((*stack)->value < last->value)
		rotate_b(stack);
	if ((*stack)->value < (*stack)->next->value)
		swap_b(stack);
}
	
void	big_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	count;

	count = 0;
	if (check_sorted(stack_a))
		return ;
	while (count < size - 3)
	{
		if (count >= 2)
		{
			double_sort(stack_a, stack_b);
			quick_sort_b(stack_b);
		}
		push_b(stack_a, stack_b);
		quick_sort(stack_a);
		count++;
	}
	sort_three(stack_a);
	while (count >= 0)
	{
		if (count > 2)
		{
			double_sort(stack_a, stack_b);
			quick_sort_b(stack_b);
		}
		push_a(stack_a, stack_b);
		quick_sort(stack_a);
		count--;
	}
	if (!check_sorted(stack_a))
		return (big_sort(stack_a, stack_b, size));
}
