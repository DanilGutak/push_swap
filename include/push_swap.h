/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:58:53 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/02 20:57:54 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	char	*input;
	int		*stack_a;
	int		stack_a_count;
	int		*indexes;
	int		*stack_b;
	int		stack_b_count;
	int		chunk_size;
	int		chunk_num;
	int		chunk_last_size;
	int		read_chunk;
	int		end;
	char	cmd[4];
}			t_data;
int			*new_strmapi(char **s, long int (*f)(char *, t_data *),
				t_data *data);
long int	atoi_new(char *str, t_data *data);
void		free_double_p(char **p);
void		error(t_data *data, int status);
void		sort_for_index(t_data *data);
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