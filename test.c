/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/20 04:41:38 by jyim              #+#    #+#             */
/*   Updated: 2014/03/22 08:45:47 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_link		*end_link(t_link *l, t_salle *s)
{
	t_link		*tmp;
	t_link		*tmp2;

	tmp = l;
	tmp2 = (t_link *)malloc(sizeof(t_link));
	tmp2->next = NULL;
	tmp2->target = s;
	if (l == NULL)
		return (tmp2);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	return (l);
}

t_salle				*sala(t_l *la, t_salle *salle)
{
	t_salle		*tmp;
	t_salle		*tmp2;

	while (la)
	{
		tmp = salle;
		while (tmp)
		{
			if (!ft_strcmp(tmp->name, la->n1))
			{
				tmp2 = salle;
				while (tmp2)
				{
					if (!ft_strcmp(tmp2->name, la->n2))
						break ;
					tmp2 = tmp2->next;
				}
				if (tmp2 && tmp)
				{
					tmp->link = end_link(tmp->link, tmp2);
					tmp2->link = end_link(tmp2->link, tmp);
				}
				else
				{
					ft_printf("Map error !\n");
					exit(0);
				}
			}
			tmp = tmp->next;
		}
		la = la->next;
	}
	return (salle);
}

t_way			*end_way(t_way *l, char *name, int b)
{
	t_way	*tmp;
	t_way	*tmp2;

	tmp = l;
	tmp2 = (t_way *)malloc(sizeof(t_way));
	tmp2->next = NULL;
	tmp2->prev = NULL;
	tmp2->name = ft_strdup(name);
	if (b != 1)
	{
		tmp2->n = (int *)malloc(sizeof(int) * 2);
		tmp2->n[0] = 0;
		tmp2->n[1] = 0;
	}
	if (l == NULL)
		return (tmp2);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	tmp2->prev = tmp;
	return (l);
}
