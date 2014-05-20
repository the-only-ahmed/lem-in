/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   salle_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 23:00:47 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/02/23 23:01:00 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check(t_salle *salle, t_salle *res)
{
	t_salle		*tmp;

	tmp = res;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, salle->name))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		checking(t_salle *res, t_salle *salle)
{
	t_salle		*tmp;
	t_salle		*tmp2;

	tmp2 = salle;
	while (tmp2)
	{
		tmp = res;
		while (tmp)
		{
			if (!ft_strcmp(tmp->name, tmp2->name))
				break ;
			tmp = tmp->next;
		}
		if (!tmp)
			return (0);
		tmp2 = tmp2->next;
	}
	return (1);
}
