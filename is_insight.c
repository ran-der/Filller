/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_insight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 02:19:44 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/22 18:30:07 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coord		check_part(t_coord start, t_plateau p, t_args *ag)
{
	t_coord		ret;

	ret.x = -3;
	while (*(ag->c) != ag->limc)
	{
		*(ag->l) = (ag->c == &(ag->y) ? start.x : start.y);
		while (*(ag->l) != ag->liml && !is_ennemi((p.map)[ag->y][ag->x], p.pl))
		{
			if ((p.map)[ag->y][ag->x] == p.pl && (ret.x = -1))
				return (ret);
			*(ag->l) += ag->dl;
		}
		if (ret.x == -3 && *(ag->l) == ag->liml)
		{
			*(ag->l) -= ag->dl;
			ret.x = ag->x;
			ret.y = ag->y;
		}
		if ((*(ag->l) == ag->liml - ag->dl || *(ag->c) == ag->limc - ag->dc)\
			&& is_ennemi((p.map)[ag->y][ag->x], p.pl) && (ret.x = -2))
			return (ret);
		*(ag->c) += ag->dc;
	}
	return (ret);
}

void		set_args(t_args *ag, t_dir cdir, t_dir ldir, t_plateau p)
{
	ag->dc = (cdir == E || cdir == S ? 1 : -1);
	ag->dl = (ldir == E || ldir == S ? 1 : -1);
	ag->c = (cdir == N || cdir == S ? &(ag->y) : &(ag->x));
	ag->l = (ag->c == &(ag->y) ? &(ag->x) : &(ag->y));
	ag->limc = -1;
	ag->liml = -1;
	if (cdir == S || cdir == E)
		ag->limc = (cdir == S ? (p.size).y : (p.size).x);
	if (ldir == S || ldir == E)
		ag->limc = (cdir == S ? (p.size).y : (p.size).x);
}

int			is_insight(t_skin pnt, t_plateau p)
{
	t_dir		cdir;
	t_dir		ldir;
	t_args		args;
	t_coord		start;

	start = pnt.crd;
	cdir = get_cdir(pnt, p.size);
	ldir = get_ldir(pnt, cdir);
	set_args(&args, cdir, ldir, p);
	args.x = (pnt.crd).x;
	args.y = (pnt.crd).y;
	while ((start = check_part(start, p, &args)).x >= 0)
	{
		cdir = invert_dir(cdir);
		ldir = invert_dir(ldir);
		set_args(&args, cdir, ldir, p);
	}
	return (start.x == -1 ? 1 : 0);
}
