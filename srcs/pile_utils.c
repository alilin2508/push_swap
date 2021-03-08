/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:15:22 by alilin            #+#    #+#             */
/*   Updated: 2021/03/08 11:50:22 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void 	ft_rr(t_pile *pile, int len, char *line, int flag)
{
	int 			tmp[len + 1];
	int 			i;

	i = 0;
	if (len > 1)
	{
		while(i < len)
		{
			tmp[i] = ft_depile(pile);
			i++;
		}
		i = len - 2;
		while(i >= 0)
		{
			ft_pile(pile, tmp[i]);
			i--;
		}
		ft_pile(pile, tmp[len - 1]);
		if (line != NULL && flag == 0)
			printf("%s\n", line);
	}
}

void 	ft_r(t_pile *pile, int len, char *line, int flag)
{
	int 			tmp[len + 1];
	int 			i;

	i = 0;
	if (len > 1)
	{
		while(i < len)
		{
			tmp[i] = ft_depile(pile);
			i++;
		}
		ft_pile(pile, tmp[0]);
		i--;
		while(i > 0)
		{
			ft_pile(pile, tmp[i]);
			i--;
		}
		if (line != NULL && flag == 0)
			printf("%s\n", line);
	}
}

void	ft_s(t_pile *pile, char *line, int flag)
{
	int		tmp[2];

	if (pile_len(pile) > 1)
	{
		tmp[0] = ft_depile(pile);
		tmp[1] = ft_depile(pile);
		ft_pile(pile, tmp[0]);
		ft_pile(pile, tmp[1]);
		if (line != NULL && flag == 0)
			printf("%s\n", line);
	}
}

void 	ft_p(t_pile *pile, t_pile *depile, char *line, int flag)
{
	int tmp;

	if (pile_len(depile) > 0)
	{
		tmp = ft_depile(depile);
		ft_pile(pile, tmp);
		if (flag == 0)
			printf("%s\n", line);
	}
}

int		is_sorted(t_pile *pileA)
{
	int 			tmp;
	t_element *elem;

	elem = pileA->first;
	while (elem->next != NULL)
	{
		tmp = elem->nb;
		elem = elem->next;
		if (tmp > elem->nb)
			return (1);
	}
	return (0);
}
