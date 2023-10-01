/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:42:34 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/01 16:16:43 by dgutak           ###   ########.fr       */
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
	printf("rra\n");
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
	printf("rrb\n");
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
