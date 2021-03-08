/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:57:22 by alilin            #+#    #+#             */
/*   Updated: 2021/03/08 15:36:53 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void 	quick_sort(t_pile *pileA)
{
	register int	max_id;

	if (pile_len(pileA) == 1)
		return;
	if (pile_len(pileA) == 2)
	{
		if(pileA->first->nb > pileA->first->next->nb)
			ft_exec("sa", pileA, NULL, 0);
	}
	else
	{
		max_id = find_max_id(pileA);
		if (max_id == 0)
			ft_exec("ra", pileA, NULL, 0);
		else if (max_id == 1)
			ft_exec("rra", pileA, NULL, 0);
		if (pileA->first->nb > pileA->first->next->nb)
			ft_exec("sa", pileA, NULL, 0);
	}
}

void 	place_in_pileB(t_pile *pile, int len, int nb)
{
	int 					index;

	if (len < 2)
		return;
	index = find_min_nb_id(pile, nb);
	if (index != -1)
		exec_rb_rrb(pile, len, index);
	else
		exec_rb_rrb(pile, len, find_max_id(pile));
}

void 	place_in_pileA(t_pile *pile, int len, int nb)
{
	int 					index;

	if (len < 2)
		return;
	index = find_max_nb_id(pile, nb);
	if (index != -1)
		exec_ra_rra(pile, len, index);
	else
		exec_ra_rra(pile, len, find_min_id(pile));
}

void	insert_leftover_to_b(t_pile *pileA, t_pile *pileB)
{
	int				index;

	index = 0;
	while (pile_len(pileA) > 2)
	{
		index = find_min_id(pileA);
		if (index == 0)
			ft_exec("pb", pileA, pileB, 0);
		else if (index <= pile_len(pileA) / 2)
			ft_exec("ra", pileA, pileB, 0);
		else if (index > pile_len(pileA) / 2)
			ft_exec("rra", pileA, pileB, 0);
	}
}

void 	global_sort(t_pile *pileA)
{
	t_pile				*pileB;
	int 					mv;
	int 					optimizer;

	pileB = init_pile();
	if (pile_len(pileA) > 200)
		optimizer = 50;
	else
		optimizer = 2;
	while (pile_len(pileA) > optimizer)
 	{
		mv = best_move_a(pileA, pileB, pile_len(pileA));
		exec_ra_rra(pileA, pile_len(pileA), mv);
		place_in_pileB(pileB, pile_len(pileB), pileA->first->nb);
		ft_exec("pb", pileA, pileB, 0);
	}
	if (optimizer == 50)
		insert_leftover_to_b(pileA, pileB);
	while (pile_len(pileB) != 0)
	{
		mv = best_move_b(pileA, pileB, pile_len(pileB));
		exec_rb_rrb(pileB, pile_len(pileB), mv);
		place_in_pileA(pileA, pile_len(pileA), pileB->first->nb);
		ft_exec("pa", pileA, pileB, 0);
	}
	exec_ra_rra(pileA, pile_len(pileA), find_min_id(pileA));
}

void 	ft_sort_pile(t_pile *pileA)
{
	int						len;

	len = pile_len(pileA);
	if (is_sorted(pileA) == 0)
		return;
	if (len <= 3)
		quick_sort(pileA);
	else
		global_sort(pileA);
}

int		main(int ac, char **av)
{
	t_pile				*pileA;

	if (ac <= 1)
		return (-1);
	pileA = init_arg(av);
	ft_sort_pile(pileA);
	return (0);
}
