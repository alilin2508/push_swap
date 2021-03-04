/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:48:28 by alilin            #+#    #+#             */
/*   Updated: 2021/03/04 15:13:45 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void 	ft_exec2(char *line, t_pile *pileA, t_pile *pileB)
{
	if (!ft_strcmp(line, "ra"))
		ft_r(pileA, pile_len(pileA));
	else if (!ft_strcmp(line, "rb"))
		ft_r(pileB, pile_len(pileB));
	else if (!ft_strcmp(line, "rr"))
	{
		ft_r(pileA, pile_len(pileA));
		ft_r(pileB, pile_len(pileB));
	}
	else if (!ft_strcmp(line, "rra"))
		ft_rr(pileA, pile_len(pileA));
	else if (!ft_strcmp(line, "rrb"))
		ft_rr(pileB, pile_len(pileB));
	else if (!ft_strcmp(line, "rrr"))
	{
		ft_rr(pileA, pile_len(pileA));
		ft_rr(pileB, pile_len(pileB));
	}
	else
	{
		free(line);
		ft_error();
	}
}


void	ft_exec(char *line, t_pile *pileA, t_pile *pileB)
{
	if (!ft_strcmp(line, "sa"))
		ft_s(pileA);
	else if (!ft_strcmp(line, "sb"))
		ft_s(pileB);
	else if (!ft_strcmp(line, "ss"))
	{
		ft_s(pileA);
		ft_s(pileB);
	}
	else if (!ft_strcmp(line, "pa"))
		ft_p(pileA, pileB);
	else if (!ft_strcmp(line, "pb"))
		ft_p(pileB, pileA);
	else
		ft_exec2(line, pileA, pileB);
}
