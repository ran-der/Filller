/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_area.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 18:32:00 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/20 19:26:46 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ennemi_coll(t_coord pos, t_plateau p)
{
	t_coord		*pc;
	int			ret;

	ret = 0;
	pc = (p.pce).crd;
	while (pc != NULL)
	{
		if ((pos.x + pc->x + 1 < (p.size).x && \
				is_ennemi((p.map)[pos.y + pc->y][pos.x + pc->x + 1], p.pl)) \
			|| (pos.x + pc->x - 1 >= 0 && \
				is_ennemi((p.map)[pos.y + pc->y][pos.x + pc->x - 1], p.pl)) \
			|| (pos.y + pc->y + 1 < (p.size).y && \
				is_ennemi((p.map)[pos.y + pc->y + 1][pos.x + pc->x], p.pl)) \
			|| (pos.y + pc->y - 1 >= 0 && \
				is_ennemi((p.map)[pos.y + pc->y - 1][pos.x + pc->x], p.pl)))
			ret++;
		pc = pc->next;
	}
	return (ret);
}

int			collisions(t_coord pos, t_plateau p)
{
	t_coord		*pc;
	int			ret;

	ret = 0;
	pc = (p.pce).crd;
	while (pc != NULL)
	{
		if ((pos.x + pc->x + 1 < (p.size).x && \
				(p.map)[pos.y + pc->y][pos.x + pc->x + 1] == p.pl) \
			|| (pos.x + pc->x - 1 >= 0 && \
				(p.map)[pos.y + pc->y][pos.x + pc->x - 1] == p.pl) \
			|| (pos.y + pc->y + 1 < (p.size).y && \
				(p.map)[pos.y + pc->y + 1][pos.x + pc->x] == p.pl) \
			|| (pos.y + pc->y - 1 >= 0 && \
				(p.map)[pos.y + pc->y - 1][pos.x + pc->x] == p.pl))
			ret++;
		pc = pc->next;
	}
	return (ret);
}

t_skin		fill_area(t_plateau p)
{
	t_skin		ret;
	t_coord		*tmp;
	t_coord		max;
	t_coord		coll;

	max.x = 0;
	max.y = 0;
	tmp = p.pos;
	while (tmp != NULL)
	{
		if (!max.x && (coll.y = collisions(*tmp, p)) > max.y)
		{
			max.y = coll.y;
			ret.crd = *tmp;
		}
		if ((coll.x = ennemi_coll(*tmp, p)) > max.x)
		{
			max.x = coll.x;
			ret.crd = *tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}
