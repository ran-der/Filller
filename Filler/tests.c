/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 04:16:41 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/03 08:52:42 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			is_ennemi(char c, char pl)
{
	if (c == (pl == 'X' : 'O' : 'X'))
		return (1);
	return (0);
}

int			is_surface(t_coord p, char **map, t_coord size, char pl, int max)
{
	int			i;
	int			sides;

	sides = 0;
	i = 0;
	while (p.y + i < size.y && i <= max && !is_ennemi(map[p.y + i][p.x], pl))
		i++;
	if (p.y + i != size.y)
		sides++;
	i = 0;
	while (p.y - i >= 0 && i <= max && !is_ennemi(map[p.y - i][p.x], pl))
		i++;
	if (p.y - i != -1)
		sides++;
	i = 0;
	while (p.x + i < size.x && i <= max && !is_ennemi(map[p.y][p.x + i], pl))
		i++;
	if (p.x + i != size.x)
		sides++;  
	i = 0;
	while (p.x - i >= 0 && i <= max && !is_ennemi(map[p.y][p.x - i], pl))
		i++;
	if (p.x - i != -1)
		sides++;
	return (sides < 3 ? 1 : 0);
}

int			is_skinpnt(t_coord pnt, char **map, t_coord size, char pl)
{
	if (((pnt.y + 2 < size.y && is_ennemi(map[pnt.y + 2][pnt.x], pl)) || \
		(pnt.y - 2 >= 0 && is_ennemi(map[pnt.y - 2][pnt.x], pl)) || \
		(pnt.x + 2 < size.x && is_ennemi(map[pnt.y][pnt.x + 2], pl)) || \
		(pnt.x - 2 >= 0 && is_ennemi(map[pnt.y][pnt.x - 2], pl))) \
		&& is_surface(pnt, map, size, pl, MAX(size.x, size.y) / 10)
		return (1);
	return (0);
}
