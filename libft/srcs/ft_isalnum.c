/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:48:51 by alilin            #+#    #+#             */
/*   Updated: 2021/03/04 15:48:54 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	if ((c > 47 && 58 > c) || (c > 64 && 91 > c) || (c > 96 && 123 > c))
		return (1);
	else
		return (0);
}