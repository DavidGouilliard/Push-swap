/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:15:47 by dagouill          #+#    #+#             */
/*   Updated: 2025/01/07 16:36:46 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_malloc(t_list **begin)
{
	ft_lstclear(begin);
	exit(1);
}

void	append_list(int count, t_list **begin, t_list *node)
{
	if (count == 0)
		*begin = node;
	if (count > 0)
		ft_lstadd_back(begin, node);
}

t_list	*fill_list(char **av, t_list *node, t_list *begin)
{
	int	i;
	int	j;
	int	count;
	int	words;

	i = 1;
	count = 0;
	words = 0;
	while (av[i])
	{
		j = 0;
		words += count_words(av[i]);
		while (av[i][j] && count < words)
		{
			node = ft_lstnew(count, (int )ft_atoi(av[i], &j, &begin));
			if (node == NULL)
				error_malloc(&begin);
			append_list(count, &begin, node);
			count++;
		}
		i++;
	}
	return (begin);
}

t_list	*parse_arg(char **av)
{
	t_list	*node;
	t_list	*begin;

	node = NULL;
	begin = NULL;
	check_str(av);
	begin = fill_list(av, node, begin);
	if (begin == NULL)
		exit(1);
	if (check_double(begin))
		atoi_error(&begin);
	return (begin);
}
