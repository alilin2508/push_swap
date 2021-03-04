/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:50:53 by alilin            #+#    #+#             */
/*   Updated: 2021/03/04 15:50:55 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dupdst;
	unsigned char	*dupsrc;
	int				i;

	i = 0;
	dupdst = (unsigned char *)dst;
	dupsrc = (unsigned char *)src;
	while (n-- > 0)
	{
		dupdst[i] = dupsrc[i];
		if (dupsrc[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
