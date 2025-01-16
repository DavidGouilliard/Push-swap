/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:09:51 by dagouill          #+#    #+#             */
/*   Updated: 2025/01/15 18:23:40 by dagouill         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*p;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		print_error();
	stack_a = parse_arg(av);
	choose_sort(&stack_a, &stack_b);
	p = stack_a;
	printf("stack_a\n");
	while (p != NULL)
	{
		printf("index:%d value:%d\n", p->index, p->value);
		p = p->next;
	}
	p = stack_b;
	printf("stack_b\n");
	while (p != NULL)
	{
		printf("index:%d value:%d\n", p->index, p->value);
		p = p->next;
	}
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}	
