/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:52:28 by alilin            #+#    #+#             */
/*   Updated: 2021/03/10 14:26:18 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int		find_max_id(t_pile *pile)
{
	int			i;
	int			tmp;
	int			index;
	t_element	*elem;

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

int		find_min_id(t_pile *pile)
{
	int			i;
	int			tmp;
	int			index;
	t_element	*elem;

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

int		find_min_nb(t_pile *pile)
{
	int			i;
	int			tmp;
	t_element	*elem;

	i = 0;
	elem = pile->first;
	tmp = elem->nb;
	while (i < pile_len(pile) - 1)
	{
		elem = elem->next;
		i++;
		if (tmp > elem->nb)
			tmp = elem->nb;
	}
	return (tmp);
}

int		find_max_nb(t_pile *pile)
{
	int			i;
	int			tmp;
	t_element	*elem;

	i = 0;
	elem = pile->first;
	tmp = elem->nb;
	while (i < pile_len(pile) - 1)
	{
		elem = elem->next;
		i++;
		if (tmp < elem->nb)
			tmp = elem->nb;
	}
	return (tmp);
}
