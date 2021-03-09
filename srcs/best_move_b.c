/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:45:32 by alilin            #+#    #+#             */
/*   Updated: 2021/03/09 14:37:27 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int 	calc_place_in_pileA(t_pile *pile, int len, int nb)
{
	int 					index;

	if (len < 2)
		return (0);
	index = find_max_nb_id(pile, nb);
	if (index == len - 1 && pile->first->nb == find_min_nb_id(pile, nb))
		return (0);
	if (index != -1)
	{
		if (index > len / 2)
			return (len - index);
		return (index);
	}
	else
	{
		if (find_min_id(pile) > len / 2)
			return (len - find_min_id(pile));
		return (find_min_id(pile));
	}
}

int 	calc_rb_rrb(int len, int i)
{
	if (i > len / 2)
		return (len - i);
	return (i);
}

int			calc_move_b(t_pile *pileA, t_pile *pileB, int *tab, int i)
{
	int						moves;

	moves = calc_rb_rrb(pile_len(pileB), i) + calc_place_in_pileA(pileA, pile_len(pileA), tab[i]) + 1;
	return (moves);
}

int 		best_move_b(t_pile *pileA, t_pile *pileB, int lenB)
{
	int 					tab[lenB + 1];
	t_element 		*elem;
	int 					index;
	int						i;
	int 					nb_move;


	i = 0;
	elem = pileB->first;
	while (i < pile_len(pileB))
	{
		tab[i] = elem->nb;
		elem = elem->next;
		i++;
	}
	nb_move = calc_move_b(pileA, pileB, tab, 0);
	i = 1;
	index = 0;
	while (i < pile_len(pileB))
	{
		if (calc_move_b(pileA, pileB, tab, i) < nb_move)
		{
			nb_move = calc_move_b(pileA, pileB, tab, i);
			index = i;
		}
		i++;
	}
	return (index);
}
