/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:48:28 by alilin            #+#    #+#             */
/*   Updated: 2021/03/10 13:39:16 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void	ft_exec2(char *line, t_pile *pile_a, t_pile *pile_b, int flag)
{
	if (!ft_strcmp(line, "ra"))
		ft_r(pile_a, pile_len(pile_a), line, flag);
	else if (!ft_strcmp(line, "rb"))
		ft_r(pile_b, pile_len(pile_b), line, flag);
	else if (!ft_strcmp(line, "rr"))
	{
		ft_r(pile_a, pile_len(pile_a), line, flag);
		ft_r(pile_b, pile_len(pile_b), NULL, 1);
	}
	else if (!ft_strcmp(line, "rra"))
		ft_rr(pile_a, pile_len(pile_a), line, flag);
	else if (!ft_strcmp(line, "rrb"))
		ft_rr(pile_b, pile_len(pile_b), line, flag);
	else if (!ft_strcmp(line, "rrr"))
	{
		ft_rr(pile_a, pile_len(pile_a), line, flag);
		ft_rr(pile_b, pile_len(pile_b), NULL, 1);
	}
	else
	{
		free(line);
		ft_error(NULL, pile_a, pile_b);
	}
}

void	ft_exec(char *line, t_pile *pile_a, t_pile *pile_b, int flag)
{
	if (!ft_strcmp(line, "sa"))
		ft_s(pile_a, line, flag);
	else if (!ft_strcmp(line, "sb"))
		ft_s(pile_b, line, flag);
	else if (!ft_strcmp(line, "ss"))
	{
		ft_s(pile_a, line, flag);
		ft_s(pile_b, NULL, 1);
	}
	else if (!ft_strcmp(line, "pa"))
		ft_p(pile_a, pile_b, line, flag);
	else if (!ft_strcmp(line, "pb"))
		ft_p(pile_b, pile_a, line, flag);
	else
		ft_exec2(line, pile_a, pile_b, flag);
}
