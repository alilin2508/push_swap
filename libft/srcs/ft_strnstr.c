/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:57:42 by alilin            #+#    #+#             */
/*   Updated: 2021/03/04 15:57:45 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	posi;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	posi = 0;
	while (haystack[posi] && posi < len)
	{
		j = 0;
		while (haystack[posi + j] == needle[j] && posi + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[posi]);
			j++;
		}
		posi++;
	}
	return (0);
}
