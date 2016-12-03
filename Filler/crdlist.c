/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crdlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 16:20:20 by rvan-der          #+#    #+#             */
/*   Updated: 2016/11/27 16:50:49 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			delete_crdlist(t_coord *list)
{
	if (list == NULL)
		return ;
	delete_crdlist(list->next);
	free(list);
}

t_coord			*new_crdlist(int x, int y)
{
	t_coord		*ret;

	ret = (t_coord*)malloc(sizeof(t_coord*));
	ret->x = x;
	ret->y = y;
	ret->next = NULL;
	return (ret);
}

void			crdlist_pushback(t_coord **list, t_coord *elem)
{
	t_coord		*tmp;

	tmp = *list;
	if (tmp == NULL)
		*list = elem;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = elem;
	}
}
