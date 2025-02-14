/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:09:51 by dagouill          #+#    #+#             */
/*   Updated: 2025/02/14 03:15:58 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)

{
	t_list	*p;

	p = NULL;
	while (*lst)
	{
		p = (*lst)->next;
		free(*lst);
		*lst = p;
	}
	*lst = NULL;
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

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		print_error();
	stack_a = parse_arg(av);
	choose_sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}	
