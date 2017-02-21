/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:16:59 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/21 12:54:00 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			get_square2(t_square *sqr, t_plateau p)
{
	int			x;
	int			y;
	int			found;

	sqr->e = 0;
	found = 0;
	y = (p.size).y;
	while (--y != -1)
	{
		x = (p.size).x - 1;
		while (x != -1 && !is_ennemi((p.map)[y][x], p.pl))
			x--;
		if (!found && x != -1)
			sqr->s = y;
		else if (x != -1 && x > sqr->e)
			sqr->e = x;
		found = (!found && x == -1 ? 0 : 1);
	}
}

t_square		get_square(t_plateau p)
{
	t_square	sqr;
	int			x;
	int			y;
	int			found;

	sqr.w = (p.size).x - 1;
	found = 0;
	y = -1;
	while (++y < (p.size).y)
	{
		x = 0;
		while (x < (p.size).x && !is_ennemi((p.map)[y][x], p.pl))
			x++;
		if (!found && x != (p.size).x)
			sqr.n = y;
		else if (x != (p.size).x && x < sqr.w)
			sqr.w = x;
		found = (!found && x == (p.size).x ? 0 : 1);
	}
	get_square2(&sqr, p);
	return (sqr);
}
