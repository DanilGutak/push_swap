/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:02:15 by dgutak            #+#    #+#             */
/*   Updated: 2023/09/29 17:18:57 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	int	i;

	i = data->stack_a_count - 1;
	if (data->stack_a_count == 1)
		data->stack_a[1] = data->stack_a[0];
	else
	{
		while (i > 0)
		{
			data->stack_a[i] = data->stack_a[i - 1];
			i--;
		}
	}
	data->stack_a[0] = data->stack_b[0];
	data->stack_a_count++;
	i = 0;
	while (i < data->stack_b_count - 1)
	{
		data->stack_b[i] = data->stack_b[i + 1];
		i++;
	}
	data->stack_b_count--;
}

void	pb(t_data *data)
{
	int i;

	i = data->stack_b_count - 1;
	if (data->stack_b_count == 1)
		data->stack_b[1] = data->stack_b[0];
	else
	{
		while (i > 0)
		{
			data->stack_b[i] = data->stack_b[i - 1];
			i--;
		}
	}
	data->stack_b[0] = data->stack_a[0];
	data->stack_b_count++;
	i = 0;
	while (i < data->stack_a_count - 1)
	{
		data->stack_a[i] = data->stack_a[i + 1];
		i++;
	}
	data->stack_a_count--;
}