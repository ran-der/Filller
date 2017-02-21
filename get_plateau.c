/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plateau.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 02:08:51 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/21 17:02:52 by rvan-der         ###   ########.fr       */
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

void			printlist(t_coord *list, char *name)
{
	t_coord		*tmp;

	printf("%s:\n X ; Y\n", name);
	if ((tmp = list) == NULL)
		printf("NULL\n");
	while (tmp != NULL)
	{
		printf(" %d ; %d\n", tmp->x, tmp->y);
		tmp = tmp->next;
	}
}

t_plateau		*get_plt(t_plateau **p, char *buff, char pl)
{
	if (*p == NULL)
	{
		if ((*p = (t_plateau*)malloc(sizeof(t_plateau))) == NULL)
			return (NULL);
		(*p)->pl = pl;
		(*p)->size = get_size(buff + 8);
		((*p)->ctr).x = ((*p)->size).x / 2;
		((*p)->ctr).y = ((*p)->size).y / 2;
		(*p)->map = NULL;
	}
	else
	{
		delete_map((*p)->pmap, ((*p)->size).y);
		delete_crdlist(((*p)->pce).crd);
		delete_crdlist((*p)->pos);
	}
	(*p)->pmap = (*p)->map;
	(*p)->map = read_map((*p)->size);
	(*p)->pce = read_piece();
	get_allpos(*p);
	return (*p);
}
