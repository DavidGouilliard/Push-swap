/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:10:07 by dagouill          #+#    #+#             */
/*   Updated: 2025/01/07 15:40:59 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int				index;
	int				value;
	struct s_list	*next;
}	t_list;

void	ft_putstr_fd(char *s, int fd);
void	print_error(void);
void	error_malloc(t_list **begin);
void	atoi_error(t_list **begin);

int		push_swap(int ac, char **av);
t_list	*parse_arg(char **av);
int		ft_isdigit(int c);
int		ft_isspace(int c);
void	check_str(char **str);
int		ft_atoi(const char *str, int *i, t_list **begin);
int		count_words(char *str);

t_list	*ft_lstnew(int index, int value);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);

#endif
