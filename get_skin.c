/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_skin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:58:16 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/27 17:09:11 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				is_skin(t_coord pos, t_skin *list)
{
	t_skin		*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		if ((tmp->crd).x == pos.x && (tmp->crd).y == pos.y)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void			get_skin4(t_plateau p, t_ennemi *e)
{
	t_coord		pos;

	pos.y = (e->sqr).s;
	while (pos.y >= (e->sqr).n)
	{
		pos.x = ((e->sqr).w ? (e->sqr).w - 1 : 0);
		while (!is_ennemi((p.map)[pos.y][pos.x], p.pl))
		{
			if (((pos.y + 1 < (p.size).y && \
					is_ennemi((p.map)[pos.y + 1][pos.x], p.pl)) || \
					(pos.y - 1 >= 0 && \
					is_ennemi((p.map)[pos.y - 1][pos.x], p.pl)) || \
					is_ennemi((p.map)[pos.y][pos.x + 1], p.pl)) \
					&& is_surface(pos, p) \
					&& !is_inhole(pos, p) \
					&& !is_skin(pos, e->skin))
				skin_pushback(&(e->skin), pos, p);
			(pos.x)++;
		}
		(pos.y)--;
	}
}

void			get_skin3(t_plateau p, t_ennemi *e)
{
	t_coord		pos;

	pos.x = (e->sqr).e;
	while (pos.x >= (e->sqr).w)
	{
		pos.y = ((e->sqr).s == (p.size).y - 1 ? (e->sqr).s : (e->sqr).s + 1);
		while (!is_ennemi((p.map)[pos.y][pos.x], p.pl))
		{
			if (((pos.x + 1 < (p.size).x && \
					is_ennemi((p.map)[pos.y][pos.x + 1], p.pl)) || \
					(pos.x - 1 >= 0 && \
					is_ennemi((p.map)[pos.y][pos.x - 1], p.pl)) || \
					is_ennemi((p.map)[pos.y - 1][pos.x], p.pl)) \
					&& is_surface(pos, p) \
					&& !is_inhole(pos, p) \
					&& !is_skin(pos, e->skin))
				skin_pushback(&(e->skin), pos, p);
			(pos.y)--;
		}
		(pos.x)--;
	}
	get_skin4(p, e);
}

void			get_skin2(t_plateau p, t_ennemi *e)
{
	t_coord		pos;

	pos.y = (e->sqr).n;
	while (pos.y <= (e->sqr).s)
	{
		pos.x = ((e->sqr).e == (p.size).x - 1 ? (e->sqr).e : (e->sqr).e + 1);
		while (!is_ennemi((p.map)[pos.y][pos.x], p.pl))
		{
			if (((pos.y + 1 < (p.size).y && \
					is_ennemi((p.map)[pos.y + 1][pos.x], p.pl)) || \
					(pos.y - 1 >= 0 && \
					is_ennemi((p.map)[pos.y - 1][pos.x], p.pl)) || \
					is_ennemi((p.map)[pos.y][pos.x - 1], p.pl)) \
					&& is_surface(pos, p) \
					&& !is_inhole(pos, p) \
					&& !is_skin(pos, e->skin))
				skin_pushback(&(e->skin), pos, p);
			(pos.x)--;
		}
		(pos.y)++;
	}
	get_skin3(p, e);
}

void			get_skin(t_plateau p, t_ennemi *e)
{
	t_coord		pos;

	pos.x = (e->sqr).w;
	while (pos.x <= (e->sqr).e)
	{
		pos.y = ((e->sqr).n > 0 ? (e->sqr).n - 1 : 0);
		while (!is_ennemi((p.map)[pos.y][pos.x], p.pl))
		{
			if (((pos.x + 1 < (p.size).x && \
					is_ennemi((p.map)[pos.y][pos.x + 1], p.pl)) || \
					(pos.x - 1 >= 0 && \
					is_ennemi((p.map)[pos.y][pos.x - 1], p.pl)) || \
					is_ennemi((p.map)[pos.y + 1][pos.x], p.pl)) \
					&& is_surface(pos, p) \
					&& !is_inhole(pos, p) \
					&& !is_skin(pos, e->skin))
				skin_pushback(&(e->skin), pos, p);
			(pos.y)++;
		}
		(pos.x)++;
	}
	get_skin2(p, e);
}
