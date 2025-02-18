/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:10:07 by dagouill          #+#    #+#             */
/*   Updated: 2025/02/14 03:42:06 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_list
{
	int				index;
	int				value;
	int				target;
	int				cost;
	bool			above_m;

	struct s_list	*next;
}	t_list;

void	ft_putstr_fd(char *s, int fd);
void	print_error(void);
void	error_malloc(t_list **begin);
void	atoi_error(t_list **begin);
int		check_double(t_list *begin);

int		push_swap(int ac, char **av);
t_list	*parse_arg(char **av);
int		ft_isdigit(int c);
int		ft_isspace(int c);
void	check_str(char **str);
int		ft_atoi(const char *str, int *i, t_list **begin);
int		count_words(char *str);

t_list	*ft_lstnew(int index, int value);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list **lst);
void	ft_lstclear(t_list **lst);

void	swap(t_list **stack);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_ab(t_list **stack_a, t_list **stack_b);

void	update_index(t_list **stack);
void	push(t_list **stack1, t_list **stack2);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);

void	rotate(t_list **stack);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_ab(t_list **stack_a, t_list **stack_b);

void	rev_rotate(t_list **stack);
void	rev_rotate_a(t_list **stack_a);
void	rev_rotate_b(t_list **stack_b);
void	rev_rotate_ab(t_list **stack_a, t_list **stack_b);

void	choose_sort(t_list **stack_a, t_list **stack_b);
void	sort_two(t_list **stack_a);
void	sort_three(t_list **stack_a);
void	sort_four(t_list **stack_a, t_list **stack_b);
int		check_sorted(t_list **stack_a);

int		get_low(t_list **stack_a);
int		get_big(t_list **stack_a);

void	greedy_sort(t_list **stack_a, t_list **stack_b, int size);

void	set_target_a(t_list **stack_a, t_list **stack_b);
void	set_target_b(t_list **stack_a, t_list **stack_b);

int		find_cost(t_list **p, t_list **stack1, t_list **stack2);
void	set_cost(t_list **stack1, t_list **stack2);

t_list	*set_to_push(t_list **stack);
t_list	*get_target(t_list **p, t_list **stack);

void	rot_target_a(t_list **stack_a, t_list *t);
void	rot_target_b(t_list **stack_b, t_list *t);
void	push_opp_a(t_list **stack_a, t_list **stack_b, t_list *p, t_list *t);
void	push_opp_b(t_list **stack_a, t_list **stack_b, t_list *p, t_list *t);

void	to_push_a(t_list **stack_a, t_list **stack_b);
void	to_push_b(t_list **stack_a, t_list **stack_b);

void	min_on_top(t_list **stack_a);

#endif
