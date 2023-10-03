/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:35:00 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/03 10:35:19 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_n(t_data *data, int n, void (*f)(t_data *))
{
	while (n--)
		f(data);
}

void	check_chunk(t_data *data, int start, int end, int j)
{
	int	middle;
	int	i;

	middle = (end - start) / 2;
	while (++j < data->stack_a_count)
	{
		i = start - 1;
		while (++i < end)
		{
			if (data->stack_a[j] == data->indexes[i])
			{
				if (data->stack_a_count - j > j)
					run_n(data, j, ra);
				else
					run_n(data, data->stack_a_count - j, rra);
				pb(data);
				if (i > middle + start)
					rb(data);
				j = -1;
				break ;
			}
		}
	}
}

void	push_b(t_data *data, int start, int end, int i)
{
	int	j;

	while (++i < data->chunk_num)
	{
		check_chunk(data, start, end, -1);
		j = start - 1;
		while (++j < end - 1 - (end - start) / 2)
			rrb(data);
		start += data->chunk_size;
		end += data->chunk_size;
		if (i + 2 == data->chunk_num)
			end += data->chunk_last_size;
	}
}
