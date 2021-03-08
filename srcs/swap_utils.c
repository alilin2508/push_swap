/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:52:28 by alilin            #+#    #+#             */
/*   Updated: 2021/03/08 13:52:36 by alilin           ###   ########.fr       */
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

int 	find_min_nb(t_pile *pile)
{
	int				i;
	int 			tmp;
	t_element *elem;

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

int 	find_min_nb_id(t_pile *pile, int nb)
{
	int				i;
	int				index;
	int				tmp;
	t_element *elem;

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

void 	exec_rb_rrb(t_pile *pile, int len, int index)
{
	int 	i;

	i = 0;
	if (index >= len / 2)
	{
		while (i < len - index)
		{
			ft_exec("rrb", NULL, pile, 0);
			i++;
		}
	}
	else
	{
		while (i < index)
		{
			ft_exec("rb", NULL, pile, 0);
			i++;
		}
	}
}
