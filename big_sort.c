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

int	get_lowest(t_list **stack_a, int start, int end)
{
	int		lowest;
	t_list	*p;

	p = *stack_a;
	while (p->next->index < start && p->next)
		p = p->next;
	lowest = p->value;
	while (p->next && p->next->index < end)
	{
		if (lowest > p->next->value)
			lowest = p->next->value;
		p = p->next;
	}
	return (lowest);
}

int	get_big(t_list **stack_a)
{
	int		big;
	t_list	*p;

	p = *stack_a;
	big = p->value;
	while (p)
	{
		if (big < p->value)
			big = p->value;
		p = p->next;
	}
	return (big);
}

int	get_low(t_list **stack_a)
{
	int		low;
	t_list	*p;

	p = *stack_a;
	low = p->value;
	while (p)
	{
		if (low > p->value)
			low = p->value;
		p = p->next;
	}
	return (low);
}

int	get_index_b(t_list **stack_a)
{
	int		index;
	int		big;
	t_list	*p;

	p = *stack_a;
	index = p->index;
	big = p->value;
	while (p->next)
	{
		if (big < p->next->value)
		{
			index = p->next->index;
			big = p->next->value;
		}
		p = p->next;
	}
	return (index);
}

int	get_index_a(t_list **stack_a)
{
	int		index;
	int		big;
	t_list	*p;

	p = *stack_a;
	index = p->index;
	big = p->value;
	while (p->next)
	{
		if (big > p->next->value)
		{
			index = p->next->index;
			big = p->next->value;
		}
		p = p->next;
	}
	return (index);
}

int	get_index(t_list **stack_a, int start, int end)
{
	int		index;
	int		lowest;
	t_list	*p;

	p = *stack_a;
	while (p->next->index < start && p->next)
		p = p->next;
	/*printf("index de p : %d\n", p->index);*/
	index = p->index;
	lowest = p->value;
	while (p->next && p->next->index < end)
	{
		if (lowest > p->next->value)
		{
			index = p->next->index;
			lowest = p->next->value;
		}
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

void	sort_chunk(t_list **stack_a, t_list **stack_b, int size)
{
	int	low_up;
	int	low_down;
	int	count;
	int	the_value;

	count = 0;
	while (count < size / 4)
	{
		low_up = get_index(stack_a, 0, size / 4);
		low_down = get_index(stack_a, size - size / 4 , size);
		if (low_up < size - count - low_down)
		{
			the_value = get_lowest(stack_a, 0, size / 4);
			while ((*stack_a)->value != the_value)
				rotate_a(stack_a);
		}
		else if (low_up >= size - count - low_down)
		{
			the_value = get_lowest(stack_a, size - size / 4 , size);
			while ((*stack_a)->value != the_value)
				rev_rotate_a(stack_a);
		}
		push_b(stack_a, stack_b);
		count++;
		size--;
	}
}
			
void	sort_b(t_list ** stack_a, t_list **stack_b)
{
	int	biggest;
	int	index;
	int	size;
	int	count;

	count = 0;
	size = ft_lstsize(stack_b);
	while (count < size)
	{
		biggest = get_big(stack_b);
		index = get_index_b(stack_b);
		while ((*stack_b)->value != biggest)
		{
			if(index < (size - count) / 2)
				rotate_b(stack_b);
			else if (index >= (size - count) / 2)
				rev_rotate_b(stack_b);
		}
		push_a(stack_a, stack_b);
		count++;
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	count;
	int	lowest;
	int	index;

	count = 0;
	if (check_sorted(stack_a))
		return ;
	push_b(stack_a, stack_b);
	/*printf("%d\n", get_index(stack_a, size - size / 4 , size));*/
	/*sort_chunk(stack_a, stack_b, size);*/
	size = ft_lstsize(stack_a);
	while (count < size)
	{
		lowest = get_big(stack_a);
		index = get_index_a(stack_a);
		while ((*stack_a)->value != lowest)
		{
			if(index < (size - count) / 2)
				rotate_a(stack_a);
			else if (index >= (size - count) / 2)
				rev_rotate_a(stack_a);
		}
		push_b(stack_a, stack_b);
		count++;
	}
	sort_b(stack_a, stack_b);

	if (!check_sorted(stack_a))
		printf("not sorted\n");
	/*	big_sort(stack_a, stack_b, size);*/
}
