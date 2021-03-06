/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:46:10 by alilin            #+#    #+#             */
/*   Updated: 2021/03/06 14:03:43 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

t_pile	*init_pile()
{
	t_pile *pile;

	pile = malloc(sizeof(*pile));
	if (pile == NULL)
		return (NULL);
	pile->first = NULL;
	return (pile);
}

void 		ft_pile(t_pile *pile, int newnb)
{
	t_element *new;

	new = malloc(sizeof(*new));
	if (pile == NULL || new == NULL)
		return;
	new->nb = newnb;
	new->next = pile->first;
	pile->first = new;
	return;
}

int 		ft_depile(t_pile *pile)
{
	int 			nbDepile;
	t_element	*elemDepile;

	nbDepile = 0;
	elemDepile = pile->first;
	if (pile == NULL)
		return (-1);
	if (pile->first != NULL)
	{
		nbDepile = elemDepile->nb;
		pile->first = elemDepile->next;
		free(elemDepile);
	}
	return nbDepile;
}

void 		disp_pile(t_pile *pile)
{
	t_element *elem;

	if (pile == NULL)
		return;
	elem = pile->first;
	while (elem != NULL)
	{
		printf("%d\n", elem->nb);
		elem = elem->next;
	}
	return;
}

int 		pile_len(t_pile *pile)
{
	t_element *elem;
	int				i;

	if (pile == NULL)
		return (0);
	i = 0;
	elem = pile->first;
	while (elem != NULL)
	{
		i++;
		elem = elem->next;
	}
	return (i);
}
