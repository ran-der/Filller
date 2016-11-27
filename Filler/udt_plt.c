/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   udt_plt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 02:08:51 by rvan-der          #+#    #+#             */
/*   Updated: 2016/11/27 16:50:55 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				isplace(t_coord pos, char **map, t_coord *piece, t_coord size,\
						char pl)
{
	int			overlaps;
	t_coord		*tmp;

	overlaps = 0;
	tmp = piece;
	while (tmp != NULL)
	{
		if (pos.y + tmp->y >= size.y || pos.x + tmp->x >= size.x)
			return (0);
		if (map[pos.y + tmp->y][pos.x + tmp->x] == pl)
			overlaps++;
		else if (map[pos.y + tmp->y][pos.x + tmp->x] != '.')
			return (0);
		tmp = tmp->next;
	}
	return (overlaps == 1 ? 1 : 0);
}

t_coord			*get_allpos(char **map, char pl, tcoord size, t_coord *piece)
{
	t_coord		*ret;
	t_coord		pos;
	int			x;
	int			y;

	ret = NULL;
	pos.y = -1;
	while (++y < size.y)
	{
		pos.x = -1;
		while (map[y][++x] != 0)
		{
			if (isplace(pos, map, piece, size, pl))
				crdlist_pushback(&ret, new_crdlist(pos.x, pos.y));
		}
	}
	return (ret);
}

t_coord			*get_epos(char **map, char **pmap, char pl, int size)
{
	t_coord		*ret;
	int			x;
	int			y;

	ret = NULL;
	y = -1;
	while (++y < size)
	{
		x = -1;
		while (map[y][++x] != 0)
		{
			if (!pmap || (map[y][x] != '.' && map[y][x] != pl && \
						map[y][x] != pmap[y][x]))
				crdlist_pushback(&ret, new_crdlist(x, y));
		}
	}
	return (ret);
}

t_plateau		*udt_plt(t_plateau *plt, char ***pmap)
{
	delete_map(*pmap, (plt->size).y);
	*pmap = plt->map;
	plt->map = read_map(plateau.size);
	delete_crdlist((plt->pce).crd);
	plt->pce = read_piece();
	delete_crdlist(plt->epos);
	plt->epos = get_epos(plt->map, *pmap, plt->pl, (plt->size).y);
	delete_crdlist(plt->pos)
	plt->pos = get_allpos(plt->map, plt->pl, (plt->pce).crd, plt->size);
	return (plt);
}
