/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 06:22:29 by rvan-der          #+#    #+#             */
/*   Updated: 2016/11/26 04:42:44 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <string.h>
# include <sys/errno.h>

typedef struct			s_coord
{
	int					x;
	int					y;
	struct s_coord		*next;
}						t_coord;

typedef struct			s_piece
{
	int					x_offset;
	int					y_offset;
	t_coord				*crd;
}						t_piece;

typedef struct			s_plateau
{
	t_coord				size;
	t_coord				*ctr;
	t_coord				*epos;
	t_coord				*pos;
	t_piece				pce;
	char				**map;
	char				pl;
}						t_plateau;

#endif
