/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skin_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 04:16:41 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/22 22:28:30 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			is_ennemi(char c, char pl)
{
	if (c == (pl == 'X' ? 'O' : 'X'))
		return (1);
	return (0);
}

int			is_surface2(t_coord p, t_plateau plt, int max, int sides)
{
	int		i;

	i = 0;
	while (p.x + i < (plt.size).x && i <= max && \
			!is_ennemi((plt.map)[p.y][p.x + i], plt.pl))
		i++;
	if (i != max + 1 && p.x + i != (plt.size).x)
		sides++;
	i = 0;
	while (p.x - i >= 0 && i <= max && \
			!is_ennemi((plt.map)[p.y][p.x - i], plt.pl))
		i++;
	if (i != max + 1 && p.x - i != -1)
		sides++;
	return (sides < 3 ? 1 : 0);
}

int			is_surface(t_coord p, t_plateau plt, int max)
{
	int			i;
	int			sides;

	sides = 0;
	i = 0;
	while (p.y + i < (plt.size).y && i <= max && \
			!is_ennemi((plt.map)[p.y + i][p.x], plt.pl))
		i++;
	if (i != max + 1 && p.y + i != (plt.size).y)
		sides++;
	i = 0;
	while (p.y - i >= 0 && i <= max && \
			!is_ennemi((plt.map)[p.y - i][p.x], plt.pl))
		i++;
	if (i != max + 1 && p.y - i != -1)
		sides++;
	return (is_surface2(p, plt, max, sides));
}

int			is_skinpnt(t_coord pnt, t_plateau *plt)
{
	char		**map;
	char		pl;
	t_coord		sz;

	pl = plt->pl;
	sz = plt->size;
	map = plt->map;
	if (pnt.y + 1 < sz.y && is_ennemi(map[pnt.y + 1][pnt.x], pl))
		return (is_surface(pnt, *plt, MAX(sz.x, sz.y) / 10));
	if (pnt.y - 1 >= 0 && is_ennemi(map[pnt.y - 1][pnt.x], pl))
		return (is_surface(pnt, *plt, MAX(sz.x, sz.y) / 10));
	if (pnt.x + 1 < sz.x && is_ennemi(map[pnt.y][pnt.x + 1], pl))
		return (is_surface(pnt, *plt, MAX(sz.x, sz.y) / 10));
	if (pnt.x - 1 >= 0 && is_ennemi(map[pnt.y][pnt.x - 1], pl))
		return (is_surface(pnt, *plt, MAX(sz.x, sz.y) / 10));
	return (0);
}
