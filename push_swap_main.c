/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:09:51 by dagouill          #+#    #+#             */
/*   Updated: 2025/01/07 16:59:08 by dagouill         ###   ########.fr       */
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
	t_list	*p;

	stack_a = NULL;
	if (ac < 2)
		print_error();
	stack_a = parse_arg(av);
	p = stack_a;
	while (p != NULL)
	{
		printf("index:%d value:%d\n", p->index, p->value);
		p = p->next;
	}
	ft_lstclear(&stack_a);
	return (0);
}	
