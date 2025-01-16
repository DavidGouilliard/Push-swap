/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:32:27 by dagouill          #+#    #+#             */
/*   Updated: 2025/01/15 18:00:28 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	int	temp;

	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
}

void	swap_a(t_list **stack_a)
{
	if (ft_lstsize(stack_a) < 2)
		return ;
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_list **stack_b)
{
	if (ft_lstsize(stack_b) < 2)
		return ;
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(stack_a) < 2 || ft_lstsize(stack_b) < 2)
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
