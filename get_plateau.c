/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plateau.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 02:08:51 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/25 23:13:30 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				isplace(t_coord pos, t_plateau p)
{
	int			overlaps;
	t_coord		*tmp;

	overlaps = 0;
	tmp = (p.pce).crd;
	while (tmp != NULL)
	{
		if (pos.y + tmp->y >= (p.size).y || pos.x + tmp->x >= (p.size).x)
			return (0);
		if ((p.map)[pos.y + tmp->y][pos.x + tmp->x] == p.pl)
			overlaps++;
		else if ((p.map)[pos.y + tmp->y][pos.x + tmp->x] != '.')
			return (0);
		tmp = tmp->next;
	}
	return (overlaps == 1 ? 1 : 0);
}

t_coord			*get_allpos(t_plateau p)
{
	t_coord		*ret;
	t_coord		tmp;

	ret = NULL;
	tmp.y = -1;
	while (++(tmp.y) < (p.size).y)
	{
		tmp.x = -1;
		while ((p.map)[tmp.y][++(tmp.x)] != 0)
		{
			if (isplace(tmp, p))
				crdlist_pushback(&ret, new_crdlist(tmp.x, tmp.y));
		}
	}
	return (ret);
}

t_plateau		get_plt(char *buff, char pl)
{
	t_plateau	ret;

	ret.pl = pl;
	ret.size = get_size(buff + 8);
	(ret.ctr).x = (ret.size).x / 2;
	(ret.ctr).y = (ret.size).y / 2;
	ret.map = read_map(ret.size);
	ret.pce = read_piece();
	ret.pos = get_allpos(ret);
	return (ret);
}
