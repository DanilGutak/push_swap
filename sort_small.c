/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:20:12 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/03 14:37:32 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_data *data)
{
	if (data->stack_a[1] > data->stack_a[2]
		&& data->stack_a[2] > data->stack_a[0])
	{
		sa(data);
		ra(data);
	}
	else if (data->stack_a[2] > data->stack_a[0]
		&& data->stack_a[0] > data->stack_a[1])
		sa(data);
	else if (data->stack_a[1] > data->stack_a[0]
		&& data->stack_a[0] > data->stack_a[2])
		rra(data);
	else if (data->stack_a[0] > data->stack_a[2]
		&& data->stack_a[2] > data->stack_a[1])
		ra(data);
	else if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[1] > data->stack_a[2])
	{
		sa(data);
		rra(data);
	}
}

void	smallest(t_data *data)
{
	int	ret;
	int	i;
	int	j;

	i = 0;
	ret = data->stack_a[0];
	j = 0;
	while (++i < data->stack_a_count)
	{
		if (ret > data->stack_a[i])
		{
			ret = data->stack_a[i];
			j = i;
		}
	}
	if (data->stack_a_count - j >= j)
		run_n(data, j, ra);
	else
		run_n(data, data->stack_a_count - j, rra);
	pb(data);
}

void	sort_small(t_data *data)
{
	if (data->stack_a_count == 2)
		sa(data);
	else if (data->stack_a_count == 3)
		sort_3(data);
	else if (data->stack_a_count == 4)
	{
		smallest(data);
		sort_3(data);
		pa(data);
	}
	else
	{
		smallest(data);
		smallest(data);
		if (data->stack_b[0] < data->stack_b[1])
			sb(data);
		sort_3(data);
		pa(data);
		pa(data);
	}
	action(data, "end");
	error(data, 0);
}
