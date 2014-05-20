/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reso.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 05:19:40 by jyim              #+#    #+#             */
/*   Updated: 2014/03/22 08:57:47 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_salle		*end_s(t_salle *l)
{
	t_salle	*tmp;

	tmp = l;
	while (tmp->next && tmp->bol != 0)
		tmp = tmp->next;
	return (tmp);
}

 t_salle		*suppr_elem(t_salle *start, t_way *way)
{
	t_salle		*tmp;
	t_way		*tmp2;

	tmp2 = way;
	while (tmp2)
	{
		tmp = start;
		while (tmp && ft_strcmp(tmp->name, way->name))
			tmp = tmp->next;
		if (tmp)
			tmp->poids = -2;
		tmp2 = tmp2->next;
	}
	return (start);
}

void			reso_lemin(t_lex *structure, t_pars *l)
{
	t_way	**way;
	t_way	*wayb;
	t_salle	*end;

	structure->lst = classer(structure->lst);
	structure->lst = sala(structure->noeud, structure->lst);
	fill_height(structure->lst, 1);
	wayb = NULL;
	way = NULL;
	end = end_s(structure->lst);
	if (end->poids == -1)
		exit(0);
	while ((wayb = dijkstra(end_s(structure->lst), wayb)))
	{
		structure->lst = suppr_elem(structure->lst, wayb);
		way = realloc_way(way, wayb);
		wayb = NULL;
	}
	aff_pars(l);
	if (!way && structure->start && end)
		print_sec(end->name, structure->fourmis);
	else
		to_printf(way, end_s(structure->lst)->name, structure->fourmis);
}
