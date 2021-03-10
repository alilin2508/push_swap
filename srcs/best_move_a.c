/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:50:47 by alilin            #+#    #+#             */
/*   Updated: 2021/03/10 13:33:33 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int		calc_place_in_pile_b(t_pile *pile, int len, int nb)
{
	int		index;

	if (len < 2)
		return (0);
	index = find_min_nb_id(pile, nb);
	if (index != -1)
		return (index);
	else
		return (find_max_id(pile));
}

int		calc_ra_rra(int len, int i)
{
	if (i > len / 2)
		return (len - i);
	return (i);
}

int		calc_move_a(t_pile *pile_a, t_pile *pile_b, int *tab, int i)
{
	int		moves;
	int		index_b;

	index_b = calc_place_in_pile_b(pile_b, pile_len(pile_b), tab[i]);
	moves = calc_r_rr(pile_len(pile_a), i, index_b, pile_len(pile_b)) + 1;
	return (moves);
}

int		best_move_a(t_pile *pile_a, t_pile *pile_b, int len_a)
{
	int		tab[len_a + 1];
	int		index;
	int		i;
	int		nb_move;

	fill_tab(tab, pile_a, pile_len(pile_a));
	nb_move = calc_move_a(pile_a, pile_b, tab, 0);
	i = 1;
	index = 0;
	while (i < pile_len(pile_a))
	{
		if (calc_move_a(pile_a, pile_b, tab, i) < nb_move)
		{
			nb_move = calc_move_a(pile_a, pile_b, tab, i);
			index = i;
		}
		i++;
	}
	return (index);
}
