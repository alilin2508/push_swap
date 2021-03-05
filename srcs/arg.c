/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:33:39 by alilin            #+#    #+#             */
/*   Updated: 2021/03/05 11:25:28 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int			ft_nb_cmd(char **av, int i, int j, int len)
{
	while (av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] == ' ')
			{
				while(av[i][j + 1] == ' ')
					j++;
				if (av[i][j + 1] != '\0')
					len++;
			}
			j++;
		}
		len++;
		i++;
	}
	return (len);
}

char		**get_cmd(char **av, int i, int j, int j_cmd)
{
	char  **cmd;
	int index_cmd;
	int len;

	index_cmd = 0;
	len = ft_nb_cmd(av, 1, 0, 0);
	cmd = malloc(sizeof(char *) * (len + 1));
	while (av[i])
	{
		cmd[index_cmd] = malloc(sizeof(char) * (ft_strlen(av[i]) + 1));
		j = 0;
		j_cmd = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ')
			{
				cmd[index_cmd][j_cmd] = av[i][j];
				j_cmd++;
			}
			else
			{
				while (av[i][j + 1] == ' ')
				j++;
				if (av[i][j + 1] != '\0')
				{
					cmd[index_cmd][j_cmd] = '\0';
					j_cmd = 0;
					index_cmd++;
					cmd[index_cmd] = malloc(sizeof(char) * (ft_strlen(&av[i][j]) + 1));
				}
			}
			j++;
		}
		cmd[index_cmd][j_cmd] = '\0';
		index_cmd++;
		i++;
	}
	cmd[index_cmd] = NULL;
	return (cmd);
}

int			ft_tablen(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

t_pile	*init_arg(char **av)
{
	t_pile 	*pileA;
	char 		**arg;
	int 		i;

	arg = get_cmd(av, 1, 0, 0);
	ft_checkerror(arg);
	pileA = init_pile();
	i = ft_tablen(arg) - 1;
	while (i > -1)
	{
		ft_pile(pileA, ft_atoi(arg[i]));
		i--;
	}
	ft_splitdel(&arg);
	return (pileA);
}
