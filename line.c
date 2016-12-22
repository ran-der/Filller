/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:46:53 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/15 21:27:22 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_linex(t_plateau plt, t_coord p1, t_coord p2, double coef)
{
	e = p2

int		is_obstructed(t_plateau plt, t_coord p1, t_coord p2)
{
	double		coef;
	double		tmpy;
	double		tmpx;
	int			i;

	tmpx = (double)p1.x;
	tmpy = (double)p1.y;
	if (p1.x == p2.x && p1.y != p2.y)
		while ((tmpy += (tmpy < p2.y ? 1 : -1)) != (double)(p2.y))
			if ((plt.map)[(int)tmpy][p1.x] == (plt.pl == 'X' ? 'O' : 'X'))
				return (1);
	else if (p1.y == p2.y && p1.x != p2.x)
		while ((tmpx += (tmpx < p2.x ? 1 : -1)) != (double)(p2.x))
			if ((plt.map)[p1.y][(int)tmpx] == (plt.pl == 'X' ? 'O' : 'X'))
				return (1);
	else if (p1.x != p2.x && p1.y != p2.y)
	{
		coef = (double)(p2.y - p1.y) / (p2.x - p1.x)
		if (coef <= 1 && coef >= -1 && check_linex(plt, \
			(p1.x < p2.x ? p1 : p2), (p1.x < p2.x ? p2 : p1), coef))
			return (1);
		else if (check_liney(plt, (p1.y < p2.y ? p1 : p2), \
				(p1.y < p2.y ? p2 : p1), coef))
			return (1);
	return (0);
}
