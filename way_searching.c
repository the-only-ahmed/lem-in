/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_searching.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 19:46:22 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/22 08:52:12 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			fill_height(t_salle *l, int i)
{
	t_link		*link;

	link = l->link;
	while (link)
	{
		if (link->target->poids == -1 || link->target->poids > i)
		{
			link->target->poids = i;
			fill_height(link->target, i + 1);
		}
		link = link->next;
	}
}

static int		fn_min(t_salle *l1)
{
	t_link		*l;
	int			p;

	l = l1->link;
	while (l->target->poids == -2)
		l = l->next;
	p = l->target->poids;
	while (l)
	{
		if (l->target->poids < p && l->target->poids != -2)
			p = l->target->poids;
		l = l->next;
	}
	return (p);
}

t_way			*dijkstra(t_salle *l, t_way *way)
{
	t_link		*link;
	int			p;

	link = l->link;
	while (link)
	{
		if (link->target->poids == -2)
		{
			link = link->next ;
			continue ;
		}
		p = fn_min(l);
		if (link->target->poids == p && link->target->bol != 1)
		{
			way = end_way(way, link->target->name, link->target->bol);
			dijkstra(link->target, way);
			return (way);
		}
		link = link->next;
	}
	return (way);
}
