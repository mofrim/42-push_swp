/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:35:26 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/19 13:04:25 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"
#include <stdlib.h>

/* I need a stacks_dup function to temporarily duplicate the stacks struct for
 * simulation. Also i want to have the sorted stack inside the stacks struct. */
t_stacks	*stacks_dup(t_stacks *orig)
{
	t_stacks	*dup;
	int			i;

	if (!orig)
		return (NULL);
	dup = init_stacks_empty(orig->initial_size);
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < dup->initial_size)
	{
		dup->a->st[i] = orig->a->st[i];
		dup->b->st[i] = orig->b->st[i];
		dup->sortd[i] = orig->sortd[i];
	}
	dup->a->size = orig->a->size;
	dup->b->size = orig->b->size;
	dup->cur_min = orig->cur_min;
	return (dup);
}

/* Return index of value `num` in array of longs `stack`. */
int	indexof_long(long num, long *arr, int size)
{
	int	i;

	i = 0;
	while (arr[i] != num && i < size)
		i++;
	return (i);
}

/* Will find **the first** index where arr[index] matches num. */
int	indexof_int(int num, int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != num)
		i++;
	return (i);
}

/* This function should move the element specified minimal element to top of
 * stack a. The minimal element of interest min, min+1, min+2 will be chosen
 * from the cur_min variable inside t_stacks struct which holds the index of the
 * current minimal value to be handled. For min+1 set min_offset to 1. The
 * corresponding index of this element in stack a will be found by
 * get_stack_index. Return value is the number of moves needed to move value of
 * interest to top of a. */
int move_top_min(t_stacks **sts, int min_offset)
{
	int	indx_a;
	int	indx_min;
	int	ops;

	indx_min = (*sts)->cur_min + min_offset;
	if (indx_min >= (*sts)->initial_size)
		return (-1);
	indx_a = indexof_long((*sts)->sortd[indx_min], (*sts)->a->st, (*sts)->initial_size);
	ops = 0;
	while ((*sts)->a->st[0] != (*sts)->sortd[indx_min])
	{
		if (indx_a < (*sts)->a->size - indx_a)
			ops += ra(sts);
		else
			ops += rra(sts);
	}
	return (ops);
}

/* The same func. This one just prints ops along the way. */
int move_top_min_print(t_stacks **sts, int min_offset)
{
	int	indx_a;
	int	indx_min;
	int	ops;

	indx_min = (*sts)->cur_min + min_offset;
	if (indx_min >= (*sts)->initial_size)
		return (-1);
	indx_a = indexof_long((*sts)->sortd[indx_min], (*sts)->a->st, (*sts)->a->size);
	ops = 0;
	while ((*sts)->a->st[0] != (*sts)->sortd[indx_min])
	{
		if (indx_a < (*sts)->a->size - indx_a)
			ops += ra_print(sts);
		else
			ops += rra_print(sts);
	}
	return (ops);
}

/*
 * Call the simulation functions for all 3 strats and return the strat num which
 * took the least ops.
 */
int	simulate_strats(t_stacks **sts)
{
	int s012;
	int s021;
	int s102;
	int s120;
	int s210;

	s012 = strat012_sim(*sts);
	s021 = strat021_sim(*sts);
	s102 = strat102_sim(*sts);
	s210 = strat210_sim(*sts);
	s120 = strat120_sim(*sts);

	if (s012 <= s102 && s012 <= s210 && s012 <= s021 && s012 <= s120)
		return (1);
	if (s102 <= s012 && s102 <= s210 && s102 <= s021 && s102 <= s120)
		return (2);
	if (s210 <= s012 && s210 <=s102 && s210 <= s021 && s210 <= s120)
		return (3);
	if (s021 <= s012 && s021 <=s102 && s021 <= s210 && s021 <= s120)
		return (4);
	if (s120 <= s012 && s120 <=s021 && s120 <= s102 && s120 <= s210)
		return (5);
	return (0);
}

/* Handles 2-elem stack_a. */
int	sort2(t_stacks **sts)
{
	int	ops;

	ops = 0;
	if ((*sts)->a->st[0] > (*sts)->a->st[1])
		ops += sa_print(sts);
	return (ops);
}
