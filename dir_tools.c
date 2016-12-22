/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:32:15 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/22 18:27:56 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_dir		get_cdir(t_skin pnt, t_coord size)
{
	if (!(pnt.crd).x)
	{
		if (!(pnt.crd).y)
			return (pnt.dir == N ? E : S);
		if ((pnt.crd).y == size.y - 1)
			return (pnt.dir == S ? E : N);
	}
	if ((pnt.crd).x == size.x - 1)
	{
		if (!(pnt.crd).y)
			return (pnt.dir == N ? W : S);
		if ((pnt.crd).y == size.y - 1)
			return (pnt.dir == S ? W : N);
	}
	return (pnt.dir);
}

t_dir		get_ldir(t_skin pnt, t_dir cdir)
{
	if (cdir == N || cdir == S)
		return (!(pnt.crd).x ? E : W);
	return (!(pnt.crd).y ? S : N);
}

t_dir		invert_dir(t_dir dir)
{
	if (dir == N)
		return (S);
	if (dir == S)
		return (N);
	if (dir == W)
		return (E);
	if (dir == E)
		return (W);
	if (dir == NE)
		return (SW);
	if (dir == SW)
		return (NE);
	if (dir == NW)
		return (SE);
	return (NW);
}
