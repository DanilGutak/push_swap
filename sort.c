/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 07:39:22 by codespace         #+#    #+#             */
/*   Updated: 2023/10/02 21:41:46 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_bubble(t_data *data, int i, int j, int swapped)
{
	int	temp;

	while (swapped && ++i < data->stack_a_count)
	{
		swapped = 0;
		j = -1;
		while (++j < data->stack_a_count - i)
		{
			if (data->stack_a[j] > data->stack_a[j + 1])
			{
				temp = data->stack_a[j];
				data->stack_a[j] = data->stack_a[j + 1];
				data->stack_a[j + 1] = temp;
				temp = data->indexes[j];
				data->indexes[j] = data->indexes[j + 1];
				data->indexes[j + 1] = temp;
				swapped = 1;
			}
		}
	}
}

void	sort_for_index(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->stack_a_count)
		data->indexes[i] = i;
	sort_bubble(data, 0, 0, 1);
	i = -1;
	while (++i < data->stack_a_count)
		data->stack_a[i] = i;
	i = 1;
	while (i * i < data->stack_a_count)
		i++;
	i = i / 2;
	data->chunk_num = i;
	data->chunk_size = data->stack_a_count / data->chunk_num;
	data->chunk_last_size = data->stack_a_count - data->chunk_size
		* data->chunk_num;
}
