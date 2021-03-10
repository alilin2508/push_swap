/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:26:06 by alilin            #+#    #+#             */
/*   Updated: 2021/03/10 14:26:15 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int		find_min_nb_id(t_pile *pile, int nb)
{
	int			i;
	int			index;
	int			tmp;
	t_element	*elem;

	i = 0;
	index = -1;
	elem = pile->first;
	tmp = find_min_nb(pile);
	while (i < pile_len(pile))
	{
		if (elem->nb < nb && elem->nb >= tmp)
		{
			index = i;
			tmp = elem->nb;
		}
		i++;
		elem = elem->next;
	}
	return (index);
}

int		find_max_nb_id(t_pile *pile, int nb)
{
	int			i;
	int			index;
	int			tmp;
	t_element	*elem;

	i = 0;
	index = -1;
	elem = pile->first;
	tmp = find_max_nb(pile);
	while (i < pile_len(pile))
	{
		if (elem->nb > nb && elem->nb <= tmp)
		{
			index = i;
			tmp = elem->nb;
		}
		i++;
		elem = elem->next;
	}
	return (index);
}
