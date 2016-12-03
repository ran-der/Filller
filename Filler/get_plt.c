/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 02:08:51 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/03 08:52:39 by rvan-der         ###   ########.fr       */
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

	ret = NULL;
	pos.y = -1;
	while (++(pos.y) < size.y)
	{
		pos.x = -1;
		while (map[pos.y][++(pos.x)] != 0)
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

void			get_size(char *buff, t_plateau *plt)
{
	(plt->size).y = ft_atoi(buff + 8);
	while (ft_isdigit(buff + 8))
		buff++;
	(plt->size).x = ft_atoi(buff + 8);
}

t_plateau		*get_plt(t_plateau **plt, char ***pmap, char *buff, char pl,\
							int udt)
{
	if (!udt)
	{
		if ((*plt = (t_plateau*)malloc(sizeof(t_plateau))) == NULL)
			return (NULL);
		(*plt)->pl = pl;
		get_size(buff, *plt);
	}
	else
	{
		delete_map(*pmap, ((*plt)->size).y);
		delete_crdlist(((*plt)->pce).crd);
		delete_crdlist((*plt)->epos);
		delete_crdlist((*plt)->pos);
		delete_skin((*plt)->skin);
	}
	(*plt)->map = read_map(plt->size);
	if (udt)
		*pmap = (*plt)->map;
	(*plt)->pce = read_piece();
	(*plt)->epos = get_epos((*plt)->map, *pmap, (*plt)->pl, ((*plt)->size).y);
	(*plt)->pos = get_allpos((*plt)->map, (*plt)->pl, ((*plt)->pce).crd,\
								(*plt)->size);
	get_skin((*plt)->map, (*plt)->epos, *plt);
	return (*plt);
}
