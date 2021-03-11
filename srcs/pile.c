/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:46:10 by alilin            #+#    #+#             */
/*   Updated: 2021/03/11 12:48:49 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

t_pile	*init_pile(void)
{
	t_pile		*pile;

	if (!(pile = malloc(sizeof(*pile))))
		ft_malloc_error();
	pile->first = NULL;
	return (pile);
}

void	ft_pile(t_pile *pile, int newnb)
{
	t_element	*new;

	if (!(new = malloc(sizeof(*new))))
		ft_malloc_error();
	if (pile == NULL)
		return ;
	new->nb = newnb;
	new->next = pile->first;
	pile->first = new;
	return ;
}

int		ft_depile(t_pile *pile)
{
	int			nb_depile;
	t_element	*elem_depile;

	nb_depile = 0;
	if (pile == NULL)
		return (-1);
	elem_depile = pile->first;
	if (pile->first != NULL)
	{
		nb_depile = elem_depile->nb;
		pile->first = elem_depile->next;
		free(elem_depile);
	}
	return (nb_depile);
}

void	disp_pile(t_pile *pile)
{
	t_element	*elem;

	if (pile == NULL)
		return ;
	elem = pile->first;
	while (elem != NULL)
	{
		printf("%d\n", elem->nb);
		elem = elem->next;
	}
	return ;
}

int		pile_len(t_pile *pile)
{
	t_element	*elem;
	int			i;

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
