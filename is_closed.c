/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 19:38:09 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/11 21:03:44 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_closed2(t_plateau p, t_ennemi e)
{
	int		x;
	int		y;

	x = (e.sqr).e + 1;
	while (--x > (e.sqr).w - 1)
	{
		y = (p.size).y;
		while (--y > -1 && (p.map)[y][x] != p.pl)
			if (is_ennemi((p.map)[y][x], p.pl))
				return (0);
	}
	y = (e.sqr).s + 1;
	while (--y > (e.sqr).n - 1)
	{
		x = -1;
		while (++x < (p.size).x && (p.map)[y][x] != p.pl)
			if (is_ennemi((p.map)[y][x], p.pl))
				return (0);
	}
	return (1);
}

int		is_closed(t_plateau p, t_ennemi e)
{
	int		x;
	int		y;

	x = (e.sqr).w - 1;
	while (++x < (e.sqr).e + 1)
	{
		y = -1;
		while (++y < (p.size).y && (p.map)[y][x] != p.pl)
			if (is_ennemi((p.map)[y][x], p.pl))
				return (0);
	}
	y = (e.sqr).n - 1;
	while (++y < (e.sqr).s + 1)
	{
		x = (p.size).x;
		while (--x > -1 && (p.map)[y][x] != pl)
			if (is_ennemi((p.map)[y][x], p.pl))
				return (0);
	}
	return (is_closed2(p));
}
