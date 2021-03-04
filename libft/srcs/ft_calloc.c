/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:48:22 by alilin            #+#    #+#             */
/*   Updated: 2021/03/04 15:48:25 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*al;
	size_t	i;

	i = 0;
	if (!(al = malloc(size * count)))
		return (0);
	while (count > i)
	{
		al[i] = 0;
		i++;
	}
	return (al);
}
