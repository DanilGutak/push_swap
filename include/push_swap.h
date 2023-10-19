/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:58:53 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/19 10:55:02 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
#include "get_next_line.h"


int			*new_strmapi(char **s, long int (*f)(char *), t_data *data, int i);
long int	atoi_new(char *str);
void		free_double_p(char **p);
void		error(t_data *data, int status);
void		sort_for_index(t_data *data);
void		sort_small(t_data *data);
void		push_a(t_data *data, int i);
void		push_b(t_data *data, int start, int end, int i);
void		is_sorted(t_data *data);
void		check_duplicate(t_data *data);
void		run_n(t_data *data, int n, void (*f)(t_data *));
/* funcs */
void		action(t_data *data, char *cmd);
void		rrb(t_data *data);
void		rra(t_data *data);
void		rrr(t_data *data);
void		rb(t_data *data);
void		ra(t_data *data);
void		rr(t_data *data);
void		sb(t_data *data);
void		sa(t_data *data);
void		ss(t_data *data);
void		pa(t_data *data);
void		pb(t_data *data);

#endif