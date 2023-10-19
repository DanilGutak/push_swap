/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:54:35 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/19 12:01:28 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	int	temp;

	if (data->stack_a_count < 1)
		return;
	temp = data->stack_a[1];
	data->stack_a[1] = data->stack_a[0];
	data->stack_a[0] = temp;
	if (data->flag == 0)
		action(data, "sa");
}

void	sb(t_data *data)
{
	int	temp;

	if (data->stack_b_count < 1)
		return;
	temp = data->stack_b[1];
	data->stack_b[1] = data->stack_b[0];
	data->stack_b[0] = temp;
	if (data->flag == 0)
		action(data, "sb");
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
