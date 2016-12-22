/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:32:15 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/22 11:56:37 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_dir		get_cdir(t_coord pnt, t_coord size)
{
	if (!pnt.x)
	{
		if (!pnt.y)
			return (pnt.dir == N ? E : S);
		if (pnt.y == size - 1)
			return (pnt.dir == S ? E : N);
	}
	if (pnt.x == size.x - 1)
	{
		if (!pnt.y)
			return (pnt.dir == N ? W : S);
		if (pnt.y == size.y - 1)
			return (pnt.dir == S ? W : N);
	}
	return (pnt.dir);
}

t_dir		get_ldir(t_coord pnt, t_coord size, t_dir cdir)
{
	if (cdir == N || cdir == S)
		return (!pnt.x ? E : W);
	return (!pnt.y ? S : N);
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
