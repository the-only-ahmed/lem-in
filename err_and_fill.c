/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_and_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 03:20:12 by jyim              #+#    #+#             */
/*   Updated: 2014/03/10 08:02:42 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_salle		*init_salle(int bol, char *line, t_salle *tmp)
{
	tmp->name = ft_strdup(line);
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->link = NULL;
	tmp->bol = bol;
	if (bol == 0)
		tmp->poids = 0;
	if (bol == 1)
		tmp->poids = 0;
	else
		tmp->poids = -1;
	return (tmp);
}

void				verif_list(t_pars *l)
{
	t_pars		*tmp;
	int			i;
	int			x;

	i = 0;
	x = 0;
	tmp = l;
	while (tmp)
	{
		if (ft_strcmp(tmp->s, "##start") == 0)
			i++;
		else if (ft_strcmp(tmp->s, "##end") == 0)
			i++;
		else if ((ft_strchr(tmp->s, '-') != NULL) && i == 2)
		{
			x = 1;
			i++;
		}
		tmp = tmp->next;
	}
	if (i != 3 || !x)
	{
		ft_putendl("Map error.");
		exit(0);
	}
}

t_salle				*ft_atoi_int(char *s, int bol, t_salle *l)
{
	char		**line;
	t_salle		*tmp;
	t_salle		*tmp2;

	tmp2 = (t_salle *)malloc(sizeof(t_salle));
	line = ft_strsplit(s, ' ');
	if (count_tab(line) != 3)
	{
		ft_putendl("Error");
		exit(0);
	}
	tmp2 = init_salle(bol, line[0], tmp2);
	if (l == NULL)
		return (tmp2);
	tmp = l;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	tmp2->prev = tmp;
	free(line);
	return (l);
}

t_l					*add_noeud(char *line, t_l *l)
{
	char	**tab;
	t_l		*tmp;
	t_l		*tmp2;

	tab = ft_strsplit(line, '-');
	if (count_tab(tab) != 2)
	{
		ft_putendl("Parsing noeud error.");
		exit(0);
	}
	tmp2 = (t_l *)malloc(sizeof(t_l));
	tmp2->next = NULL;
	tmp2->prev = NULL;
	tmp2->n1 = ft_strdup(tab[0]);
	tmp2->n2 = ft_strdup(tab[1]);
	if (l == NULL)
		return (tmp2);
	tmp = l;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	tmp2->prev = tmp;
	return (l);
}
