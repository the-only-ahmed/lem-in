/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 02:55:23 by jyim              #+#    #+#             */
/*   Updated: 2014/03/22 08:56:27 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		count_tabw(t_way **way)
{
	int		i;

	i = 0;
	if (way == NULL)
		return (0);
	while (way[i])
		i++;
	return (i);
}

t_way			**realloc_way(t_way **way, t_way *l)
{
	t_way	**tmp;
	int		i;

	i = 0;
	tmp = (t_way **)malloc(sizeof(t_way *) * (count_tabw(way) + 2));
	if (way)
	{
		while (way[i])
		{
			tmp[i] = way[i];
			i++;
		}
	free(way);
	}
	tmp[i] = l;
	tmp[i + 1] = NULL;
	return (tmp);
}

t_way			*ft_sort(t_way *l)
{
	while (l->next)
		l = l->next;
	return (l);
}

void	print_sec(char *end, int ant)
{
	int		i;

	i = 1;
	while (i <= ant)
	{
		ft_putstr("L");
		ft_putnbr(i);
		ft_putstr("-");
		ft_putendl(end);
		i++;
	}
}

void	aff_pars(t_pars *l)
{
	if (!l)
	{
		ft_putchar('\n');
		return ;
	}
	else
	{
		ft_putendl(l->s);
		aff_pars(l->next);
	}
}
