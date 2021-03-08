/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:50:47 by alilin            #+#    #+#             */
/*   Updated: 2021/03/08 15:01:18 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int 	calc_place_in_pileB(t_pile *pile, int len, int nb)
{
	int 					index;

	if (len < 2)
		return (0);
	index = find_min_nb_id(pile, nb);
	if (index != -1)
	{
		if (index >= len / 2)
			return (len - index);
		return (index);
	}
	else
	{
		if (find_max_id(pile) >= len / 2)
			return (len - find_max_id(pile));
		return (find_max_id(pile));
	}
}

int 	calc_ra_rra(int len, int i)
{
	if (i >= len / 2)
		return (len - i);
	return (i);
}

int			calc_move_a(t_pile *pileA, t_pile *pileB, int *tab, int i)
{
	int						moves;

	moves = calc_ra_rra(pile_len(pileA), i) + calc_place_in_pileB(pileB, pile_len(pileB), tab[i]) + 1;
	return (moves);
}

int 		best_move_a(t_pile *pileA, t_pile *pileB, int lenA)
{
	int 					tab[lenA + 1];
	t_element 		*elem;
	int 					index;
	int						i;
	int 					nb_move;


	i = 0;
	elem = pileA->first;
	while (elem != NULL)
	{
		tab[i] = elem->nb;
		elem = elem->next;
		i++;
	}
	nb_move = calc_move_a(pileA, pileB, tab, 0);
	i = 1;
	while (tab[i])
	{
		if (calc_move_a(pileA, pileB, tab, i) < nb_move)
		{
			nb_move = calc_move_a(pileA, pileB, tab, i);
			index = i;
		}
		i++;
	}
	return (index);
}
