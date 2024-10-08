/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_convert_p_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:55:54 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/05 19:36:48 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_left_padded(unsigned long p, t_flags *fl);

static int	print_right_padded(unsigned long p, t_flags *fl);

/* Convert mem adress. */
int	ftpr_compl_converter_p(unsigned long p, t_flags *fl)
{
	int	r;

	r = 0;
	if (!fl->minus && fl->width)
		r = print_left_padded(p, fl);
	else if (fl->minus)
		r = print_right_padded(p, fl);
	else
		return (ftpr_converter_p(p));
	return (r);
}

/* Helper function. Print left padded. */
static int	print_left_padded(unsigned long p, t_flags *fl)
{
	int		i;
	int		len;

	len = (p != 0) * (ftpr_hex_digits(p) + 2) + (!p) * 5;
	i = -1;
	if (fl->width > len)
		while (++i < fl->width - len)
			ft_putchar(' ');
	ftpr_converter_p(p);
	if (fl->width >= len)
		return (fl->width);
	return (len);
}

/* Helper function. Print right padded. */
static int	print_right_padded(unsigned long p, t_flags *fl)
{
	int		i;
	int		len;

	len = (p != 0) * (ftpr_hex_digits(p) + 2) + (!p) * 5;
	i = -1;
	ftpr_converter_p(p);
	if (fl->width > len)
		while (++i < fl->width - len)
			ft_putchar(' ');
	if (fl->width >= len)
		return (fl->width);
	return (len);
}
