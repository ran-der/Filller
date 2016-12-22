/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 02:08:51 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/19 19:22:15 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				isplace(t_coord pos, t_plateau *p)
{
	int			overlaps;
	t_coord		*tmp;

	overlaps = 0;
	tmp = (p->pce).crd;
	while (tmp != NULL)
	{
		if (pos.y + tmp->y >= (p->size).y || pos.x + tmp->x >= (p->size).x)
			return (0);
		if ((p->map)[pos.y + tmp->y][pos.x + tmp->x] == p->pl)
			overlaps++;
		else if ((p->map)[pos.y + tmp->y][pos.x + tmp->x] != '.')
			return (0);
		tmp = tmp->next;
	}
	return (overlaps == 1 ? 1 : 0);
}

void			get_allpos(t_plateau *p)
{
	t_coord		pos;

	p->pos = NULL;
	pos.y = -1;
	while (++(pos.y) < (p->size).y)
	{
		pos.x = -1;
		while ((p->map)[pos.y][++(pos.x)] != 0)
		{
			if (isplace(pos, p))
				crdlist_pushback(&(p->pos), new_crdlist(pos.x, pos.y));
		}
	}
}

void			get_epos(t_plateau *p)
{
	int			x;
	int			y;

	p->epos = NULL;
	y = -1;
	while (++y < (p->size).y)
	{
		x = -1;
		while ((p->map)[y][++x] != 0)
		{
			if (!(p->pmap) || ((p->map)[y][x] != '.' && (p->map)[y][x] != p->pl\
						&& (p->map)[y][x] != (p->pmap)[y][x]))
				crdlist_pushback(&(p->epos), new_crdlist(x, y));
		}
	}
}

void			get_size(char *buff, t_plateau *plt)
{
	(plt->size).y = ft_atoi(buff + 8);
	while (ft_isdigit(*(buff + 8)))
		buff++;
	(plt->size).x = ft_atoi(buff + 8);
}

t_plateau		*get_plt(t_plateau **p, char *buff, char pl)
{
	if (!udt)
	{
		if ((*p = (t_plateau*)malloc(sizeof(t_plateau))) == NULL)
			return (NULL);
		(*p)->pl = pl;
		get_size(buff, *p);
		(*p)->map = NULL;
	}
	else
	{
		delete_map((*p)->pmap, ((*p)->size).y);
		delete_crdlist(((*p)->pce).crd);
		delete_crdlist((*p)->epos);
		delete_crdlist((*p)->pos);
		delete_skin((*p)->skin);
	}
	(*p)->pmap = (*p)->map;
	(*p)->map = read_map((*p)->size);
	(*p)->pce = read_piece();
	get_epos(*p);
	get_allpos(*p);
	get_skin(*p);
	return (*p);
}
