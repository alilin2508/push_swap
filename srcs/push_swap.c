/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:57:22 by alilin            #+#    #+#             */
/*   Updated: 2021/03/06 14:13:58 by alilin           ###   ########.fr       */
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

void 	place_in_pile(t_pile *pile, int len)
{
	int 					index;

	if (len < 2)
		return;
	index = find_min_id(pile);
	exec_ra_rra(pile, len, index);
}

void 	global_sort(t_pile *pileA)
{
	t_pile				*pileB;

	pileB = init_pile();
	while (pile_len(pileA) != 0)
 	{
		best_move_a(pileA, pile_len(pileA));
		place_in_pile(pileB, pile_len(pileB));
		ft_exec("pb", pileA, pileB, 0);
	}
	while (pile_len(pileB) != 0)
 	{
		exec_ra_rra(pileB, pile_len(pileB), find_max_id(pileB));
		ft_exec("pa", pileA, pileB, 0);
	}
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
	// printf("pileA\n");
	// disp_pile(pileA);
	// printf("pileB\n");
	// disp_pile(pileB);
	return (0);
}
