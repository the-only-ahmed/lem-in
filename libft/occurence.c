/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occurence.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:23:46 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/02/21 09:57:49 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_occ_nb(const char *str, char c)
{
	int		i;
	int		x;

	i = x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			x++;
		i++;
	}
	return (x);
}
