/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:29:28 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/14 14:54:50 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_node
{
	struct s_node	*p_next;
	struct s_node	*p_prev;
	struct s_node	*target;
	int				data;
	int				index;
	int				is_in_upper_half;
	int				is_in_lower_half;
	int				cost;
	int				cost_in_a;
	int				cost_in_b;
	int				target_data;
}	t_node;

typedef struct s_dlist
{
	int		is_sorted;
	int		is_reverse_sorted;
	size_t	dlst_len;
	t_node	*p_head;
	t_node	*p_tail;
}	t_dlist;

void	ft_errorlist(t_dlist **dlst);
void	ft_error(void);
void	ft_dlstfree(t_dlist **dlst);
void	ft_dlstadd_front(t_dlist *dlst, int data);
void	ft_dlstadd_back(t_dlist *dlst, int data);
void	ft_deallocate(char **array, int i);
void	ft_checknumber(const char *number, int is_negative);
void	checklist_string_helper(const char *str, int *i);
void	ft_checkinput(int argc, char *argv[]);
void	ft_checklist_string(const char *str);

int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_isdigit(char c);
int		ft_isspace(char c);
int		ft_isminus(char c);
int		ft_isnumber(char c);
int		ft_max(int n1, int n2);
int		ft_min(int n1, int n2);
int		ft_atoi(const char *str);
int		ft_is_empty_stack(t_dlist *stack);
int		ft_is_sorted_stack(t_dlist *stack);
int		ft_get_max_index(int *tab);
int		ft_get_min_index(int *tab);

size_t	ft_strlen(const char *str);
size_t	ft_nbrlen(const char *str);
size_t	ft_strncpy(char *dst, const char *src, size_t n);
size_t	ft_nbrlen_v2(const char **str);

void	ft_nbrchr(const char *str, char **number);
void	ft_unicheck(const char *str);
void	ft_checksingle_arg(const char *str);
void	ft_checkall_arg(int argc, char *argv[]);
char	*ft_bust_zeroes_v2(const char *str);
char	*ft_bust_zeroes(const char *str);
char	*ft_nbrtr(const char *str);

void	ft_get_numbers(int argc, char *argv[], t_dlist *dlst);
void	ft_swap(t_dlist *dlst);
void	ft_push(t_dlist *stack_from, t_dlist *stack_to);
void	ft_rotate(t_dlist *stack);
void	ft_rrotate(t_dlist *stack);
void	ft_sa(t_dlist *stack_a);
void	ft_sb(t_dlist *stack_b);
void	ft_ss(t_dlist *stack_a, t_dlist *stack_b);
void	ft_pb(t_dlist *stack_a, t_dlist *stack_b);
void	ft_pa(t_dlist *stack_a, t_dlist *stack_b);
void	ft_ra(t_dlist *stack_a);
void	ft_rb(t_dlist *stack_b);
void	ft_rr(t_dlist *stack_a, t_dlist *stack_b);
void	ft_rra(t_dlist *stack_a);
void	ft_rrb(t_dlist *stack_b);
void	ft_rrr(t_dlist *stack_a, t_dlist *stack_b);
void	ft_supersmartsort_v4(t_dlist *a, t_dlist *b);
void	ft_rotate_stacks_helper(t_dlist *a, t_dlist *b, t_node *cheapest);
void	ft_rotate_stacks(t_dlist *a, t_dlist *b, t_node *cheapest);
void	ft_set_index(t_dlist *stack);
void	ft_get_target_node(t_dlist *a, t_node *node_b);
void	ft_set_target_node(t_dlist *a, t_dlist *b);
void	ft_set_cost_in_a(t_dlist *a, t_node *node);
void	ft_set_cost_in_b(t_dlist *b, t_node *node);
void	ft_set_cost(t_dlist *a, t_dlist *b);
void	ft_finish_rotating(t_dlist *stack, int \
*cost_in_stack, void (*f)(t_dlist *));
void	ft_empty_b(t_dlist *a, t_dlist *b);
void	ft_push_everybody_in_b(t_dlist *a, t_dlist *b);
void	ft_sort_a(t_dlist *a);
void	ft_size_2_solver(t_dlist *stack);
void	ft_size_3_solver(t_dlist *a);
void	ft_3_solver_helper(t_dlist *a);

t_node	*ft_get_min(t_dlist *a);
t_node	*ft_get_max(t_dlist *a);
t_node	*ft_get_cheapest(t_dlist *b);

t_dlist	*ft_dlstnew(void);

char	**ft_split(char const *s, char c);

long	ft_atol(const char *str);
#endif
