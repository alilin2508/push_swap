/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:21:56 by alilin            #+#    #+#             */
/*   Updated: 2021/03/10 13:52:13 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int		*fill_tab(int *tab, t_pile *pile, int len)
{
	int			i;
	t_element	*elem;

	i = 0;
	elem = pile->first;
	while (i < len)
	{
		tab[i] = elem->nb;
		elem = elem->next;
		i++;
	}
	return (tab);
}

int		calc_r_rr(int len_a, int index_a, int index_b, int len_b)
{
	int			index;

	index = 0;
	if (index_a > len_a / 2 && index_b > len_b / 2)
	{
		if (len_a - index_a > len_b - index_b)
			index = calc_ra_rra(len_a, index_a);
		else
			index = calc_rb_rrb(len_b, index_b);
	}
	else if (index_a <= len_a / 2 && index_b <= len_b / 2)
	{
		if (index_a < index_b)
			index = calc_rb_rrb(len_b, index_b);
		else
			index = calc_ra_rra(len_a, index_a);
	}
	else
		index = calc_ra_rra(len_a, index_a) + calc_rb_rrb(len_b, index_b);
	return (index);
}

int		place_in_pile_b(t_pile *pile_b, t_pile *pile_a, int len, int index_a)
{
	int				index;
	int				i;
	int				nb;
	t_element		*elem;

	if (len < 2)
		return (0);
	i = 0;
	elem = pile_a->first;
	while (i <= index_a)
	{
		nb = elem->nb;
		elem = elem->next;
		i++;
	}
	index = find_min_nb_id(pile_b, nb);
	if (index != -1)
		return (index);
	else
		return (find_max_id(pile_b));
}

int		place_in_pile_a(t_pile *pile_a, t_pile *pile_b, int len, int index_b)
{
	int				index;
	int				i;
	int				nb;
	t_element		*elem;

	if (len < 2)
		return (0);
	i = 0;
	elem = pile_b->first;
	while (i <= index_b)
	{
		nb = elem->nb;
		elem = elem->next;
		i++;
	}
	index = find_max_nb_id(pile_a, nb);
	if (index != -1)
		return (index);
	else
		return (find_min_id(pile_a));
}

void	insert_leftover_to_b(t_pile *pile_a, t_pile *pile_b)
{
	int				index;

	index = 0;
	while (pile_len(pile_a) > 2)
	{
		index = find_min_id(pile_a);
		if (index == 0)
			ft_exec("pb", pile_a, pile_b, 0);
		else if (index <= pile_len(pile_a) / 2)
			ft_exec("ra", pile_a, pile_b, 0);
		else if (index > pile_len(pile_a) / 2)
			ft_exec("rra", pile_a, pile_b, 0);
	}
}
