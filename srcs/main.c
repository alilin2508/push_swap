/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:46:04 by alilin            #+#    #+#             */
/*   Updated: 2021/03/04 15:04:42 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void 	checker(t_pile *pileA, t_pile *pileB)
{
	int 			tmp;
	t_element *elem;

	// printf("pileA\n");
	// disp_pile(pileA);
	// printf("pileB\n");
	// disp_pile(pileB);
	if (pile_len(pileB))
		ft_ko();
	else
	{
		elem = pileA->first;
		while (elem->next != NULL)
		{
			tmp = elem->nb;
			elem = elem->next;
			if (tmp > elem->nb)
				ft_ko();
		}
		ft_ok();
	}
}

void 	loop_check(t_pile *pileA, t_pile *pileB)
{
	char		*line;

	line = NULL;
	while (42)
	{
		if (get_next_line(0, &line) == 0)
			checker(pileA, pileB);
		ft_exec(line, pileA, pileB);
		free(line);
		line = NULL;
	}
}

int		main(int ac, char **av)
{
	t_pile	*pileA;
	t_pile	*pileB;
	int			i;

	if (ac <= 1)
		return (-1);
	ft_checkerror(av);
	pileA = init_pile();
	pileB = init_pile();
	i = ac - 1;
	while (i > 0)
	{
		ft_pile(pileA, ft_atoi(av[i]));
		i--;
	}
	loop_check(pileA, pileB);
	return (0);
}
