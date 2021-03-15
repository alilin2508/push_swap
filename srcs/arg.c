/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:33:39 by alilin            #+#    #+#             */
/*   Updated: 2021/03/15 09:56:04 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int		ft_nb_cmd(char **av, int i, int j, int len)
{
	while (av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] == ' ')
			{
				while (av[i][j + 1] == ' ')
					j++;
				if (av[i][j + 1] != '\0')
					len++;
			}
			j++;
		}
		len++;
		i++;
	}
	return (len + 1);
}

int		new_cmd2(char **cmd, char *av, int **index_cmd, int *j_cmd)
{
	cmd[**index_cmd][*j_cmd] = '\0';
	*j_cmd = 0;
	**index_cmd += 1;
	if (!(cmd[**index_cmd] =
			(char *)malloc(sizeof(char *) * (ft_strlen(av) + 1))))
		return (-1);
	return (0);
}

int		new_cmd(char **cmd, char *av, int *index_cmd, int j)
{
	int		j_cmd;

	j_cmd = 0;
	while (av[j])
	{
		if (av[j] != ' ')
		{
			cmd[*index_cmd][j_cmd] = av[j];
			j_cmd++;
		}
		else
		{
			while (av[j + 1] == ' ')
				j++;
			if (av[j + 1] != '\0')
				if (new_cmd2(cmd, &av[j], &index_cmd, &j_cmd) == -1)
					return (-1);
		}
		j++;
	}
	cmd[*index_cmd][j_cmd] = '\0';
	return (0);
}

char	**get_cmd(char **av, int i, int index_cmd)
{
	char	**cmd;
	int		j;

	if (!(cmd = malloc(sizeof(char *) * (ft_nb_cmd(av, 1, 0, 0) + 1))))
		return (NULL);
	while (av[i])
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j] == '\0')
		{
			write(2, "Error\n", 6);
			exit(-1);
		}
		if (!(cmd[index_cmd] = malloc(sizeof(char) * (ft_strlen(av[i]) + 1))))
			return (NULL);
		if (new_cmd(cmd, av[i], &index_cmd, j) == -1)
			return (NULL);
		index_cmd++;
		i++;
	}
	cmd[index_cmd] = NULL;
	return (cmd);
}

t_pile	*init_arg(char **av)
{
	t_pile	*pile_a;
	char	**arg;
	int		i;

	arg = get_cmd(av, 1, 0);
	ft_checkerror(arg);
	pile_a = init_pile();
	i = ft_tablen(arg) - 1;
	while (i > -1)
	{
		ft_pile(pile_a, ft_atoi(arg[i]));
		i--;
	}
	ft_splitdel(&arg);
	return (pile_a);
}
