/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 06:22:29 by rvan-der          #+#    #+#             */
/*   Updated: 2016/12/22 11:56:54 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <string.h>
# include <stdio.h>
# include <sys/errno.h>
# define MAX(a, b) (a >= b ? a : b)
# define ABS(x) (x < 0 ? -x : x)

typedef enum			e_dir
{
	NE = 1,
	NW,
	SE,
	SW,
	N,
	S,
	E,
	W
}						t_dir;

typedef enum			e_goal
{
	contact = 0,
	combat,
	fill
}						t_goal;

typedef enum			e_mark
{
	atwallo,
	atwall,
	fre,
	ocp,
	eocp
}						t_mark;

typedef struct			s_coord
{
	int					x;
	int					y;
	struct s_coord		*next;
}						t_coord;

typedef struct			s_skin
{
	t_dir				dir;
	t_mark				mark;
	t_coord				crd;
	struct s_skin		*prev;
	struct s_skin		*next;
}						t_skin;

typedef struct			s_piece
{
	t_coord				size;
	t_coord				NEpole;
	t_coord				NWpole;
	t_coord				SWpole;
	t_coord				offset;
	t_coord				*crd;
}						t_piece;

/*
 * The relative coordinates of the upper left corner (SE pole) always are
 * x = 0 , y = 0 since it's the refference for the relative coordinates 
 * of the piece.
 * From this perspective, the piece's mass points approximatively
 * towards SE (down-right).
 * The relative coordinates of the other corners (or poles) depend on it's size.
 */

typedef struct			s_args
{
	int					x;
	int					y;
	int					*c;
	int					*l;
	int					dc;
	int					dl;
	int					limc;
	int					liml;
	int					lastc;


typedef struct			s_plateau
{
	t_coord				size;
	t_skin				*skins;
	t_skin				*edge[2];
	t_coord				*epos;
	t_coord				*pos;
	t_piece				pce;
	char				**pmap;
	char				**map;
	char				pl;
}						t_plateau;

t_plateau				*get_plt(t_plateau **p, char *buff, char pl, int udt);
t_piece					read_piece(void);
char					**read_map(t_coord size);
void					get_skin(t_plateau *plt);
double					distance_2d(t_coord p1, t_coord p2);
double					dmin_to_grp(t_coord pnt, t_coord *grp);
int						is_skinpnt(t_coord pnt, t_plateau *plt);
int						is_ennemi(char c, char pl);
void					delete_crdlist(t_coord *list);
t_coord					*new_crdlist(int x, int y);
void					crdlist_pushback(t_coord **list, t_coord *elem);
void					delete_map(char **map, int size);
void					delete_skin(t_skin *skin);

#endif
