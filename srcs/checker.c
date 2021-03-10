/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:46:04 by alilin            #+#    #+#             */
/*   Updated: 2021/03/10 17:10:32 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void	checker(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_len(pile_b))
		ft_ko(pile_a, pile_b);
	else
	{
		if (is_sorted(pile_a))
			ft_ko(pile_a, pile_b);
		ft_ok(pile_a, pile_b);
	}
}

void	loop_check(t_pile *pile_a, t_pile *pile_b)
{
	char	*line;

	line = NULL;
	while (42)
	{
		if (get_next_line(0, &line) == 0)
			checker(pile_a, pile_b);
		ft_exec(line, pile_a, pile_b, 1);
		free(line);
		line = NULL;
	}
}

int		main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (ac <= 1)
		return (-1);
	pile_a = init_arg(av);
	pile_b = init_pile();
	loop_check(pile_a, pile_b);
	return (0);
}
