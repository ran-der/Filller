/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surface.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:52:45 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/19 19:30:19 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			is_surface2(t_coord p, t_plateau plt, int sides, int lim)
{
	int			i;

	i = 0;
	while ((p.x + i) < (plt.size).x && i <= lim && \
			!is_ennemi((plt.map)[p.y][p.x + i], plt.pl))
		i++;
	if ((p.x + i) < (plt.size).x && i <= lim)
		sides++;
	i = 0;
	while ((p.x - i) >= 0 && i <= lim && \
			!is_ennemi((plt.map)[p.y][p.x - i], plt.pl))
		i++;
	if ((p.x - i) >= 0 && i <= lim)
		sides++;
	return (sides == 1 ? 1 : 0);
}

int			is_surface(t_coord p, t_plateau plt)
{
	int			i;
	int			sides;
	int			lim;

	lim = (MAX((plt.size).x, (plt.size).y)) / 6;
	lim = (lim < 2 ? 2 : lim);
	sides = 0;
	i = 0;
	while ((p.y + i) < (plt.size).y && i <= lim && \
			!is_ennemi((plt.map)[p.y + i][p.x], plt.pl))
		i++;
	if ((p.y + i) < (plt.size).y && i <= lim)
		sides++;
	i = 0;
	while ((p.y - i) >= 0 && i <= lim && \
			!is_ennemi((plt.map)[p.y - i][p.x], plt.pl))
		i++;
	if ((p.y - i) >= 0 && i <= lim)
		sides++;
	return (is_surface2(p, plt, sides, lim));
}
