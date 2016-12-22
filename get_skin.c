/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_skin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 03:09:10 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/19 19:22:25 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

int			is_epos(int y, int x, t_coord *epos)
{
	while (epos != NULL)
	{
		if (epos->x == x && epos->y == y)
			return (1);
		epos = epos->next;
	}
	return (0);
}

int			is_atwall(t_coord pnt, t_plateau p)
{
	int		xsize;
	int		ysize;
	char	**map;

	xsize = (p.size).x;
	ysize = (p.size).y;
	if (!pnt.x || pnt.x == xsize || !pnt.y || pnt.y == ysize)
	{
		map = p.map;
		if ((!pnt.x || pnt.x == xsize) && (!pnt.y || pnt.y == ysize))
			if (is_ennemi(map[pnt.y + (!pnt.y ? 1 : -1)][pnt.x]) || \
				is_ennemi(map[pnt.y][pnt.x + (!pnt.x ? 1 : -1)]))
				return (1);
		if (!pnt.x || pnt.x == xsize)
			if ((pnt.y < ysize - 1 && is_ennemi(map[pnt.y + 1][pnt.x])) || \
				(pnt.y > 0 && is_ennemi(map[pnt.y - 1][pnt.x])))
				return (1);
		if (!pnt.y || pnt.y == ysize)
			if ((pnt.x < xsize - 1 && is_ennemi(map[pnt.y][pnt.x + 1])) || \
				(pnt.x > 0 && is_ennemi(map[pnt.y][pnt.x - 1])))
				return (1);
	}
	return (0);
}


void		set_ocp_marks(t_skin *skin, t_plateau p)
{
	t_skin		*tmp;
	int			i;

	tmp = skin;
	while (tmp != NULL)
	{
		i = -2;
		if (is_atwall(tmp->crd, p))
			tmp->mark = atwall;
		while (++i < 2)
			if (is_epos((tmp->crd).y - 1, (tmp->crd).x + i, p.epos) ||\
				is_epos((tmp->crd).y + 1, (tmp->crd).x + i, p.epos) ||\
				(i && is_epos((tmp->crd).y, (tmp->crd).x + i, p.epos)))
				tmp->mark = (tmp->mark == atwall ? atwallo : eocp);
		while (ocp != -1 && --i > -2)
			if ((p.map)[(tmp->crd).y - 1][(tmp->crd).x + i] == p.pl ||\
				(p.map)[(tmp->crd).y + 1][(tmp->crd).x + i] == p.pl ||\
				(i && (p.map)[(tmp->crd).y][(tmp->crd).x + i] == p.pl))
				tmp->mark = (tmp->mark == atwall ? atwallo : ocp);
		tmp = tmp->next;
	}
}

void		find_edges(t_skin **skin, t_plateau *p)
{
	t_skin		*tmp;
	int			n;
	int			max;

	while ((*skin).ocp != 0 || ((*skin)->prev).ocp == 0)
		*skin = (*skin)->prev;
	max = 0;
	(p->edge)[0] = *skin;
	(p->edge)[1] = *skin;
	while (((p->edge)[1]).ocp == 0)
	{
		(p->edge)[1] = ((p->edge)[1])->next;
		max++;
	}


void		get_skin(t_plateau *plt)
{
	t_skin		*tmp;
	t_chunk		*pts;
	t_coord		pnt;
	
	pts = NULL;
	pnt.y = -1;
	while (++(pnt.y) < (plt->size).y)
	{
		pnt.x = -1;
		while ((plt->map)[pnt.y][++(pnt.x)] != '\0')
			if (is_skinpnt(pnt, plt))
				skin_pushback(&pts, pnt);
	}
	set_ocp_marks(pts, *plt);
	tmp = skin;
	find_edges(skin, plt)
	plt->skin = skin;
}
