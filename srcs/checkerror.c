/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:04:51 by alilin            #+#    #+#             */
/*   Updated: 2021/03/16 19:39:44 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void	ft_checkdigit(char **av, int i)
{
	int			j;

	j = 0;
	while (av[i][j])
	{
		if (av[i][j] < 48 || av[i][j] > 57)
		{
			if (j != 0 || (j == 0 && av[i][j] != 45))
				ft_error(av, NULL, NULL, 0);
		}
		j++;
	}
}

void	ft_checkerror(char **av)
{
	int			i;
	int			j;
	long long	tmp;

	i = 0;
	while (av[i])
	{
		ft_checkdigit(av, i);
		j = i - 1;
		while (j > -1)
		{
			if (!ft_strcmp(av[i], av[j]))
				ft_error(av, NULL, NULL, 0);
			j--;
		}
		tmp = ft_atoi(av[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			ft_error(av, NULL, NULL, 0);
		i++;
	}
}
