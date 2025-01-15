/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:31:59 by dagouill          #+#    #+#             */
/*   Updated: 2025/01/15 15:10:39 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_list *stack)
{
	t_list	*p;
	int		temp;
	int		temp2;
	
	p = ft_lstlast(stack);
	temp = p->value;
	p = stack;
	temp2 = p->value;
	p->value = temp;
	while (p->next)
	{
		p = p->next;
		temp = p->value;
		p->value = temp2;
		temp2 = temp;
	}
}

void	rev_rotate_a(t_list *stack_a)
{
	rev_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rev_rotate_b(t_list *stack_b)
{
	rev_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rev_rotate_ab(t_list *stack_a, t_list *stack_b)
{

	rev_rotate(stack_b);
	rev_rotate(stack_a);
	ft_putstr_fd("rrr\n", 1);
}
