/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:40:08 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/21 17:05:53 by rvan-der         ###   ########.fr       */
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
				printf("%c", map[y][x]);
			x++;
		}
		printf("\n");
	}
}



void		print_map(char **map, int size)
{
	int		i;

	printf("MAP (size = %i):\n", size);
	if (map == NULL || *map == NULL)
		write(1, "NULL\n", 5);
	else
	{
		i = -1;
		while (++i < size)
			printf("%03i%s\n", i, map[i]);
	}
}

int			main(void)
{
	char		*buff;
	char		pl;
	t_plateau	*plateau;
	t_ennemi	*ennemi;
	
	plateau = NULL;
	ennemi = NULL;
	while (get_next_line(0, &buff))
	{
		if (!ft_strncmp(buff, "$$$ exec p", 10))
			pl = (*(buff + 10) == '1' ? 'O' : 'X');
		else if (!ft_strncmp(buff, "Plateau ", 8))
		{
			plateau = get_plt(&plateau, buff, pl);
			ennemi = get_ennemi(&ennemi, plateau);
			//((ennemi->skin)->prev)->next = NULL;
			//print_map_skin(plateau->map, plateau->size, *ennemi);
			//((ennemi->skin)->prev)->next = ennemi->skin;
			if((player(plateau, ennemi)).x == -1000)
			{
				delete_all(&plateau, &ennemi);
				free(buff);
				return (0);
			}
		}
		free(buff);
	}
	return (0);
}
