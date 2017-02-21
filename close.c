/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:08:03 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/16 18:35:01 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


t_skin		close_ennemi(t_plateau p)
{
	t_skin		ret;

	(ret.crd).x = 0;
	while ((ret.crd).x < (p.size).x)
	{
		(ret.crd).y = 0;
		while ((ret.crd).y < (p.size).y - 1 && \
				(p.map)[(ret.crd).y][(ret.crd).x] != p.pl)
		{
			if (is_ennemi((p.map[(ret.crd).y + 1][(ret.crd).x], p.pl
			((ret.crd).y)++;
		}
		((ret.crd).x)++;
	}
	return (close_ennemi2(p));
}
