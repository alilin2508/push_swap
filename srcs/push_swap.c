/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:57:22 by alilin            #+#    #+#             */
/*   Updated: 2021/03/09 14:37:33 by alilin           ###   ########.fr       */
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

int 	place_in_pileB(t_pile *pileB, t_pile *pileA, int len, int indexA)
{
	int 					index;
	int						i;
	int						nb;
	t_element 		*elem;

	if (len < 2)
		return (0);
	i = 0;
	elem = pileA->first;
	while (i <= indexA)
	{
		nb = elem->nb;
		elem = elem->next;
		i++;
	}
	index = find_min_nb_id(pileB, nb);
	if (index == len - 1 && pileB->first->nb == find_max_nb_id(pileB, nb))
		return (0);
	if (index != -1)
		return(index);
	else
		return(find_max_id(pileB));
}

int 	place_in_pileA(t_pile *pileA, t_pile *pileB, int len, int indexB)
{
	int 					index;
	int						i;
	int						nb;
	t_element 		*elem;

	if (len < 2)
		return (0);
	i = 0;
	elem = pileB->first;
	while (i <= indexB)
	{
		nb = elem->nb;
		elem = elem->next;
		i++;
	}
	index = find_max_nb_id(pileA, nb);
	if (index == len - 1 && pileA->first->nb == find_min_nb_id(pileA, nb))
		return (0);
	if (index != -1)
		return (index);
	else
		return(find_min_id(pileA));
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
	int 					optimizer;
	int 					mv;

	pileB = init_pile();
	if (pile_len(pileA) > 200)
		optimizer = 50;
	else
		optimizer = 2;
	while (pile_len(pileA) > optimizer)
	{
		mv = best_move_a(pileA, pileB, pile_len(pileA));
		exec_r_rr(pileA, pileB, mv, place_in_pileB(pileB, pileA, pile_len(pileB), mv));
		ft_exec("pb", pileA, pileB, 0);
	}
	if (optimizer == 50)
		insert_leftover_to_b(pileA, pileB);
	while (pile_len(pileB) != 0)
	{
		mv = best_move_b(pileA, pileB, pile_len(pileB));
		exec_r_rr(pileA, pileB, place_in_pileA(pileA, pileB, pile_len(pileA), mv), mv);
		ft_exec("pa", pileA, pileB, 0);
	}
	ft_free(pileB);
	exec_ra_rra(pileA, pile_len(pileA), find_min_id(pileA), 0);
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
	ft_free(pileA);
	return (0);
}
