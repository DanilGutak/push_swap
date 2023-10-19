/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:42:34 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/19 12:01:21 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	int	i;
	int	temp;

	if (data->stack_a_count == 0)
		return;
	i = data->stack_a_count - 1;
	temp = data->stack_a[i];
	while (i > 0)
	{
		data->stack_a[i] = data->stack_a[i - 1];
		i--;
	}
	data->stack_a[0] = temp;
	if (data->flag == 0)
		action(data, "rra");
}

void	rrb(t_data *data)
{
	int	i;
	int	temp;

	if (data->stack_b_count == 0)
		return;
	i = data->stack_b_count - 1;
	temp = data->stack_b[i];
	while (i > 0)
	{
		data->stack_b[i] = data->stack_b[i - 1];
		i--;
	}
	data->stack_b[0] = temp;
	if (data->flag == 0)
		action(data, "rrb");
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
