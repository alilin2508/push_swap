/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:52:28 by alilin            #+#    #+#             */
/*   Updated: 2021/03/06 11:59:36 by alilin           ###   ########.fr       */
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

void 	exec_ra_rra(t_pile *pile, int len, int index)
{
	int 	i;

	i = 0;
	if (index >= len / 2)
	{
		while (i < len - index)
		{
			ft_exec("rra", pile, NULL, 0);
			i++;
		}
	}
	else
	{
		while (i < index)
		{
			ft_exec("ra", pile, NULL, 0);
			i++;
		}
	}
}
