/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_skin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 03:27:07 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/03 08:52:36 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"



t_skin		*get_all_pts(char **map, t_coord size, char pl)
{
	t_skin		*ret;
	t_coord		pnt;
	
	ret = NULL;
	pnt.y = -1;
	while (++(pnt.y) < size.y)
	{
		pnt.x = -1;
		while (map[pnt.y][++(pnt.x)] != '\0')
			if (is_skinpnt(pnt, map, size, pl))
				skin_insert(&ret, pnt);
	}
	return (ret);
}	

void		get_skin(char **map, t_coord *epos, t_plateau *plt)
{
	t_skin		*pts;
	t_skin		*skin;
	
	skin = get_all_pts(map, plt->size, plt->pl);
	arrange_pts(&skin);
	set_ocp_marks(map, skin, epos);
	plt->skin = skin;
}
