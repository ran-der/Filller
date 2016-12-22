/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:40:08 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/19 19:22:21 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(void)
{
	char		pl;
	t_plateau	*plateau;

	plateau = NULL;
	while (1)
	{
		get_next_line(0, &buf);
		if (!ft_strncmp(buf, "$$$ exec p", 10))
			pl = (*(buf + 10) == '1' ? 'O' : 'X');
		else if (!ft_strncmp(buf, "Plateau ", 8))
			play(get_plt(&plateau, buf, pl));
		else
		{
			delete_plt(pmap, plateau);
			free(buf);
			return (0);
		}
		free(buf);
	}
	return (0);
}
