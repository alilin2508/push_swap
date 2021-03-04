/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:53:22 by alilin            #+#    #+#             */
/*   Updated: 2021/03/04 15:53:25 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_words(char const *s, char c)
{
	int		size;
	int		i;
	char	*word;

	size = 0;
	i = 0;
	while (s[size] && s[size] != c)
		size++;
	if (!(word = (char *)malloc(sizeof(char *) * (size + 1))))
		return (0);
	i = 0;
	while (*s && *s != c)
	{
		word[i] = *s;
		i++;
		s++;
	}
	word[i] = '\0';
	return (word);
}

static int			ft_words_count(char const *s, char c)
{
	int		count;
	int		j;

	j = 0;
	count = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j] && s[j] != c)
		{
			count++;
			while (s[j] && s[j] != c)
				j++;
		}
	}
	return (count);
}

char				**ft_split(char const *s, char c)
{
	char	**tab;
	int		nb_words;
	int		i;
	int		j;

	nb_words = ft_words_count(s, c);
	if (!(tab = (char **)malloc(sizeof(char*) * (nb_words + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j] && s[j] != c)
		{
			(tab[i] = ft_words(&s[j], c));
			i++;
			while (s[j] && s[j] != c)
				j++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
