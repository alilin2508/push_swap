/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:57:22 by alilin            #+#    #+#             */
/*   Updated: 2021/03/05 12:25:27 by alilin           ###   ########.fr       */
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

	}
}

void 	ft_sort_pile(t_pile *pileA)
{
	if (is_sorted(pileA) == 0)
		return;
	if (pile_len(pileA) <= 3)
		quick_sort(pileA);
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
