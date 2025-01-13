/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:19:16 by dagouill          #+#    #+#             */
/*   Updated: 2025/01/07 13:26:25 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int index, int value)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof (t_list));
	if (new == NULL)
		return (NULL);
	new->index = index;
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	if (lst)
		*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		p = ft_lstlast(*lst);
		p->next = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		i;

	if (!lst)
		return (0);
	p = lst;
	i = 0;
	while (p)
	{
		p = p->next;
		i++;
	}
	return (i);
}
