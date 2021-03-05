/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:47:14 by alilin            #+#    #+#             */
/*   Updated: 2021/03/05 09:48:45 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long		ft_atoi(const char *str)
{
	long long		result;
	int					i;
	int					value;

	i = 0;
	while ((str[i] > 8 && 14 > str[i]) || str[i] == 32)
		i++;
	value = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			value *= -1;
		i++;
	}
	while (str[i] > 47 && 58 > str[i])
	{
		if (str[i + 1] > 47 && 58 > str[i + 1])
			result = (result + ((char)str[i] - 48)) * 10;
		else
			result = result + ((char)str[i] - 48);
		i++;
	}
	return (result * value);
}
