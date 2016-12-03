/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:40:08 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/03 08:52:33 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		init_args(char *buff, t_plateau **plateau, t_piece **piece)
{
	if (args == NULL)
	{
		errno = 0;
		if ((*args = malloc(sizeof(t_plateau*))) == NULL)
			perror("malloc in function init_args");
		((*args)->plateau).old = NULL;
	}
	else
		delete_map(((*args)->plateau).old);
	((*args)->plateau).old = ((*args)->plateau).map;
	((*args)->plateau).map = read_map(buff);
	((*args)->plateau).lstpos = get_lstpos(((*args)->plateau).map, \
											((*args)->plateau).old);
	get_piece(args);
	

int			main(void)
{
	char		pl;
	char		**pmap;
	t_plateau	*plt;

	pmap = NULL;
	plt = NULL;
	while (get_next_line(0, &buf))
	{
		if (!ft_strncmp(buf, "$$$ exec p", 10))
			pl = (*(buf + 10) == '1' ? 'O' : 'X');
		else if (!ft_strncmp(buf, "Plateau ", 8))
			play(get_plt(&plt, &pmap, buf, pl, (!plt ? 0 : 1)));
		else
		{
			delete_plt(pmap, plt);
			free(buf);
			return (0);
		}
		free(buf);
	}
	return (0);
}
