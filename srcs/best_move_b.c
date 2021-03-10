/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:45:32 by alilin            #+#    #+#             */
/*   Updated: 2021/03/10 13:31:52 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int		calc_place_in_pile_a(t_pile *pile, int len, int nb)
{
	int			index;

	if (len < 2)
		return (0);
	index = find_max_nb_id(pile, nb);
	if (index != -1)
		return (index);
	else
		return (find_min_id(pile));
}

int		calc_rb_rrb(int len, int i)
{
	if (i > len / 2)
		return (len - i);
	return (i);
}

int		calc_move_b(t_pile *pile_a, t_pile *pile_b, int *tab, int i)
{
	int			moves;
	int			index_a;

	index_a = calc_place_in_pile_a(pile_a, pile_len(pile_a), tab[i]);
	moves = calc_r_rr(pile_len(pile_a), index_a, i, pile_len(pile_b)) + 1;
	return (moves);
}

int		best_move_b(t_pile *pile_a, t_pile *pile_b, int len_b)
{
	int			tab[len_b + 1];
	int			index;
	int			i;
	int			nb_move;

	fill_tab(tab, pile_b, pile_len(pile_b));
	nb_move = calc_move_b(pile_a, pile_b, tab, 0);
	i = 1;
	index = 0;
	while (i < len_b)
	{
		if (calc_move_b(pile_a, pile_b, tab, i) < nb_move)
		{
			nb_move = calc_move_b(pile_a, pile_b, tab, i);
			index = i;
		}
		i++;
	}
	return (index);
}
