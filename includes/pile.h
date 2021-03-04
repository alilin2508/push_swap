/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:45:54 by alilin            #+#    #+#             */
/*   Updated: 2021/03/04 15:40:32 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILE_H
# define PILE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct s_element
{
    int nb;
    struct s_element *next;
}							t_element;

typedef struct s_pile
{
    t_element *first;
}							t_pile;

t_pile	*init_pile();
void 		ft_pile(t_pile *pile, int newnb);
int 		ft_depile(t_pile *pile);
void 		disp_pile(t_pile *pile);
int 		pile_len(t_pile *pile);
void 		ft_p(t_pile *pile, t_pile *depile);
void		ft_s(t_pile *pile);
void 		ft_r(t_pile *pile, int len);
void 		ft_rr(t_pile *pile, int len);
void 		ft_error();
void 		ft_ko();
void 		ft_ok();
void 		ft_exec2(char *line, t_pile *pileA, t_pile *pileB);
void 		ft_exec(char *line, t_pile *pileA, t_pile *pileB);
void 		ft_checkdigit(char **av, int i);
void 		ft_checkerror(char **av);

#endif
