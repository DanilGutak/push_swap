/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:42:34 by dgutak            #+#    #+#             */
/*   Updated: 2023/09/27 20:32:56 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	int	i;
	int	temp;

	i = data->stack_a_count - 1;
	temp = data->stack_a[i];
	while (i > 0)
	{
		data->stack_a[i] = data->stack_a[i - 1];
		i--;
	}
	data->stack_a[0] = temp;
}

void	rrb(t_data *data)
{
	int	i;
	int	temp;

	i = data->stack_b_count - 1;
	temp = data->stack_b[i];
	while (i > 0)
	{
		data->stack_b[i] = data->stack_b[i - 1];
		i--;
	}
	data->stack_b[0] = temp;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
