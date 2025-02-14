/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:54:08 by dagouill          #+#    #+#             */
/*   Updated: 2025/02/14 03:20:54 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_target(t_list **p, t_list **stack)
{
	t_list	*t;

	t = *stack;
	while (t && t->value != (*p)->target)
		t = t->next;
	return (t);
}

void	rot_target_b(t_list **stack_b, t_list *t)
{
	if (t->above_m)
		rotate_b(stack_b);
	else
		rev_rotate_b(stack_b);
}

void	rot_target_a(t_list **stack_a, t_list *t)
{
	if (t->above_m)
		rotate_a(stack_a);
	else
		rev_rotate_a(stack_a);
}

void	push_opp_a(t_list **stack_a, t_list **stack_b, t_list *p, t_list *t)
{
	if (p->above_m && t->above_m)
		rotate_ab(stack_a, stack_b);
	else if (!(p->above_m) && !(t->above_m))
		rev_rotate_ab(stack_a, stack_b);
	else
		rot_target_a(stack_a, p);
}	

void	push_opp_b(t_list **stack_a, t_list **stack_b, t_list *p, t_list *t)
{
	if (p->above_m && t->above_m)
		rotate_ab(stack_a, stack_b);
	else if (!(p->above_m) && !(t->above_m))
		rev_rotate_ab(stack_a, stack_b);
	else
		rot_target_b(stack_b, p);
}	
