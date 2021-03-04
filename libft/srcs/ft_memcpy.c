/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:51:23 by alilin            #+#    #+#             */
/*   Updated: 2021/03/04 15:51:25 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dupdst;

	dupdst = (unsigned char *)dst;
	while (n-- > 0)
	{
		*dupdst = *(unsigned char *)src;
		dupdst++;
		src++;
	}
	return (dst);
}
