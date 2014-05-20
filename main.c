/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 00:50:36 by jyim              #+#    #+#             */
/*   Updated: 2014/03/22 08:57:55 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	char		*line;
	t_pars		*l;
	t_lex		structure;

	l = NULL;
	while (get_next_line(0, &line) > 0)
	{
		l = lst_end(l, line);
		free(line);
	}
	verif_list(l);
	fill_struct(&structure, l);
	fill_salle(structure.lst, &structure);
	reso_lemin(&structure, l);
	return (0);
}
