/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:00:27 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/19 18:13:39 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		delete_map(char **map, int size)
{
	int		i;

	if (map != NULL)
	{
		i = -1;
		while (++i < size)
			ft_strdel(map[i]);
		free(map);
	}
}

void		delete_crdlist(t_coord *list)
{
	if (*list != NULL)
	{
		delete_crdlist(list->next);
		free(list);
	}
}

void		delete_skin(t_skin *list)
{
	if (list != NULL)
	{
		delete_crdlist(list->next)
		free(list);
	}
}
