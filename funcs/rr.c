/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:34:13 by dgutak            #+#    #+#             */
/*   Updated: 2023/09/27 20:45:15 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	int	i;
	int	temp;

	i = 0;
	temp = data->stack_a[0];
	while (i < data->stack_a_count - 1)
	{
		data->stack_a[i] = data->stack_a[i + 1];
		i++;
	}
	data->stack_a[i] = temp;
}

void	rb(t_data *data)
{
	int	i;
	int	temp;

	i = 0;
	temp = data->stack_b[0];
	while (i < data->stack_b_count - 1)
	{
		data->stack_b[i] = data->stack_b[i + 1];
		i++;
	}
	data->stack_b[i] = temp;
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
