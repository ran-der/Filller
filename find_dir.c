/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 20:34:02 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/20 20:21:57 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_dir		find_dir2(t_coord pnt, t_plateau p)
{
	if (!pnt.x)
	{
		if (!is_ennemi((p.map)[pnt.y][pnt.x + 1], p.pl))
			return (is_ennemi((p.map)[pnt.y + 1][pnt.x], p.pl) ? N : St);
		return (W);
	}
	else if (pnt.x == (p.size).x - 1)
	{
		if (!is_ennemi((p.map)[pnt.y][pnt.x - 1], p.pl))
			return (is_ennemi((p.map)[pnt.y + 1][pnt.x], p.pl) ? N : St);
		return (E);
	}
	else if (is_ennemi((p.map)[pnt.y + 1][pnt.x], p.pl))
		return (N);
	else if (is_ennemi((p.map)[pnt.y - 1][pnt.x], p.pl))
		return (St);
	else if (is_ennemi((p.map)[pnt.y][pnt.x + 1], p.pl))
		return (W);
	return (E);
}

t_dir		find_dir(t_coord pnt, t_plateau p)
{
	if (pnt.y == (p.size).y - 1)
	{
		if (!pnt.x)
			return (is_ennemi((p.map)[pnt.y - 1][0], p.pl) ? E : N);
		if (pnt.x == (p.size).x - 1)
			return (is_ennemi((p.map)[pnt.y - 1][pnt.x], p.pl) ? W : N);
		if (!is_ennemi((p.map)[pnt.y - 1][pnt.x], p.pl))
			return (is_ennemi((p.map)[pnt.y][pnt.x + 1], p.pl) ? W : E);
		return (St);
	}
	else if (!pnt.y)
	{
		if (!pnt.x)
			return (is_ennemi((p.map)[pnt.y + 1][0], p.pl) ? E : St);
		if (pnt.x == (p.size).x - 1)
			return (is_ennemi((p.map)[pnt.y + 1][pnt.x], p.pl) ? W : St);
		if (!is_ennemi((p.map)[pnt.y + 1][pnt.x], p.pl))
			return (is_ennemi((p.map)[pnt.y][pnt.x + 1], p.pl) ? W : E);
		return (N);
	}
	return (find_dir2(pnt, p));
}
