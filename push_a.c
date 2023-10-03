/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:33:14 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/03 10:34:20 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_insert(t_data *data)
{
	int	k;

	k = data->stack_b_count + data->end;
	while (--k)
	{
		if (data->stack_b[0] == data->indexes[k])
			return (1);
		if (data->stack_a[data->stack_a_count - 1] == data->indexes[k])
			return (0);
	}
	return (0);
}

void	run_b_a(t_data *data, int n, int flag, int *j)
{
	while (n--)
	{
		if (flag == 1)
		{
			if (data->end == 0 || check_for_insert(data))
			{
				pa(data);
				ra(data);
				data->end++;
			}
			else
				rb(data);
		}
		else
			rrb(data);
	}
	pa(data);
	*j = -1;
}

void	check_b_stack(t_data *data, int i)
{
	int	j;

	j = -1;
	while (++j < data->stack_b_count)
	{
		if (data->stack_b[j] == data->indexes[i])
		{
			if (data->stack_b_count - j >= j)
				run_b_a(data, j, 1, &j);
			else
				run_b_a(data, data->stack_b_count - j, 2, &j);
		}
	}
}

void	push_a(t_data *data, int i)
{
	data->end = 0;
	while (--i > -1)
	{
		if (data->stack_b[0] == data->indexes[i])
		{
			pa(data);
		}
		else
		{
			check_b_stack(data, i);
			if (data->stack_a[data->stack_a_count - 1] == data->indexes[i])
			{
				rra(data);
			}
		}
	}
}
