/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:52:28 by alilin            #+#    #+#             */
/*   Updated: 2021/03/05 13:19:19 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int 	find_max_id(t_pile *pile)
{
	int				i;
	int 			tmp;
	int 			index;
	t_element *elem;

	i = 0;
	index = 0;
	elem = pile->first;
	tmp = elem->nb;
	while (i < pile_len(pile) - 1)
	{
		elem = elem->next;
		i++;
		if (tmp < elem->nb)
		{
			tmp = elem->nb;
			index = i;
		}
	}
	return (index);
}

int 	find_min_id(t_pile *pile)
{
	int				i;
	int 			tmp;
	int 			index;
	t_element *elem;

	i = 0;
	index = 0;
	elem = pile->first;
	tmp = elem->nb;
	while (i < pile_len(pile) - 1)
	{
		elem = elem->next;
		i++;
		if (tmp > elem->nb)
		{
			tmp = elem->nb;
			index = i;
		}
	}
	return (index);
}
