/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 05:34:05 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/13 22:42:25 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

double		sqroot(double nb)
{
	double		min;
	double		max;
	double		res;

	res = nb;
	if (nb >= 1)
	{
		max = nb;
		min = 0;
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

	dx = ABS(p1.x - p2.x);
	dy = ABS(p1.y - p2.y);
	return (sqroot((double)(dx * dx + dy * dy)));
}

double		dmin_to_grp(t_coord pnt, t_coord *grp)
{
	double		dmin;
	double		tmp;

	dmin = 0;
	if (grp != NULL)
	{
		dmin = distance_2d(*grp, pnt);
		grp = grp->next;
		while (grp != NULL)
		{
			tmp = distance_2d(*grp, pnt);
			dmin = (tmp < dmin ? tmp : dmin);
			grp = grp->next;
		}
	}
	return (dmin);
}
