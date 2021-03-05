/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:48:28 by alilin            #+#    #+#             */
/*   Updated: 2021/03/05 12:51:21 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void 	ft_exec2(char *line, t_pile *pileA, t_pile *pileB, int flag)
{
	if (!ft_strcmp(line, "ra"))
		ft_r(pileA, pile_len(pileA), line, flag);
	else if (!ft_strcmp(line, "rb"))
		ft_r(pileB, pile_len(pileB), line, flag);
	else if (!ft_strcmp(line, "rr"))
	{
		ft_r(pileA, pile_len(pileA), line, flag);
		ft_r(pileB, pile_len(pileB), NULL, flag);
	}
	else if (!ft_strcmp(line, "rra"))
		ft_rr(pileA, pile_len(pileA), line, flag);
	else if (!ft_strcmp(line, "rrb"))
		ft_rr(pileB, pile_len(pileB), line, flag);
	else if (!ft_strcmp(line, "rrr"))
	{
		ft_rr(pileA, pile_len(pileA), line, flag);
		ft_rr(pileB, pile_len(pileB), NULL, flag);
	}
	else
	{
		free(line);
		ft_error();
	}
}


void	ft_exec(char *line, t_pile *pileA, t_pile *pileB, int flag)
{
	if (!ft_strcmp(line, "sa"))
		ft_s(pileA, line, flag);
	else if (!ft_strcmp(line, "sb"))
		ft_s(pileB, line, flag);
	else if (!ft_strcmp(line, "ss"))
	{
		ft_s(pileA, line, flag);
		ft_s(pileB, NULL, flag);
	}
	else if (!ft_strcmp(line, "pa"))
		ft_p(pileA, pileB, line, flag);
	else if (!ft_strcmp(line, "pb"))
		ft_p(pileB, pileA, line, flag);
	else
		ft_exec2(line, pileA, pileB, flag);
}
