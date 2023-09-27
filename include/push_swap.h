/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:58:53 by dgutak            #+#    #+#             */
/*   Updated: 2023/09/27 19:27:28 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	char	*input;
	int		*stack_a;
	int		stack_a_count;
	int		*indexes;
	int		*stack_b;
}			t_data;
int			*new_strmapi(char **s, long int (*f)(char *, t_data *),
				t_data *data);
long int	atoi_new(char *str, t_data *data);
void		free_double_p(char **p);
void		error(t_data *data, int status);

#endif