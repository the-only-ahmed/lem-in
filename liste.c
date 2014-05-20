/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 02:17:11 by jyim              #+#    #+#             */
/*   Updated: 2014/02/23 22:14:29 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	fill_salle(t_salle *l, t_lex *struc)
{
	t_salle		*tmp;
	int			x;
	int			y;

	x = 0;
	y = 0;
	tmp = l;
	while (tmp)
	{
		if (tmp->x > x)
			x = tmp->x;
		if (tmp->y > y)
			y = tmp->y;
		tmp = tmp->next;
	}
	struc->maxx = x;
	struc->maxy = y;
}

t_pars		*lst_end(t_pars *l, char *s)
{
	t_pars		*tmp;
	t_pars		*tmp2;

	tmp2 = (t_pars *)malloc(sizeof(t_pars));
	tmp2->s = ft_strdup(s);
	tmp2->next = NULL;
	tmp2->prev = NULL;
	if (l == NULL)
		return (tmp2);
	tmp = l;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	tmp2->prev = tmp;
	return (l);
}
