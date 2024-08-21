/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 00:35:34 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/22 00:39:00 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

int	get_max_indx(t_stack *s)
{
	int	i;
	int	max;
	int	imax;

	if (!s->size)
		return (-1);
	i = 0;
	max = s->st[0];
	imax = 0;
	while (i < s->size)
	{
		if (max < s->st[i])
		{
			max = s->st[i];
			imax = i;
		}
		i++;
	}
	return (imax);
}

int	get_min_indx(t_stack *s)
{
	int	i;
	int	min;
	int	imin;

	if (!s->size)
		return (-1);
	i = 0;
	min = s->st[0];
	imin = 0;
	while (i < s->size)
	{
		if (min > s->st[i])
		{
			min = s->st[i];
			imin = i;
		}
		i++;
	}
	return (imin);
}

long	get_stack_max(t_stack *stck)
{
	int	i;
	int	max;

	max = INT_MIN;
	i = -1;
	while (++i < stck->size)
		if (stck->st[i] > max)
			max = stck->st[i];
	return (max);
}
