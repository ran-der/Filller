/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:21:08 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/21 17:02:26 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coord		*get_valid_pos(t_skin target, t_plateau *p)
{
	t_coord		*ret;
	t_args		ag;
	int			i;

	ret = NULL;
	set_args(target, *p, &ag);
	while ((*(ag.c) += 1) != ag.limc && \
			!is_ennemi((p->map)[(ag.pnt).y][(ag.pnt).x], p->pl))
	{
		*(ag.l) -= ag.dl;
		i = 0;
		while ((*(ag.l) += ag.dl) != ag.liml && p->pos != NULL && \
				!is_ennemi((p->map)[(ag.pnt).y][(ag.pnt).x], p->pl))
		{
			if (is_inlist((ag.pnt).x, (ag.pnt).y, p->pos))
			{
				crdlist_pushback(&ret, new_crdlist((ag.pnt).x, (ag.pnt).y));
				delete_elem((ag.pnt).x, (ag.pnt).y, &(p->pos));
			}
			i += ag.dl;
		}
		*(ag.l) -= i;
	}
	return (ret);
}

int			ctr_occupied(t_plateau p)
{
	int		i;
	int		lim;

	lim = MAX((p.size).x, (p.size).y) / 10;
	i = -1;
	while (++i <= lim)
	{
		if ((p.map)[(p.ctr).y + i][(p.ctr).x] != '.' ||\
				(p.map)[(p.ctr).y - i][(p.ctr).x] != '.' ||\
				(p.map)[(p.ctr).y][(p.ctr).x + i] != '.' ||\
				(p.map)[(p.ctr).y][(p.ctr).x - i] != '.')
			return (1);
	}
	return (0);
}

t_skin		get_target(t_plateau p, t_ennemi e, int *ctr, int *turn)
{
	t_skin		center;

	if (e.skin == NULL)
		return (fill_area(p));
	if (!(*ctr) && e.mark == far && !ctr_occupied(p) && \
		dmin_to_coord(p.ctr, p.pos) > dmin_to_skin(p.ctr, e.skin))
	{
		center.crd = p.ctr;
		return (center);
	}
	*ctr = 1;
	if (e.mark == far)
		return (counter_ennemi(e));
	if (e.mark == ocp)
		return (fill_area(p));
	return (surround_ennemi(p, e, turn));
}

t_coord			find_closest(t_coord *pnt, t_coord ref)
{
	t_coord		*tmp;
	t_coord		ret;
	double		min;
	double		d;

	ret.x = -1000;
	ret.y = -1000;
	if (pnt != NULL)
	{	
		tmp = pnt;
		min = distance_2d(ref, *tmp);
		ret = *tmp;
		tmp = tmp->next;
		while (tmp != NULL)
		{
			d = distance_2d(ref, *tmp);
			if (d < min)
			{
				min = d;
				ret = *tmp;
			}
			tmp = tmp->next;
		}
	}
	return (ret);
}

t_coord			player(t_plateau *p, t_ennemi *e)
{
	t_coord		ret;
	t_skin		target;
	t_coord		*valid;
	static int	ctr = 0;
	static int	turn = 0;

	if ((p->pce).crd != NULL && p->pos != NULL)
	{
		target = get_target(*p, *e, &ctr, &turn);
		if (ctr && e->mark != far && \
				!is_inlist((target.crd).x, (target.crd).y, p->pos))
			valid = get_valid_pos(target, p);
		ret = find_closest((ctr && valid ? valid : p->pos), target.crd);
		ret.x -= ((p->pce).offset).x;
		ret.y -= ((p->pce).offset).y;
		ft_printf("%d %d\n", ret.x, ret.y);
	}
	else
	{
		ret.x = -1000;
		ft_printf("%d %d\n", ret.x, ret.y);
	}
	if (e->skin != NULL)
		((e->skin)->prev)->next = NULL;
	return (ret);
}
