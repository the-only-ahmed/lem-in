/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 00:50:33 by jyim              #+#    #+#             */
/*   Updated: 2014/03/22 08:58:10 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <libft.h>
# include "lists.h"

# define PUTCHAR(a) (a? ft_putchar(' '):' ')
# define NEW_LINE(a) ((a == -1)? ft_putchar('\n'):' ')

t_pars		*lst_end(t_pars *l, char *s);
void		verif_list(t_pars *l);
t_salle		*ft_atoi_int(char *s, int bol, t_salle *l);
t_l			*add_noeud(char *line, t_l *l);
void		fill_struct(t_lex *struc, t_pars *l);
int			count_tab(char **tab);
void		reso_lemin(t_lex *structure, t_pars *l);
t_salle		*sala(t_l *la, t_salle *salle);
void		fill_height(t_salle *l, int i);
t_way		*dijkstra(t_salle *l, t_way *way);
t_way		*end_way(t_way *l, char *name, int b);
t_way		**realloc_way(t_way **way, t_way *l);
void		to_printf(t_way **way, char *end, int f);
t_way		*ft_sort(t_way *l);
t_count		dont_know(t_way *way, int max, t_count x);
t_count		the_else(t_way *way, int max, t_way **end, t_count x);
void		the_big_while(t_way **way, t_way **end, int max, int *current);
void		fill_salle(t_salle *l, t_lex *struc);

t_salle		*classer(t_salle *salle);
int			checking(t_salle *res, t_salle *salle);
int			check(t_salle *salle, t_salle *res);

void		print_sec(char *end, int ant);
void		aff_pars(t_pars *l);

#endif /* LEMIN_H */
