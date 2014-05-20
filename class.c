/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 22:07:30 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/02/23 23:02:34 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_salle		*ft_init_salle(t_salle *salle)
{
	t_salle		*tmp;

	tmp = (t_salle*)malloc(sizeof(t_salle));
	tmp->name = ft_strdup(salle->name);
	tmp->nb_ant = salle->nb_ant;
	tmp->bol = salle->bol;
	tmp->poids = salle->poids;
	tmp->link = salle->link;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

static t_salle		*add_mayon(t_salle *res, t_salle *salle, int a)
{
	t_salle		*tmp;
	t_salle		*tmp2;

	if (!a)
		return (ft_init_salle(salle));
	else if (a == 1)
	{
		tmp = ft_init_salle(salle);
		tmp->prev = res;
		tmp->next = NULL;
		res->next = tmp;
	}
	else
	{
		tmp2 = res;
		while (tmp2->next->next)
			tmp2 = tmp2->next;
		tmp = ft_init_salle(salle);
		tmp->prev = tmp2;
		tmp->next = tmp2->next;
		tmp2->next = tmp;
		tmp2->next->prev = tmp;
	}
	return (res);
}

static t_salle		*class_salle(t_salle *result, int *i, t_salle *tmp)
{
	while (tmp)
	{
		if (tmp->bol == 1 && !(*i))
		{
			(*i)++;
			result = add_mayon(result, tmp, 0);
		}
		else if (tmp->bol == 0 && *i == 1)
		{
			(*i)++;
			result = add_mayon(result, tmp, 1);
		}
		else if (*i == 2)
		{
			if (check(tmp, result))
				result = add_mayon(result, tmp, 2);
		}
		tmp = tmp->next;
	}
	return (result);
}

t_salle				*classer(t_salle *salle)
{
	t_salle		*tmp;
	t_salle		*result;
	int			i;

	i = 0;
	while (1)
	{
		tmp = salle;
		result = class_salle(result, &i, tmp);
		if (i == 2)
		{
			if (checking(result, salle))
				break ;
		}
	}
	return (result);
}
