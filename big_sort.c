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

int	get_lowest(t_list **stack_a)
{
	int		lowest;
	t_list	*p;

	p = *stack_a;
	lowest = p->value;
	while (p->next)
	{
		if (p->value > p->next->value)
			lowest = p->next->value;
		p = p->next;
	}
	return (lowest);
}

int	get_index(t_list **stack_a)
{
	int		index;
	t_list	*p;

	p = *stack_a;
	index = p->index;
	while (p->next)
	{
		if (p->value > p->next->value)
			index = p->next->index;
		p = p->next;
	}
	return (index);
}
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
	
void	finish_sort(t_list **stack_a, t_list **stack_b)
{
	int		biggest;
	int		count;

	count = 0;
	while (!check_sorted(stack_a))
	{
		biggest = get_biggest(stack_a);
		while ((*stack_a)->value != biggest)
		{
			rotate_a(stack_a);
		}
		push_b(stack_a, stack_b);
		count++;
	}
	while (count >= 0)
	{
		push_a(stack_a, stack_b);
		count--;
	}
	while (!check_sorted(stack_a))
		rev_rotate(stack_a);
}

void	big_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	count;
	int	lowest;
	int	index;

	count = 0;
	if (check_sorted(stack_a))
		return ;
	while (count < size)
	{
		lowest = get_lowest(stack_a);
		index = get_index(stack_a);
		while ((*stack_a)->value != lowest)
		{
			if(index <= size / 2)
				rotate_a(stack_a);
			else if (index > size / 2)
				rev_rotate_a(stack_a);
		}
		push_b(stack_a, stack_b);
		count++;
	}
	while (count >= 0)
	{
		push_a(stack_a, stack_b);
		count--;
	}
	/*while (count < size - 3)*/
	/*{*/
	/*	if (count >= 2)*/
	/*	{*/
	/*		double_sort(stack_a, stack_b);*/
	/*		quick_sort_b(stack_b);*/
	/*	}*/
	/*	push_b(stack_a, stack_b);*/
	/*	quick_sort(stack_a);*/
	/*	count++;*/
	/*}*/
	/*sort_three(stack_a);*/
	/*while (count >= 0)*/
	/*{*/
	/*	if (count > 2)*/
	/*	{*/
	/*		double_sort(stack_a, stack_b);*/
	/*		quick_sort_b(stack_b);*/
	/*	}*/
	/*	push_a(stack_a, stack_b);*/
	/*	quick_sort(stack_a);*/
	/*	count--;*/
	/*}*/
	if (!check_sorted(stack_a))
		printf("not sorted\n");
	/*	big_sort(stack_a, stack_b, size);*/
}
