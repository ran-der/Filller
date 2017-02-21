/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ennemi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:11:29 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/21 12:53:48 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coord			get_epos(t_plateau p)
{
	t_coord		ret;

	ret.y = -1;
	while (++(ret.y) < (p.size).y)
	{
		ret.x = -1;
		while ((p.map)[ret.y][++(ret.x)] != '\0')
		{
			if ((p.map)[ret.y][ret.x] == (p.pl == 'X' ? 'o' : 'x') || \
				(p.pmap == NULL && is_ennemi((p.map)[ret.y][ret.x], p.pl)))
				return (ret);
		}
	}
	return (ret);
}

t_mark			get_emark(t_ennemi e)
{
	t_skin		*tmp;

	if ((tmp = e.skin) != NULL)
	{
		if (tmp->mark == atwallo || tmp->mark == ocp)
		{
			tmp = tmp->next;
			while (tmp != NULL && (tmp->mark == ocp || tmp->mark == atwallo))
				tmp = tmp->next;
			return (tmp == NULL ? ocp : fre);
		}
		tmp = tmp->next;
		while (tmp != NULL && (tmp->mark == fre || tmp->mark == atwallf))
			tmp = tmp->next;
	}
	return (tmp == NULL ? far : fre);
}

t_ennemi		*get_ennemi(t_ennemi **e, t_plateau *p)
{	
	t_skin		*tmp;

	if (!(*e))
	{
		if ((*e = malloc(sizeof(t_ennemi))) == NULL)
			return (NULL);
		(*e)->skin = NULL;
	}
	delete_skin((*e)->skin);
	(*e)->epos = get_epos(*p);
	(*e)->sqr = get_square(*p);
	get_skin(*p, *e);
	(*e)->mark = get_emark(**e);
	if ((tmp = (*e)->skin) != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (*e)->skin;
		((*e)->skin)->prev = tmp;
	}
	return (*e);
}
