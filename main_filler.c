/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:40:08 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/22 22:03:12 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			draw_if_skin(int x, int y, t_skin *pts)
{
	while (pts != NULL)
	{
		if ((pts->crd).x == x && (pts->crd).y == y)
		{
			if (pts->mark == atwall)
				write(1, "#", 1);
			else if (pts->mark == fre)
				write(1, "~", 1);
			else
				write(1, "@", 1);
			return (0);
		}
		pts = pts->next;
	}
	return (1);
}

void		print_map_skin(char **map, t_skin *pts, int size)
{
	int			x;
	int			y = -1;

	while (++y < size)
	{
		x = -1;
		while (map[y][++x] != '\n')
			if (draw_if_skin(x, y, pts))
				write(1, &(map[y][x]), 1);
	}
}

int			main(void)
{
	char		*tmp;
	char		*buf;
	char		pl;
	t_plateau	*plateau;

	plateau = NULL;
	while (get_next_line(0, &buf))
	{
		if (!ft_strncmp(buf, "$$$ exec p", 10))
			pl = (*(buf + 10) == '1' ? 'O' : 'X');
		else if (!ft_strncmp(buf, "Plateau ", 8))
		{
			get_next_line(0, &tmp);
			free(tmp);
			plateau = get_plt(&plateau, buf, pl);
			print_map_skin(plateau->map, plateau->skin, (plateau->size).y);
		}
		else
		{
			delete_plt(plateau);
			free(buf);
			return (0);
		}
		free(buf);
	}
	return (0);
}
