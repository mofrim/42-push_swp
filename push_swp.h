/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:35:30 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/11 19:14:53 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWP_H
# define PUSH_SWP_H

typedef struct s_stack
{
	long	*st;
	int		size;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	int		initial_size;
}	t_stacks;


t_stacks	*init_stacks(int size);
void	fill_stack_rand(t_stacks **st, unsigned int seed);
void	fill_stack_rev(t_stacks **st);
void	free_stacks(t_stacks **st);
void	print_stacks(t_stacks *st);
void	simple_sort(t_stacks **sts);

/* Operations */
void	sa(t_stacks **st);
void	sb(t_stacks **st);
void	ss(t_stacks **st);
void	pa(t_stacks **st);
void	pb(t_stacks **st);
void	ra(t_stacks **st);
void	rb(t_stacks **st);
void	rr(t_stacks **st);
void	rra(t_stacks **st);
void	rrr(t_stacks **st);

#endif 

