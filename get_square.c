/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:16:59 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/27 16:39:43 by rvan-der         ###   ########.fr       */
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
		if (!found && x != -1 && (found = 1))
			sqr->s = y;
		if (x > sqr->e)
			sqr->e = x;
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
		if (!found && x != (p.size).x && (found = 1))
			sqr.n = y;
		if (x < sqr.w)
			sqr.w = x;
	}
	get_square2(&sqr, p);
	return (sqr);
}
