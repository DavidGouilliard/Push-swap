/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:58:44 by dagouill          #+#    #+#             */
/*   Updated: 2025/01/15 17:40:05 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	write (fd, s, i);
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	atoi_error(t_list **begin)
{
	if (begin)
		ft_lstclear(begin);
	print_error();
}

int	count_words(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			count++;
			while (ft_isdigit(str[i]))
				i++;
		}
		else
			i++;
	}
	return (count);
}

int	check_double(t_list *begin)
{
	t_list	*p;

	while (begin != NULL)
	{
		p = begin->next;
		while (p != NULL)
		{
			if (p->value == begin->value)
				return (1);
			p = p->next;
		}
		begin = begin->next;
	}
	return (0);
}
