/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:57:22 by alilin            #+#    #+#             */
/*   Updated: 2021/03/05 16:09:45 by alilin           ###   ########.fr       */
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
		max_id = find_max_id(pileA);
		if (max_id == 0)
			ft_exec("ra", pileA, NULL, 0);
		else if (max_id == 1)
			ft_exec("rra", pileA, NULL, 0);
		if (pileA->first->nb > pileA->first->next->nb)
			ft_exec("sa", pileA, NULL, 0);
	}
}

int 	best_move_a(t_pile *pileA, int len, int min, int max)
{
	int 					tab[len + 1];
	t_element 		*elem;
	int						i;
	int 					index;


	i = 0;
	elem = pileA->first;
	while (elem != NULL)
	{
		tab[i] = elem->nb;
		elem = elem->next;
		i++;
	}
	i = 0;
	index = 0;
	printf("%d\n", tab[min]);
	printf("%d\n", tab[max]);
	printf("%d\n", tab[max] / 5);
	printf("%d\n", (tab[max] / 5) * 2);
	printf("%d\n", (tab[max] / 5) * 3);
	printf("%d\n", (tab[max] / 5) * 4);
	while (i < len / 2)
	{
		if (tab[i] >= tab[min] && tab[i] < (tab[max] / 5) && i < index)
			index = i;
		else if (tab[i] >= (tab[max] / 5) && tab[i] < ((tab[max] / 5) * 2) && i < index)
			index = i;
		else if (tab[i] >= ((tab[max] / 5) * 2) && tab[i] <= ((tab[max] / 5) * 3) && i < index)
			index = i;
		else if (tab[i] >= ((tab[max] / 5) * 3) && tab[i] <= ((tab[max] / 5) * 4) && i < index)
			index = i;
		else if (tab[i] >= ((tab[max] / 5) * 4) && tab[i] <= tab[max] && i < index)
			index = i;
		printf("%d\n", index);
		i++;
	}
	i = len - 1;
	while (i >= len / 2)
	{
		if (tab[i] >= tab[min] && tab[i] < (tab[max] / 5) && (len - i) < index)
			index = i;
		else if (tab[i] >= (tab[max] / 5) && tab[i] < ((tab[max] / 5) * 2) && (len - i) < index)
			index = i;
		else if (tab[i] >= ((tab[max] / 5) * 2) && tab[i] <= ((tab[max] / 5) * 3) && (len - i) < index)
			index = i;
		else if (tab[i] >= ((tab[max] / 5) * 3) && tab[i] <= ((tab[max] / 5) * 4) && (len - i) < index)
			index = i;
		else if (tab[i] >= ((tab[max] / 5) * 4) && tab[i] <= tab[max] && (len - i) < index)
			index = i;
		i--;
	}
	i = 0;
	if (index >= len / 2)
	{
		while (i < len - index)
		{
			ft_exec("rra", pileA, NULL, 0);
			i++;
		}
	}
	else
	{
		while (i < index)
		{
			ft_exec("ra", pileA, NULL, 0);
			i++;
		}
	}
	elem = pileA->first;
	return (elem->nb);
}

void 	global_sort(t_pile *pileA)
{
	t_pile				*pileB;

	pileB = init_pile();
	//while (pile_len(pileA) != 0)
	//{
		printf("%d\n", best_move_a(pileA, pile_len(pileA), find_min_id(pileA), find_max_id(pileA)));
	//}
}

void 	ft_sort_pile(t_pile *pileA)
{
	int						len;

	len = pile_len(pileA);
	if (is_sorted(pileA) == 0)
		return;
	if (len <= 3)
		quick_sort(pileA);
	else if (len <= 100)
		global_sort(pileA);
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
