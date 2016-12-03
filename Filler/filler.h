/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 06:22:29 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/03 08:52:31 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <string.h>
# include <sys/errno.h>

typedef enum			e_wall
{
	north,
	south,
	east,
	west
}						t_wall;

typedef enum			e_goal
{
	contact = 0,
	defense,
	attack,
	fill
}						t_goal;

typedef struct			s_coord
{
	int					x;
	int					y;
	struct s_coord		*next;
}						t_coord;

typedef struct			s_skin
{
	int					ocp;
	t_coord				crd;
	struct s_skin		*prev;
	struct s_skin		*next;
}						t_skin;

typedef struct			s_piece
{
	int					x_offset;
	int					y_offset;
	t_coord				*crd;
}						t_piece;

typedef struct			s_plateau
{
	t_coord				size;
	t_skin				*skin;
	t_skin				*edge[2];
	t_coord				*epos;
	t_coord				*pos;
	t_piece				pce;
	char				**map;
	char				pl;
}						t_plateau;

#endif
