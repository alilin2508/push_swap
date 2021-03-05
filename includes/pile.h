/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:45:54 by alilin            #+#    #+#             */
/*   Updated: 2021/03/05 12:26:35 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILE_H
# define PILE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct 				s_element
{
    int 							nb;
    struct s_element 	*next;
}											t_element;

typedef struct 				s_pile
{
    t_element 				*first;
}											t_pile;

t_pile	*init_pile();
void 		ft_pile(t_pile *pile, int newnb);
int 		ft_depile(t_pile *pile);
void 		disp_pile(t_pile *pile);
int 		pile_len(t_pile *pile);
void 		ft_p(t_pile *pile, t_pile *depile, char *line, int flag);
void		ft_s(t_pile *pile, char *line, int flag);
void 		ft_r(t_pile *pile, int len, char *line, int flag);
void 		ft_rr(t_pile *pile, int len, char *line, int flag);
void 		ft_error();
void 		ft_ko();
void 		ft_ok();
void 		ft_exec2(char *line, t_pile *pileA, t_pile *pileB, int flag);
void 		ft_exec(char *line, t_pile *pileA, t_pile *pileB, int flag);
void 		ft_checkdigit(char **av, int i);
void 		ft_checkerror(char **av);
t_pile 	*init_arg(char **av);
char		**get_cmd(char **av, int i, int j, int j_cmd);
int			ft_nb_cmd(char **av, int i, int j, int len);
int			is_sorted(t_pile *pileA);
void 		ft_sort_pile(t_pile *pileA);

#endif
