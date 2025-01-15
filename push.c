/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:49:51 by dagouill          #+#    #+#             */
/*   Updated: 2025/01/15 18:09:00 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_index(t_list **stack)
{
	int		i;
	t_list	*p;

	i = 0;
	p = *stack;
	while (p != NULL)
	{
		p->index = i;
		i++;
		p = p->next;
	}
}

void	push(t_list **stack1, t_list **stack2)
{
	t_list	*p;
	t_list	*new_node;

	if (!*stack1)
		return ;
	new_node = ft_lstnew(0, (*stack1)->value);
	if (stack2 == NULL)
		*stack2 = new_node;
	else
	{
		ft_lstadd_front(stack2, new_node);
		update_index(stack2);
	}
	p = *stack1;
	*stack1 = (*stack1)->next;
	free(p);
	update_index(stack1);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_b)
		return ;
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a)
		return ;
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
