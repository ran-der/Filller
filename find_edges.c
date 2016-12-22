/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_edges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 04:52:30 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/05 09:49:55 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_skin		*find_next_edge(t_skin *edge)
{
	while (edge->ocp != 0)
		edge = edge->next;
	return (edge);
}

(p->edge)[]
void		find_edges(t_skin **skin, t_plateau *p)
{
	t_skin		*tmp;
	int			n;
	int			max;

	while ((*skin).ocp != 0 || ((*skin)->prev).ocp == 0)
		*skin = (*skin)->prev;
	max = 0;
	(p->edge)[0] = *skin;
	(p->edge)[1] = *skin;
	while (((p->edge)[1]).ocp == 0)
	{
		(p->edge)[1] = ((p->edge)[1])->next;
		max++;
	}
