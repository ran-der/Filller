/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 02:56:49 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/21 12:55:35 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			find_offset(t_piece *ret, char **piece, int size)
{
	int			x;
	int			y;
//	int			i;

	(ret->offset).y = -1;
	(ret->offset).x = -1;
	y = -1;
	while (++y < size && (ret->offset).x)
	{
		x = 0;
		while (piece[y][x] != '\0' && piece[y][x] != 42)
			x++;
		if (piece[y][x] == 42 && (ret->offset).y == -1)
		{
			(ret->offset).y = y;
			(ret->offset).x = x;
		}
		else if (piece[y][x] == 42)
			(ret->offset).x = (x < (ret->offset).x ? x : (ret->offset).x);
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

t_coord			get_size(char *buff)
{
	t_coord		ret;

	ret.y = ft_atoi(buff);
	while (ft_isdigit(*(buff)))
		buff++;
	ret.x = ft_atoi(buff);
	return (ret);
}

t_piece			read_piece(void)
{
	t_piece		ret;
	int			i;
	char		*buff;
	char		**piece;

	get_next_line(0, &buff);
	ret.size = get_size(buff + 6);
	piece = (char**)malloc(sizeof(char*) * (ret.size).y);
	free(buff);
	i = -1;
	while (++i < (ret.size).y)
	{
		get_next_line(0, &buff);
		piece[i] = ft_strdup(buff);
		free(buff);
	}
	find_offset(&ret, piece, (ret.size).y);
	ret.crd = get_pce_crd((ret.offset).x, (ret.offset).y, piece, (ret.size).y);
	delete_map(piece, (ret.size).y);
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
