/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_rrr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:23:22 by alilin            #+#    #+#             */
/*   Updated: 2021/03/10 14:23:45 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void	exec_rrr_utils(t_pile *pile_a, t_pile *pile_b, int index_a, int index_b)
{
	int			i;
	int			len_a;
	int			len_b;

	len_a = pile_len(pile_a);
	len_b = pile_len(pile_b);
	i = 0;
	while (i < len_a - index_a && i < len_b - index_b)
	{
		ft_exec("rrr", pile_a, pile_b, 0);
		i++;
	}
	exec_ra_rra(pile_a, len_a, index_a, i);
	exec_rb_rrb(pile_b, len_b, index_b, i);
}

void	exec_rr_utils(t_pile *pile_a, t_pile *pile_b, int index_a, int index_b)
{
	int			i;
	int			len_a;
	int			len_b;

	len_a = pile_len(pile_a);
	len_b = pile_len(pile_b);
	i = 0;
	while (i < index_a && i < index_b)
	{
		ft_exec("rr", pile_a, pile_b, 0);
		i++;
	}
	exec_ra_rra(pile_a, len_a, index_a, i);
	exec_rb_rrb(pile_b, len_b, index_b, i);
}

void	exec_r_rr(t_pile *pile_a, t_pile *pile_b, int index_a, int index_b)
{
	int			len_a;
	int			len_b;

	len_a = pile_len(pile_a);
	len_b = pile_len(pile_b);
	if (index_a > len_a / 2 && index_b > len_b / 2)
		exec_rrr_utils(pile_a, pile_b, index_a, index_b);
	else if (index_a <= len_a / 2 && index_b <= len_b / 2)
		exec_rr_utils(pile_a, pile_b, index_a, index_b);
	else
	{
		exec_ra_rra(pile_a, len_a, index_a, 0);
		exec_rb_rrb(pile_b, len_b, index_b, 0);
	}
}

void	exec_ra_rra(t_pile *pile, int len, int index, int i)
{
	if (index > len / 2)
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

void	exec_rb_rrb(t_pile *pile, int len, int index, int i)
{
	if (index > len / 2)
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
