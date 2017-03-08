/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ennemi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:11:29 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/27 16:39:19 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coord			get_epos(t_plateau p, char **pmap)
{
	t_coord		ret;

	ret.y = -1;
	while (++(ret.y) < (p.size).y)
	{
		ret.x = -1;
		while ((p.map)[ret.y][++(ret.x)] != '\0')
		{
			if (is_ennemi((p.map)[ret.y][ret.x], p.pl) && \
				(pmap == NULL || (p.map)[ret.y][ret.x] != pmap[ret.y][ret.x]))
				return (ret);
		}
	}
	ret = p.ctr;
	return (ret);
}

t_mark			get_emark(t_skin *skin)
{
	t_skin		*tmp;

	if ((tmp = skin) != NULL)
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

t_ennemi		get_ennemi(t_plateau p, char **pmap)
{
	t_skin		*tmp;
	t_ennemi	ret;

	ret.skin = NULL;
	ret.epos = get_epos(p, pmap);
	ret.sqr = get_square(p);
	get_skin(p, &ret);
	ret.mark = get_emark(ret.skin);
	if ((tmp = ret.skin) != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ret.skin;
		(ret.skin)->prev = tmp;
	}
	return (ret);
}
