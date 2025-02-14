/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:31:59 by dagouill          #+#    #+#             */
/*   Updated: 2025/02/14 03:23:04 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*p;
	int		temp;

	temp = (*stack)->value;
	p = *stack;
	while (p->next)
	{
		p->value = p->next->value;
		p = p->next;
	}
	p->value = temp;
}

void	rotate_a(t_list **stack_a)
{
	if (!*stack_a)
		return ;
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_list **stack_b)
{
	if (!*stack_b)
		return ;
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_ab(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a || !*stack_b)
		return ;
	rotate(stack_b);
	rotate(stack_a);
	ft_putstr_fd("rr\n", 1);
}
