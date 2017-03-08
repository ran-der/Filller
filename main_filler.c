/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:40:08 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/27 16:35:47 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
			ennemi = get_ennemi(plateau, global->pmap);
			ret = play(plateau, ennemi);
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
