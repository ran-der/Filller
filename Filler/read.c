/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 02:56:49 by rvan-der          #+#    #+#             */
/*   Updated: 2016/11/27 16:50:59 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			find_offset(t_piece *ret, char **piece, int size)
{
	int			x;
	int			y;
	int			yfound;
	int			xmin;

	y = -1;
	yfound = 0;
	while (++y < size)
	{
		x = -1;
		while (piece[y][++x] != '\0')
		{
			if (piece[y][x] == 42)
			{
				if (!yfound)
				{
					ret->y_offset = y;
					xmin = x;
					yfound = 1;
				}
				else
					xmin = (x < xmin ? : x : xmin);
			}
		}
	}
}

t_coord			*get_pce_crd(int xmin, int ymin, char **piece, int size)
{
	int			x;
	int			y;
	t_coord		*ret;

	ret = NULL;
	y = -1;
	while (++y < size)
	{
		x = -1;
		while (piece[y][++x] != '\0')
			if (piece[y][x] == 42)
				crdlist_pushback(&ret, new_crdlist(x - xmin, y - ymin));
	}
	return (ret);
}

t_piece			read_piece(void)
{
	t_piece		ret;
	int			i;
	char		*buff;
	char		**piece;
	int			size;

	get_next_line(0, &buff);
	size = ft_atoi(buff + 6);
	piece = (char**)malloc(sizeof(char*) * size);
	free(buff);
	i = -1;
	while (++i < size)
	{
		get_next_line(0, &buff);
		piece[i] = buff;
	}
	find_offset(&ret, piece, size);
	ret.crd = get_pce_crd(ret.x_offset, ret.y_offset, piece, size);
	delete_map(piece, size);
	return (ret);
}

char			**read_map(t_coord size)
{
	char		**ret;
	char		*buff;
	int			i;

	ret = (char**)malloc(sizeof(char*) * size.y);
	i = -1;
	while (++i < size.y)
	{
		get_next_line(0, &buff);
		ret[i] = ft_strdup(buff + 4);
		free(buff);
	}
	return (ret);
}
