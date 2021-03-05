/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:43:18 by alilin            #+#    #+#             */
/*   Updated: 2021/03/05 11:40:24 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void 	ft_error()
{
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

void 	ft_ko()
{
	printf("KO\n");
	exit (EXIT_FAILURE);
}

void 	ft_ok()
{
	printf("OK\n");
	exit (EXIT_SUCCESS);
}
