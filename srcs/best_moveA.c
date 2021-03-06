/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_moveA.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:50:47 by alilin            #+#    #+#             */
/*   Updated: 2021/03/06 12:00:00 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int		idx_from_startA(int	*tab, int len, int min, int max, int flag, int *index)
{
	int						i;

	i = 0;
	while (i < len / 2)
	{
		if (tab[i] >= tab[min] && tab[i] < (tab[max] / 5) && flag > 1)
		{
			flag = 1;
			*index = i;
		}
		else if (tab[i] >= (tab[max] / 5) && tab[i] < ((tab[max] / 5) * 2) && flag > 2)
		{
			flag = 2;
			*index = i;
		}
		else if (tab[i] >= ((tab[max] / 5) * 2) && tab[i] <= ((tab[max] / 5) * 3) && flag > 3)
		{
			flag = 3;
			*index = i;
		}
		else if (tab[i] >= ((tab[max] / 5) * 3) && tab[i] <= ((tab[max] / 5) * 4) && flag > 4)
		{
			flag = 4;
			*index = i;
		}
		else if (tab[i] >= ((tab[max] / 5) * 4) && tab[i] <= tab[max] && flag == 5)
		{
			flag = 5;
			*index = i;
		}
		i++;
	}
	return (flag);
}

int		idx_from_endA(int	*tab, int len, int min, int max, int flag, int index)
{
	int i;

	i = len - 1;
	while (i >= len / 2)
	{
		if (tab[i] >= tab[min] && tab[i] < (tab[max] / 5) && (len - i) < index && flag > 1)
		{
			flag = 1;
			index = i;
		}
		else if (tab[i] >= (tab[max] / 5) && tab[i] < ((tab[max] / 5) * 2) && (len - i) < index && flag > 2)
		{
			flag = 2;
			index = i;
		}
		else if (tab[i] >= ((tab[max] / 5) * 2) && tab[i] <= ((tab[max] / 5) * 3) && (len - i) < index && flag > 3)
		{
			flag = 3;
			index = i;
		}
		else if (tab[i] >= ((tab[max] / 5) * 3) && tab[i] <= ((tab[max] / 5) * 4) && (len - i) < index && flag > 4)
		{
			flag = 4;
			index = i;
		}
		else if (tab[i] >= ((tab[max] / 5) * 4) && tab[i] <= tab[max] && (len - i) < index && flag == 5)
		{
			flag = 5;
			index = i;
		}
		i--;
	}
	return (index);
}

int 	best_move_a(t_pile *pileA, int len)
{
	int 					tab[len + 1];
	t_element 		*elem;
	int 					index;
	int						i;
	int 					flag;


	i = 0;
	elem = pileA->first;
	while (elem != NULL)
	{
		tab[i] = elem->nb;
		elem = elem->next;
		i++;
	}
	index = 0;
	flag = idx_from_startA(tab, len, find_min_id(pileA), find_max_id(pileA), 5, &index);
	index = idx_from_endA(tab, len, find_min_id(pileA), find_max_id(pileA), flag, index);
	exec_ra_rra(pileA, len, index);
	elem = pileA->first;
	return (elem->nb);
}
