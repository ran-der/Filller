/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_insight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:49:28 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/20 20:24:00 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_args(t_skin pos, t_plateau p, t_args *ag)
{
	ag->limc = (pos.dir == N || pos.dir == St ? (p.size).x : (p.size).y);
	ag->liml = -1;
	if (pos.dir == N || pos.dir == W)
		ag->liml = (ag->limc == (p.size).x ? (p.size).y : (p.size).x);
	ag->dl = (ag->liml == -1 ? -1 : 1);
	if (pos.dir == N || pos.dir == St)
	{
		(ag->pnt).x = (pos.crd).x;
		(ag->pnt).y = (pos.dir == N ? 0 : (p.size).y - 1);
		while ((ag->pnt).x >= 0 && \
				!is_ennemi((p.map)[(ag->pnt).y + ag->dl][(ag->pnt).x], p.pl))
			((ag->pnt).x)--;
	}
	else
	{
		(ag->pnt).x = (pos.dir == W ? 0 : (p.size).x - 1);
		(ag->pnt).y = (pos.crd).y;
		while ((ag->pnt).y >= 0 && \
				!is_ennemi((p.map)[(ag->pnt).y] [(ag->pnt).x + ag->dl], p.pl))
			((ag->pnt).y)--;
	}
	(ag->c) = (pos.dir == N || pos.dir == St ? &((ag->pnt).x) : &((ag->pnt).y));
	(ag->l) = ((ag->c) == &((ag->pnt).y) ? &((ag->pnt).x) : &((ag->pnt).y));
}

int		check_first(t_skin pos, t_plateau p)
{
	while (pos.dir == St && ++((pos.crd).y) < (p.size).y)
		if ((p.map)[(pos.crd).y][(pos.crd).x] != '.')
			return ((p.map)[(pos.crd).y][(pos.crd).x] == p.pl ? 1 : 2);
	while (pos.dir == N && --((pos.crd).y) >= 0)
		if ((p.map)[(pos.crd).y][(pos.crd).x] != '.')
			return ((p.map)[(pos.crd).y][(pos.crd).x] == p.pl ? 1 : 2);
	while (pos.dir == E && ++((pos.crd).x) < (p.size).x)
		if ((p.map)[(pos.crd).y][(pos.crd).x] != '.')
			return ((p.map)[(pos.crd).y][(pos.crd).x] == p.pl ? 1 : 2);
	while (pos.dir == W && --((pos.crd).x) >= 0)
		if ((p.map)[(pos.crd).y][(pos.crd).x] != '.')
			return ((p.map)[(pos.crd).y][(pos.crd).x] == p.pl ? 1 : 2);
	return (0);
}

int		is_insight(t_skin pos, t_plateau p)
{
	t_args		ag;
	int			i;
	int			c;

	if ((c = check_first(pos, p)) > 0)
		return (c == 1 ? 1 : 0);
	set_args(pos, p, &ag);
	while (++(*(ag.c)) != ag.limc && \
			!is_ennemi((p.map)[(ag.pnt).y][(ag.pnt).x], p.pl))
	{
		*(ag.l) -= ag.dl;
		i = 0;
		while ((*(ag.l) += ag.dl) != ag.liml && \
				!is_ennemi((p.map)[(ag.pnt).y][(ag.pnt).x], p.pl))
		{
			if (is_inlist((ag.pnt).x, (ag.pnt).y, p.pos))
				return (1);
			i += ag.dl;
		}
		*(ag.l) -= i;;
	}
	return (0);
}
