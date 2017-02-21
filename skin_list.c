/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skinlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:25:50 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/21 12:41:58 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_mark		find_mark(t_coord pnt, t_dir dir, t_plateau p)
{
	int			i;
	int			lim;

	lim = MIN((p.size).x, (p.size).y) / 10;
	lim = (lim < 2 ? 2 : lim);
	i = -1;
	while (++i < lim)
	{
		if (dir == N && pnt.y - i >= 0 && (p.map)[pnt.y - i][pnt.x] == p.pl)
			return (!pnt.x || pnt.x == (p.size).x - 1 ? atwallo : ocp);
		if (dir == St && pnt.y + i < (p.size).y && \
			(p.map)[pnt.y + i][pnt.x] == p.pl)
			return (!pnt.x || pnt.x == (p.size).x - 1 ? atwallo : ocp);
		if (dir == W && pnt.x - i >= 0 && (p.map)[pnt.y][pnt.x - i] == p.pl)
			return (!pnt.y || pnt.y == (p.size).y - 1 ? atwallo : ocp);
		if (dir == E && pnt.x + i < (p.size).x - 1 && \
			(p.map)[pnt.y][pnt.x + i] == p.pl)
			return (!pnt.y || pnt.y == (p.size).y - 1 ? atwallo : ocp);
	}
	return (is_atwall(pnt, p) ? atwallf : fre);
}

t_dir		corner_dir(t_skin new, t_plateau p)
{
	if (!(new.crd).x && !(new.crd).y)
		return (new.dir == E ? N : W);
	if (!(new.crd).x && (new.crd).y == (p.size).y - 1)
		return (new.dir == E ? St : W);
	if (!(new.crd).y && (new.crd).x == (p.size).x - 1)
		return (new.dir == W ? N : E);
	return (new.dir == W ? St : E);
}

t_skin		*new_skin_pnt(t_coord pnt, t_plateau p)
{
	t_skin		*new;

	if ((new = (t_skin*)malloc(sizeof(t_skin))) == NULL)
		return (NULL);
	new->prev = NULL;
	new->next = NULL;
	(new->crd).x = pnt.x;
	(new->crd).y = pnt.y;
	new->dir = find_dir(pnt, p);
	new->mark = find_mark(pnt, new->dir, p);
	if (is_corner(new->crd, p))
		new->dir = corner_dir(*new, p);
	if (!is_insight(*new, p))
	{
		free(new);
		return (NULL);
	}
	return (new);
}

void		skin_pushback(t_skin **skin, t_coord pnt, t_plateau p)
{
	t_skin		*tmp;
	t_skin		*new;

	if ((new = new_skin_pnt(pnt, p)) != NULL)
	{
		tmp = *skin;
		while (tmp != NULL && tmp->next != NULL)
			tmp = tmp->next;
		new->prev = tmp;
		if (tmp != NULL)
			tmp->next = new;
		else
			*skin = new;
	}
}
