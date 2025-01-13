/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:41:15 by dagouill          #+#    #+#             */
/*   Updated: 2025/01/07 16:54:17 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_issign(int c)
{
	if (c == '-' || c == '+')
		return (1);
	else
		return (0);
}

void	check_str(char **str)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) && !ft_isspace(str[i][j])
				&& !ft_issign(str[i][j]))
				print_error();
			if (ft_isdigit(str[i][j]) && count == 0)
				count++;
			j++;
		}
	i++;
	}
	if (count == 0)
		print_error();
}

int	ft_atoi(const char *str, int *i, t_list **begin)
{
	long long	res;
	long long	sign;

	res = 0;
	sign = 1;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		++*i;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign *= -1;
		++*i;
	}
	if (!ft_isdigit(str[*i]))
		atoi_error(begin);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		res = res * 10 + str[*i] - '0';
		++*i;
	}
	res = res * sign;
	if (res < INT_MIN || res > INT_MAX)
		atoi_error(begin);
	return ((int)res);
}
