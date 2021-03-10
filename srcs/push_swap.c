/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:57:22 by alilin            #+#    #+#             */
/*   Updated: 2021/03/10 16:47:44 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void	quick_sort(t_pile *pile_a)
{
	register int	max_id;

	if (pile_len(pile_a) == 1)
		return ;
	if (pile_len(pile_a) == 2)
	{
		if (pile_a->first->nb > pile_a->first->next->nb)
			ft_exec("sa", pile_a, NULL, 0);
	}
	else
	{
		max_id = find_max_id(pile_a);
		if (max_id == 0)
			ft_exec("ra", pile_a, NULL, 0);
		else if (max_id == 1)
			ft_exec("rra", pile_a, NULL, 0);
		if (pile_a->first->nb > pile_a->first->next->nb)
			ft_exec("sa", pile_a, NULL, 0);
	}
}

void	global_sort(t_pile *pile_a)
{
	t_pile			*pile_b;
	int				optimizer;
	int				mv;

	pile_b = init_pile();
	optimizer = (pile_len(pile_a) > 200) ? 50 : 2;
	while (pile_len(pile_a) > optimizer)
	{
		mv = best_move_a(pile_a, pile_b, pile_len(pile_a));
		exec_r_rr(pile_a, pile_b, mv, place_in_pile_b(pile_b, pile_a, \
					pile_len(pile_b), mv));
		ft_exec("pb", pile_a, pile_b, 0);
	}
	if (optimizer == 50)
		insert_leftover_to_b(pile_a, pile_b);
	while (pile_len(pile_b) != 0)
	{
		mv = best_move_b(pile_a, pile_b, pile_len(pile_b));
		exec_r_rr(pile_a, pile_b, place_in_pile_a(pile_a, pile_b, \
					pile_len(pile_a), mv), mv);
		ft_exec("pa", pile_a, pile_b, 0);
	}
	ft_free(pile_b);
	exec_ra_rra(pile_a, pile_len(pile_a), find_min_id(pile_a), 0);
}

void	ft_sort_pile(t_pile *pile_a)
{
	int				len;

	len = pile_len(pile_a);
	if (is_sorted(pile_a) == 0)
		return ;
	if (len <= 3)
		quick_sort(pile_a);
	else
		global_sort(pile_a);
}

int		main(int ac, char **av)
{
	t_pile			*pile_a;

	if (ac <= 1)
		return (-1);
	pile_a = init_arg(av);
	ft_sort_pile(pile_a);
	ft_free(pile_a);
	return (0);
}
