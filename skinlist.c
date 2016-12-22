/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skinlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:25:50 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/18 09:26:41 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_dir		find_dir(t_coord pnt, char **map, t_coord sz, char pl)
{
	t_dir		dir;

	dir = W;
	if (pnt.y + 1 < sz.y && is_ennemi(map[pnt.y + 1][pnt.x], pl))
		dir = N;
	if (pnt.y - 1 >= 0 && is_ennemi(map[pnt.y - 1][pnt.x], pl))
		dir = S;
	if (pnt.x + 1 < sz.x && is_ennemi(map[pnt.y][pnt.x + 1], pl))
	{
		if (dir == N)
			dir = NW;
		else if (dir == S)
			dir = SW;
	}
	if (pnt.x - 1 >= 0 && is_ennemi(map[pnt.y][pnt.x - 1], pl))
	{
		if (dir == N)
			dir = NE;
		else if (dir == S)
			dir = SE;
		else
			dir = E;
	}
	return (dir);
}

t_skin		*new_skin_pnt(t_coord pnt, t_plateau plt)
{
	t_skin		*new;

	errno = 0;
	if ((new = (t_skin*)malloc(sizeof(t_skin))) == NULL || errno)
		perror("in function \"new_skin_pnt\"");
	new->prev = NULL;
	new->next = NULL;
	(new->crd).x = pnt.x;
	(new->crd).y = pnt.y;
	new->mark = fre;
	new->dir = find_dir(pnt, plt.map, plt.size, plt.pl);
	return (new);
}

void		skin_pushfront(t_skin **skin, t_coord pnt, t_plateau plt)
{
	t_skin		*new;

	new = new_skin_pnt(pnt, plt);
	if (*skin != NULL)
	{
		(*skin)->prev = new;
		new->next = *skin;
	}
	*skin = new;
}

void		skin_pushback(t_skin **skin, t_coord pnt, t_plateau plt)
{
	t_skin		*tmp;
	t_skin		*new;

	tmp = *skin;
	while (tmp != NULL && tmp->next != NULL)
		tmp = tmp->next;
	new = new_skin_pnt(pnt, plt);
	new->prev = tmp;
	if (tmp != NULL)
		tmp->next = new;
	else
		*skin = new;
}
