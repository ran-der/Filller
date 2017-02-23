/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:40:08 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/23 19:58:19 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <unistd.h>

char		*strmark(t_mark m)
{
	if (m == ocp)
		return ("ocp\n");
	if (m == atwallf)
		return ("atwallf\n");
	if (m == atwallo)
		return ("atwallo\n");
	if (m == fre)
		return ("free\n");
	return ("euhhh..\n");
}

int			draw_if_skin(int x, int y, t_skin *pts)
{
	while (pts != NULL)
	{
		if ((pts->crd).x == x && (pts->crd).y == y)
		{
			if (pts->mark == atwallf)
				printf("$");
			else if (pts->mark == atwallo)
				printf("#");
			else if (pts->mark == fre)
				printf("+");
			else if (pts->mark == ocp)
				printf("-");
			return (0);
		}
		pts = pts->next;
	}
	return (1);
}



void		print_map_skin(char **map, t_coord size, t_ennemi e)
{
	int			x;
	int			y = -1;

	while (++y < size.y)
	{
		printf("%03i ", y);
		x = 0;
		while (x < size.x)
		{
			if (draw_if_skin(x, y, e.skin))
				dprintf(2, "%c", map[y][x]);
			x++;
		}
		dprintf(2, "\n");
	}
}



void		print_map(char **map, int size)
{
	int		i;

	dprintf(2, "MAP (size = %i):\n", size);
	if (map == NULL || *map == NULL)
		write(1, "NULL\n", 5);
	else
	{
		i = -1;
		while (++i < size)
			dprintf(2, "%03i%s\n", i, map[i]);
	}
}

t_info				*init_global(char c)
{
	t_info			*ret;

	ret = (t_info*)malloc(sizeof(t_info));
	ret->pl = (c == '1' ? 'O' : 'X');
	ret->pmap = NULL;
	return (ret);
}

int					main(void)
{
	char			*buff;
	static t_info	*global = NULL;
	t_plateau		plateau;
	t_ennemi		ennemi;
	t_coord			ret;
	
	while (get_next_line(0, &buff))
	{
		if (!ft_strncmp(buff, "$$$ exec p", 10))
			global = init_global(*(buff + 10));
		else if (!ft_strncmp(buff, "Plateau ", 8))
		{
			plateau = get_plt(buff, global->pl);
			ret = play(plateau, (ennemi = get_ennemi(plateau, global->pmap)));
			delete_map(global->pmap, (plateau.size).y);
			global->pmap = (ret.x == -3 && ret.y == -3 ? NULL : plateau.map);
			delete_all(plateau, ennemi);
			ft_printf("%d %d\n", ret.y, ret.x);
		}
		free(buff);
	}
	if (global->pmap == NULL)
		free(global);
	return (0);
}
