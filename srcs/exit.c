/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:43:18 by alilin            #+#    #+#             */
/*   Updated: 2021/03/09 14:16:55 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void 	ft_error(t_pile *pileA, t_pile *pileB)
{
	write(2, "Error\n", 6);
	ft_free(pileA);
	ft_free(pileB);
	exit (EXIT_FAILURE);
}

void 	ft_ko(t_pile *pileA, t_pile *pileB)
{
	printf("KO\n");
	ft_free(pileA);
	ft_free(pileB);
	exit (EXIT_FAILURE);
}

void 	ft_ok(t_pile *pileA, t_pile *pileB)
{
	printf("OK\n");
	ft_free(pileA);
	ft_free(pileB);
	exit (EXIT_SUCCESS);
}

void 	ft_free(t_pile *pile)
{
	while (pile_len(pile) != 0)
		ft_depile(pile);
	free(pile);
}
