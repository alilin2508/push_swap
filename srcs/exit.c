/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:43:18 by alilin            #+#    #+#             */
/*   Updated: 2021/03/15 13:22:41 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void	ft_malloc_error(void)
{
	write(2, "malloc Error\n", 13);
	exit(EXIT_FAILURE);
}

void	ft_error(char **arg, t_pile *pile_a, t_pile *pile_b, int flag)
{
	write(2, "Error\n", 6);
	if (flag == 0)
	{
		ft_free(pile_a);
		ft_free(pile_b);
		if (arg != NULL)
			ft_splitdel(&arg);
		exit(EXIT_FAILURE);
	}
	return ;
}

void	ft_ko(t_pile *pile_a, t_pile *pile_b, char *line)
{
	printf("KO\n");
	ft_free(pile_a);
	ft_free(pile_b);
	free(line);
	exit(EXIT_FAILURE);
}

void	ft_ok(t_pile *pile_a, t_pile *pile_b, char *line)
{
	printf("OK\n");
	ft_free(pile_a);
	ft_free(pile_b);
	free(line);
	exit(EXIT_SUCCESS);
}

void	ft_free(t_pile *pile)
{
	while (pile_len(pile) != 0)
		ft_depile(pile);
	free(pile);
	return ;
}
