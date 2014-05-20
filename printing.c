/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 19:52:38 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/22 08:55:12 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_count		dont_know(t_way *way, int max, t_count x)
{
	while (way->next && way->next->n[0])
	{
		way->n[1] = way->next->n[1];
		PUTCHAR(x.a);
		x.a++;
		ft_printf("L%d-%s", way->n[1], way->name);
		way = way->next;
	}
	if (x.current <= max)
	{
		way->n[1] = x.current;
		PUTCHAR(x.a);
		x.a++;
		ft_printf("L%d-%s", x.current, way->name);
		x.current++;
	}
	else
	{
		way->n[0] = 0;
		way->n[1] = 0;
	}
	return (x);
}

t_count		the_else(t_way *way, int max, t_way **end, t_count x)
{
	t_way	*tmp;

	tmp = NULL;
	while (way->prev)
	{
		if (way->next && way->next->n[0] && !way->n[0])
			tmp = way;
		way = way->prev;
	}
	if (tmp)
		way = tmp;
	if (!way->prev)
	{
		(*end)->n[0]++;
		(*end)->n[1] = way->n[1];
		if ((*end)->n[1] > 0)
		{
			PUTCHAR(x.a++);
			ft_printf("L%d-%s", (*end)->n[1], (*end)->name);
			NEW_LINE(max);
		}
	}
	else
		way->n[0] = 1;
	return (dont_know(way, max, x));
}

void	the_big_while(t_way **way, t_way **end, int max, int *current)
{
	int			i;
	t_count		x;

	x.a = 0;
	x.current = *current;
	i = 0;
	while (way[i])
	{
		if (way[i]->n[0] == 0 && x.current <= max)
		{
			way[i]->n[0] = 1;
			way[i]->n[1] = x.current;
			PUTCHAR(x.a);
			x.a++;
			ft_printf("L%d-%s", x.current, way[i]->name);
			x.current++;
		}
		else
			x = the_else(way[i], max, end, x);
		i++;
	}
	*current = x.current;
}

void	to_printf(t_way **way, char *str, int max)
{
	int		i;
	int		current;
	t_way	*end;

	i = 0;
	end = (t_way *)malloc(sizeof(t_way));
	end->n = (int *)malloc(sizeof(int) * 2);
	end->name = ft_strdup(str);
	end->n[0] = 0;
	end->n[1] = 0;
	current = 1;
	while (way[i])
	{
		way[i] = ft_sort(way[i]);
		i++;
	}
	while (end->n[0] <= max)
	{
		the_big_while(way, &end, max, &current);
		ft_putchar('\n');
	}
	the_big_while(way, &end, -1, &current);
}
