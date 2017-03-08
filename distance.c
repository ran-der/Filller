/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 05:34:05 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/27 16:32:48 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

double		sqroot(double nb)
{
	double		min;
	double		max;
	double		res;

	res = (nb < 2 ? nb : nb / 2);
	if (nb >= 1)
	{
		max = res;
		min = 1;
		while (res * res != nb && (max - min) >= 0.001)
		{
			if (res * res > nb)
			{
				max = res;
				res = min + ((max - min) / 2);
			}
			else
			{
				min = res;
				res = min + ((max - min) / 2);
			}
		}
	}
	return (res);
}

double		distance_2d(t_coord p1, t_coord p2)
{
	int			dx;
	int			dy;

	dx = p1.x - p2.x;
	dx = (dx < 0 ? -dx : dx);
	dy = p1.y - p2.y;
	dy = (dy < 0 ? -dy : dy);
	return (sqroot((double)(dx * dx + dy * dy)));
}

double		dmin_to_coord(t_coord pnt, t_coord *grp)
{
	double		dmin;
	double		tmp;

	dmin = 0;
	if (grp != NULL)
	{
		dmin = distance_2d(*grp, pnt);
		grp = grp->next;
		while (grp != NULL && (tmp = distance_2d(*grp, pnt)))
		{
			dmin = (tmp < dmin ? tmp : dmin);
			grp = grp->next;
		}
		dmin = (grp != NULL ? 0 : dmin);
	}
	return (dmin);
}

double		dmin_to_skin(t_coord pnt, t_skin *grp)
{
	double		dmin;
	double		tmp;
	t_skin		*tmps;

	dmin = 0;
	if ((tmps = grp) != NULL)
	{
		dmin = distance_2d(tmps->crd, pnt);
		tmps = tmps->next;
		while (tmps != NULL && tmps != grp && \
				(tmp = distance_2d(grp->crd, pnt)))
		{
			dmin = (tmp < dmin ? tmp : dmin);
			tmps = tmps->next;
		}
		dmin = (tmps != NULL && tmps != grp ? 0 : dmin);
	}
	return (dmin);
}

int			dmin_to_wall(t_coord pnt, t_plateau p)
{
	int			dmin;
	int			tmp;

	tmp = (p.size).x - pnt.x - 1;
	dmin = (pnt.x > tmp ? tmp : pnt.x);
	tmp = (p.size).y - pnt.y - 1;
	dmin = (dmin < tmp ? dmin : tmp);
	dmin = (dmin < pnt.y ? dmin : pnt.y);
	return (dmin);
}
