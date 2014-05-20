/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_fill_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 19:42:42 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/10 08:10:10 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			init_lex(t_lex **struc)
{
	(*struc)->noeud = NULL;
	(*struc)->lst = NULL;
	(*struc)->start = NULL;
	(*struc)->end = NULL;
	(*struc)->end_f = 0;
}

void				fill_struct(t_lex *struc, t_pars *l)
{
	t_pars		*tmp;
	int			i;

	init_lex(&struc);
	tmp = l;
	i = 0;
	while (tmp)
	{
		if (i == 0)
		{
			if (ft_occ_nb(tmp->s, ' ') || !str_isdigit(tmp->s) || !ft_atoi(tmp->s))
			{
				ft_printf("Map Error !\n");
				exit(0);
			}
			struc->fourmis = ft_atoi(tmp->s);
		}
		else if (tmp->prev && ft_strcmp(tmp->prev->s, "##start") == 0)
		{
			struc->lst = ft_atoi_int(tmp->s, 1, struc->lst);
			struc->start = ft_atoi_int(tmp->s, 1, struc->lst);
		}
		else if (tmp->prev && ft_strcmp(tmp->prev->s, "##end") == 0)
			struc->lst = ft_atoi_int(tmp->s, 0, struc->lst);
		else if (ft_strchr(tmp->s, '-') != NULL && !ft_occ_nb(tmp->s, ' '))
			struc->noeud = add_noeud(tmp->s, struc->noeud);
		else if (!(ft_strchr(tmp->s, '#')))
			struc->lst = ft_atoi_int(tmp->s, 2, struc->lst);
		i++;
		tmp = tmp->next;
	}
}

int					count_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
