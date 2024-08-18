/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:35:30 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/18 19:20:07 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWP_H
# define PUSH_SWP_H

#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_stack
{
	long	*st;
	int		*dsts;
	long	*sortd;
	int		size;
}	t_stack;

/* cur_min: the index in sortd-array of current minimal value. */
typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	long	*sortd;
	int		initial_size;
	int		cur_min;
}	t_stacks;

t_stacks	*init_stacks(int size);
t_stacks	*init_stacks_rand(int size, int seed);
t_stacks	*init_stacks_empty(int size);
void		fill_stack_rand(t_stacks **st, unsigned int seed);
void		fill_stack_rev(t_stacks **st);
void		free_stacks(t_stacks **st);
void		print_stacks(t_stacks *st);

void		simple_sort(t_stacks **sts);
void		simple_sort2(t_stacks **sts);
void		swap_sort(t_stacks **sts);
void		bring_min_to_top(t_stacks **sts);
void		bring_max_to_top(t_stacks **sts, int size);

void		quicksort(long **arr, int low, int high);
long		*quicksorted_stack(long *arr, int size);
int			get_index_sorted(long num, long *sorted_stack, int size);
void		move_to_top_next(t_stacks **sts, long *ss, long xi, int stack_size);

/* Operations. */
int			sa(t_stacks **st);
int			sb(t_stacks **st);
int			ss(t_stacks **st);
int			pa(t_stacks **st);
int			pb(t_stacks **st);
int			ra(t_stacks **st);
int			rb(t_stacks **st);
int			rr(t_stacks **st);
int			rra(t_stacks **st);
int			rrb(t_stacks **st);
int			rrr(t_stacks **st);

/* Ops with printing. */
int		sa_print(t_stacks **st);
int		sb_print(t_stacks **st);
int		ss_print(t_stacks **st);
int		pa_print(t_stacks **st);
int		pb_print(t_stacks **st);
int		ra_print(t_stacks **st);
int		rb_print(t_stacks **st);
int		rr_print(t_stacks **st);
int		rra_print(t_stacks **st);
int		rrb_print(t_stacks **st);
int		rrr_print(t_stacks **st);

/* stratsort. */
int			stratsort(t_stacks **sts);
t_stacks	*stacks_dup(t_stacks *orig);
int			sort2(t_stacks **sts);
int			sort3(t_stacks **sts);
int			simulate_strats(t_stacks **sts);
int			strat31_sim(t_stacks *sts);
int			strat32_sim(t_stacks *sts);
int			strat33_sim(t_stacks *sts);
int			strat1_do(t_stacks **sts);
int			strat2_do(t_stacks **sts);
int			strat3_do(t_stacks **sts);
int			move_top_min(t_stacks **sts, int min_offset);
int 		move_top_min_print(t_stacks **sts, int min_offset);
int			indexof(long num, long *arr);


/* distsort. */
void	print_dists_stack(t_stacks *sts);
int		calc_total_dist(long *a, long *sortd, int size);
int		*get_dists_array(long *a, long *sortd, int size);
int		optimize_dists_rot(t_stacks **sts);
int		indexof_int(int num, int *arr);
int		indexof_long(long num, long *arr, int size);

/* experimental. */
int			strat_optimized(t_stacks **sts);
int			optimize_dists_rot_inv(t_stacks **sts);
int			pushb_smaller_half(t_stacks **sts);
void	set_stacka_dsts(t_stack **st, int size);
void	set_stackb_dsts(t_stack **st, int size);
void	print_dsts(t_stacks *sts);
long	ft_abs(long num);
void	free_ptr(void **p);
int		get_min_indx(t_stack *s);
void	swap_sort_single(t_stacks **sts);

#endif 
