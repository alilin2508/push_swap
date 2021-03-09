/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:46:04 by alilin            #+#    #+#             */
/*   Updated: 2021/03/09 14:15:47 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void 	checker(t_pile *pileA, t_pile *pileB)
{
	if (pile_len(pileB))
		ft_ko(pileA, pileB);
	else
	{
		if(is_sorted(pileA))
			ft_ko(pileA, pileB);
		ft_ok(pileA, pileB);
	}
}

void 	loop_check(t_pile *pileA, t_pile *pileB)
{
	char		*line;

	line = NULL;
	while (42)
	{
		if (get_next_line(0, &line) == 0)
			checker(pileA, pileB);
		ft_exec(line, pileA, pileB, 1);
		free(line);
		line = NULL;
	}
}

int		main(int ac, char **av)
{
	t_pile	*pileA;
	t_pile	*pileB;

	if (ac <= 1)
		return (-1);
	pileA = init_arg(av);
	pileB = init_pile();
	loop_check(pileA, pileB);
	return (0);
}
