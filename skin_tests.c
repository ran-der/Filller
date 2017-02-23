/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skin_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 04:16:41 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/23 17:54:16 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			is_ennemi(char c, char pl)
{
	if (c == (pl == 'X' ? 'O' : 'X'))
		return (1);
	return (0);
}

int			is_atwall(t_coord pos, t_plateau p)
{
	if (!pos.x || !pos.y || pos.x == (p.size).x || pos.y == (p.size).y)
		return (1);
	return (0);
}

int			is_corner(t_coord pos, t_plateau p)
{
	if ((!pos.x && pos.y == (p.size).y) || (pos.x == (p.size).x && !pos.y ) || \
		(pos.x == (p.size).x && pos.y == (p.size).y) || (!pos.x && !pos.y))
		return (1);
	return (0);
}

int			is_inhole(t_coord p, t_plateau plt)
{ 
	int			i;

	i = -1;
	if (p.x + 1 < (plt.size).x && is_ennemi((plt.map)[p.y][p.x + 1], plt.pl))
		while (p.x - (++i) >= 0 && (plt.map)[p.y][p.x - i] != plt.pl)
			if (is_ennemi((plt.map)[p.y][p.x - i], plt.pl))
				return (1);
	i = -1;
	if (p.x > 0 && is_ennemi((plt.map)[p.y][p.x - 1], plt.pl))
		while (p.x + (++i) < (plt.size).x && (plt.map)[p.y][p.x + i] != plt.pl)
			if (is_ennemi((plt.map)[p.y][p.x + i], plt.pl))
				return (1);
	i = -1;
	if (p.y + 1 < (plt.size).y && is_ennemi((plt.map)[p.y + 1][p.x], plt.pl))
		while (p.y - (++i) >= 0 && (plt.map)[p.y - i][p.x] != plt.pl)
			if (is_ennemi((plt.map)[p.y - i][p.x], plt.pl))
				return (1);
	i = -1;
	if (p.y > 0 && is_ennemi((plt.map)[p.y - 1][p.x], plt.pl))
		while (p.y + (++i) < (plt.size).y && (plt.map)[p.y + i][p.x] != plt.pl)
			if (is_ennemi((plt.map)[p.y + i][p.x], plt.pl))
				return (1);
	return (0);
}
