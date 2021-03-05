/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:48:28 by alilin            #+#    #+#             */
/*   Updated: 2021/03/05 12:26:12 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void 	ft_exec2(char *line, t_pile *pileA, t_pile *pileB, int flag)
{
	if (!ft_strcmp(line, "ra"))
		ft_r(pileA, pile_len(pileA), line);
	else if (!ft_strcmp(line, "rb"))
		ft_r(pileB, pile_len(pileB), line);
	else if (!ft_strcmp(line, "rr"))
	{
		ft_r(pileA, pile_len(pileA), line);
		ft_r(pileB, pile_len(pileB), NULL);
	}
	else if (!ft_strcmp(line, "rra"))
		ft_rr(pileA, pile_len(pileA), line);
	else if (!ft_strcmp(line, "rrb"))
		ft_rr(pileB, pile_len(pileB), line);
	else if (!ft_strcmp(line, "rrr"))
	{
		ft_rr(pileA, pile_len(pileA), line);
		ft_rr(pileB, pile_len(pileB), NULL);
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
		ft_s(pileA, line);
	else if (!ft_strcmp(line, "sb"))
		ft_s(pileB, line);
	else if (!ft_strcmp(line, "ss"))
	{
		ft_s(pileA, line);
		ft_s(pileB, NULL);
	}
	else if (!ft_strcmp(line, "pa"))
		ft_p(pileA, pileB, line);
	else if (!ft_strcmp(line, "pb"))
		ft_p(pileB, pileA, line);
	else
		ft_exec2(line, pileA, pileB);
}
