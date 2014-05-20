/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 20:29:39 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/10 08:20:29 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

typedef struct		s_count
{
	int				current;
	int				a;
}					t_count;

typedef struct		s_way
{
	char			*name;
	int				*n;
	struct s_way	*next;
	struct s_way	*prev;
}					t_way;

typedef struct		s_reso
{
	char			*n1;
	char			*n2;
	struct s_reso	*next;
	struct s_reso	*prev;
}					t_reso;

typedef struct		s_pars
{
	char			*s;
	struct s_pars	*next;
	struct s_pars	*prev;
}					t_pars;

typedef struct		s_l
{
	char			*n1;
	char			*n2;
	struct s_l		*next;
	struct s_l		*prev;
}					t_l;

typedef struct		s_link
{
	struct s_salle	*target;
	struct s_link	*next;
}					t_link;

typedef struct		s_salle
{
	char			*name;
	int				nb_ant;
	int				x;
	int				y;
	int				bol;
	int				poids;
	t_link			*link;
	struct s_salle	*next;
	struct s_salle	*prev;
}					t_salle;

typedef struct		s_lex
{
	int				fourmis;
	t_salle			*lst;
	t_l				*noeud;
	t_salle			*start;
	t_salle			*end;
	int				end_f;
	int				maxy;
	int				maxx;
}					t_lex;

#endif /* LISTS_H */
