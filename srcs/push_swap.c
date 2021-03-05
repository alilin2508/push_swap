/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:57:22 by alilin            #+#    #+#             */
/*   Updated: 2021/03/05 11:19:42 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int		main(int ac, char **av)
{
	t_pile	*pileA;
	t_pile	*pileB;

	if (ac <= 1)
		return (-1);
	pileA = init_arg(av);
	pileB = init_pile();
	printf("pileA\n");
	disp_pile(pileA);
	printf("pileB\n");
	disp_pile(pileB);
	return (0);
}
