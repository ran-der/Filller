/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:00:27 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/23 19:52:20 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		delete_map(char **map, int size)
{
	int		i;

	if (map != NULL && *map != NULL)
	{
		i = -1;
		while (++i < size)
			ft_strdel(&(map[i]));
		free(map);
		map = NULL;
	}
}

void			delete_elem(int x, int y, t_coord **list)
{
	t_coord		*tmp;
	t_coord		*elem;

	if ((tmp = *list) != NULL)
	{
		if (tmp->x == x && tmp->y == y)
		{
			*list = tmp->next;
			free(tmp);
		}
		else
		{
			while ((elem = tmp->next) != NULL)
			{
				if (elem->x == x && elem->y == y)
				{
					tmp->next = elem->next;
					free(elem);
					break ;
				}
				tmp = tmp->next;
			}
		}
	}
}

void		delete_crdlist(t_coord **list)
{
	t_coord		*tmp;
	t_coord		*nxt;

	if (list == NULL || (tmp = *list) == NULL)
		return ;
	while (tmp->next != NULL)
	{
		nxt = tmp->next;
		free(tmp);
		tmp = nxt;
	}
	*list = NULL;
}

void		delete_skin(t_skin **list)
{
	t_skin		*tmp;
	t_skin		*nxt;

	if (list == NULL || (tmp = *list) == NULL)
		return ;
	while (tmp->next != NULL)
	{
		nxt = tmp->next;
		free(tmp);
		tmp = nxt;
	}
	*list = NULL;
}

void		delete_all(t_plateau p, t_ennemi e)
{
	delete_crdlist(&(p.pos));
	delete_skin(&(e.skin));
}
