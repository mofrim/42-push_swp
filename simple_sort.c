/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:00:25 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/19 17:55:20 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

// FIXME: so far only here for debugging...
#include "libft/libft.h"

// Push everything to b. than find highest number in b, move to top in b and
// pa. again, again, again. this would be for 4 numbers:
// or.... find lowest number in a, rotate to top, pb, find lowest number in b
// again, rotate to top, pb, until to elems remain in a, if first > than last,
// sa, then pa, pa, pa

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

void	simple_sort(t_stacks **sts)
{
	int	i;

	while ((*sts)->a->size > 2)
	{
		i = get_min_indx((*sts)->a);
		while (i-- > 0)
		{
			ft_printf("ra\n");
			ra(sts);
		}
		ft_printf("pb\n");
		pb(sts);
	}
	ft_printf("sa");
	sa(sts);
	while ((*sts)->b->size)
	{
		ft_printf("\npa");
		pa(sts);
	}
}

/* First improvement: if imin > a.size/2 use rra. */
void	simple_sort2(t_stacks **sts)
{
	int	i;

	while ((*sts)->a->size > 2)
	{
		i = get_min_indx((*sts)->a);
		if (i >= (*sts)->a->size / 2)
			while ((*sts)->a->size - i++ > 0)
			{
				ft_printf("rra\n");
				rra(sts);
			}
		else
			while (i-- > 0)
			{
				ft_printf("ra\n");
				ra(sts);
			}
		ft_printf("pb\n");
		pb(sts);
	}
	ft_printf("sa");
	sa(sts);
	while ((*sts)->b->size)
	{
		ft_printf("\npa");
		pa(sts);
	}
}


/* only compare up to s[size-1] element */
int	find_imax(t_stack *s, int size)
{
	int	i;
	int	max;
	int	imax;

	if (!s->size)
		return (-1);
	i = 0;
	max = s->st[0];
	imax = 0;
	while (i < size)
	{
		if (max < s->st[i])
		{
			max = s->st[i];
			imax = i;
		}
		i++;
	}
	// ft_printf("imax = %d\n", imax);
	return (imax);
}

// FIXME: make this one func with min_to_top
int	bring_max_to_top(t_stacks **sts)
{
	int	i;
	int	ops;

	// ft_printf("bring max to top\n");
	i = find_imax((*sts)->b, (*sts)->b->size);
	ops = 0;
	if (i >= (*sts)->b->size / 2)
		while ((*sts)->b->size - i++ > 0)
			ops += rrb_print(sts);
	else
		while (i-- > 0)
			ops += rb_print(sts);
	return (ops);
}

// FIXME: make this one func with max_to_top
int	bring_min_to_top(t_stacks **sts)
{
	int	i;
	int	ops;

	ops = 0;
	i = get_min_indx((*sts)->a);
	if (i >= (*sts)->a->size / 2)
		while ((*sts)->a->size - i++ > 0)
			ops += rra_print(sts);
	else
		while (i-- > 0)
			ops += ra_print(sts);
	return (ops);
}
