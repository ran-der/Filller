/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 06:22:29 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/27 17:07:02 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <string.h>
# include <sys/errno.h>
# define MAX(a, b) (a >= b ? a : b)
# define MIN(a, b) (a <= b ? a : b)
# define ABS(x) (x < 0 ? -x : x)

/*
** enums:
*/

typedef enum		e_dir
{
	N,
	St,
	E,
	W,
}					t_dir;

typedef enum		e_goal
{
	center,
	contact,
	surround,
	clos,
	fill
}					t_goal;

typedef enum		e_mark
{
	far,
	fre,
	ocp,
	atwallf,
	atwallo
}					t_mark;

/*
** end enums
*/

/*
** structures:
*/

typedef struct		s_coord
{
	int				x;
	int				y;
	struct s_coord	*next;
}					t_coord;

typedef struct		s_args
{
	int				*c;
	int				*l;
	int				dl;
	int				limc;
	int				liml;
	t_coord			pnt;
}					t_args;

typedef struct		s_info
{
	char			pl;
	char			**pmap;
}					t_info;

typedef struct		s_skin
{
	t_coord			crd;
	t_dir			dir;
	t_mark			mark;
	int				sight;
	struct s_skin	*next;
	struct s_skin	*prev;
}					t_skin;

typedef struct		s_square
{
	int				n;
	int				s;
	int				e;
	int				w;
}					t_square;

typedef struct		s_ennemi
{
	t_skin			*skin;
	t_coord			epos;
	t_mark			mark;
	t_square		sqr;
}					t_ennemi;

typedef struct		s_piece
{
	t_coord			size;
	t_coord			offset;
	t_coord			*crd;
}					t_piece;

typedef struct		s_plateau
{
	char			pl;
	char			**map;
	t_coord			size;
	t_coord			ctr;
	t_piece			pce;
	t_coord			*pos;
}					t_plateau;

/*
** end structures
*/

/*
** functions:
*/

void				printlist(t_coord *list, char *name);
/*
** get_plateau.c
*/
t_plateau			get_plt(char *buff, char pl);

/*
** read.c
*/
char				**read_map(t_coord size);
t_piece				read_piece(void);
t_coord				get_size(char *buff);

/*
** coord_list.c
*/
t_coord				*new_crdlist(int x, int y);
void				crdlist_pushback(t_coord **list, t_coord *elem);
int					is_inlist(int x, int y, t_coord *list);

/*
** get_ennemi.c
*/
t_ennemi			get_ennemi(t_plateau p, char **pmap);

/*
** get_square.c
*/
t_square			get_square(t_plateau p);

/*
** get_skin.c
*/
void				get_skin(t_plateau p, t_ennemi *e);
int					is_skin(t_coord pos, t_skin *list);

/*
** skin_list.c
*/
void				skin_pushback(t_skin **skin, t_coord pnt, t_plateau p);

/*
** find_dir.c
*/
t_dir				find_dir(t_coord pnt, t_plateau p);

/*
** skin_tests.c
*/
int					is_inhole(t_coord p, t_plateau plt);
int					is_corner(t_coord pos, t_plateau p);
int					is_atwall(t_coord pos, t_plateau p);
int					is_ennemi(char c, char pl);

/*
** is_surface.c
*/
int					is_surface(t_coord p, t_plateau plt);

/*
** is_insight.c
*/
int					is_insight(t_skin pos, t_plateau p);
void				set_args(t_skin pos, t_plateau p, t_args *ag);

/*
** play.c
*/
t_coord				play(t_plateau p, t_ennemi e);

/*
** fill_area.c
*/
t_skin				fill_area(t_plateau p);

/*
** surround.c
*/
t_skin				surround_ennemi(t_plateau p, t_ennemi e);

/*
** counter.c
*/
t_skin				counter_ennemi(t_ennemi e);

/*
** delete_ft.c
*/
void				delete_crdlist(t_coord **list);
void				delete_skin(t_skin **list);
void				delete_map(char **map, int size);
void				delete_all(t_plateau p, t_ennemi e);
void				delete_elem(int x, int y, t_coord **list);

/*
** distance.c
*/
int					dmin_to_wall(t_coord pnt, t_plateau p);
double				dmin_to_skin(t_coord pnt, t_skin *grp);
double				dmin_to_coord(t_coord pnt, t_coord *grp);
double				distance_2d(t_coord p1, t_coord p2);

#endif
